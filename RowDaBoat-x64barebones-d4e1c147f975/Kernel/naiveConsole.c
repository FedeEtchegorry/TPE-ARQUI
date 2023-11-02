#include <naiveConsole.h>
#include <lib.h>
#include <colours.h>
#include <stdint.h>

static uint32_t uintToBase(uint64_t value, char * buffer, uint32_t base);
static void paintPixel( unsigned char forAndBackColor );

static char buffer[64] = { '0' };
static uint8_t * const video = (uint8_t*)0xB8000;
static uint8_t * currentVideo = (uint8_t*)0xB8000;
static const uint32_t width = 80;
static const uint32_t height = 25 ;

void ncPrint(const char * string){
	ncPrintColored(string, DEFAULT_COLOR);
}

void ncPrintChar(char character){
	*currentVideo = character;
	currentVideo += 2;
    if(currentVideo>=video+height * width * 2)
        scrollScreen(1);
}

void ncPrintColored( char * string, unsigned char forAndBackColor )
{
	for (int i = 0; string[i] != 0; i++)	{

		paintPixel(forAndBackColor);
		ncPrintChar(string[i]);
	}
		
}

void paintPixel( unsigned char forAndBackColor )
{
	*(currentVideo+1) = forAndBackColor;
}


void ncNewline(){
	do{
		paintPixel(DEFAULT_COLOR);
		ncPrintChar(' ');
	}
	while((uint64_t)(currentVideo - video) % (width * 2) != 0);
}
void ncBackspace(){
    if (currentVideo >= video+2) {
        currentVideo -= 2;
        *currentVideo = ' ';
    }
}

void setCurrentVideoLine(unsigned int lines){
    currentVideo-= (lines * width * 2);
    if (currentVideo<video){
        currentVideo = video;
    }
}
void WriteCharacterScroll(unsigned char c, unsigned char forAndBackColor, int x, int y){
    uint16_t * where;									// Esta variable combina el color de fondo y el color del carácter en un solo byte de 16 bits. Los primeros 4 bits (los más significativos) se utilizan para el color de fondo (backcolour), y los últimos 4 bits (los menos significativos) se utilizan para el color del carácter (forecolour). Estos 8 bits de atributo se almacenan en un solo valor de 16 bits.
    where = (uint16_t *)0xB8000 + (y * 80 + x) ;
    *where = c | (forAndBackColor << 8);								//Aquí, se escribe el carácter y su atributo en la ubicación de memoria calculada. c representa el carácter, y attrib << 8 coloca los atributos en los 8 bits más significativos del valor de 16 bits. Esta operación combina el carácter y los atributos en un solo valor que se almacena en la memoria de video
}
void scrollScreen(unsigned int linesToScroll) {
    unsigned int rowSize = 80 * 2;
    for (int i = 0; i < 25 - linesToScroll; i++) {
        void* from = (void*)(0xB8000 + (i + linesToScroll) * rowSize);  // fila actual + líneas a mover
        void* to = (void*)(0xB8000 + i * rowSize);  			// fila actual
        memcpy(to, from, rowSize);
    }
    setCurrentVideoLine(linesToScroll);
    // Llena con ' '
    for (int i = 25-linesToScroll; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            WriteCharacterScroll(' ', DEFAULT_COLOR, j, i);
        }
    }

}


void ncTab(){
    ncPrint("   ");
}

void ncPrintDec(uint64_t value){
	ncPrintBase(value, 10);
}

void ncPrintHex(uint64_t value){
	ncPrintBase(value, 16);
}

void ncPrintBin(uint64_t value){
	ncPrintBase(value, 2);
}

void ncPrintBase(uint64_t value, uint32_t base){
    uintToBase(value, buffer, base);
    ncPrint(buffer);
}

void ncClear(){
	int i;

	for (i = 0; i < height * width; i++){
		paintPixel(DEFAULT_COLOR);
		video[i * 2] = ' ';
	}
		
	currentVideo = video;
}

static uint32_t uintToBase(uint64_t value, char * buffer, uint32_t base){
	char *p = buffer;
	char *p1, *p2;
	uint32_t digits = 0;

	//Calculate characters for each digit
	do	{
		uint32_t remainder = value % base;
		*p++ = (remainder < 10) ? remainder + '0' : remainder + 'A' - 10;
		digits++;
	} while (value /= base);

	// Terminate string in buffer.
	*p = 0;

	//Reverse string in buffer.
	p1 = buffer;
	p2 = p - 1;
	while (p1 < p2)
	{
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2--;
	}

	return digits;
}
