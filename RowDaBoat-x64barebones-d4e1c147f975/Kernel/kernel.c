#include <stdint.h>
#include <string.h>
#include <lib.h>
#include <moduleLoader.h>
#include <naiveConsole.h>
#include <idtLoader.h>
#include <videoDriver.h>
#include <stringPrinter.h>
#include <buffer.h>	// Solo para testear

extern uint8_t text;
extern uint8_t rodata;
extern uint8_t data;
extern uint8_t bss;
extern uint8_t endOfKernelBinary;
extern uint8_t endOfKernel;

static const uint64_t PageSize = 0x1000;

static void * const sampleCodeModuleAddress = (void*)0x400000;
static void * const sampleDataModuleAddress = (void*)0x500000;

typedef int (*EntryPoint)();


void clearBSS(void * bssAddress, uint64_t bssSize)
{
	memset(bssAddress, 0, bssSize);
}

void * getStackBase()
{
	return (void*)(
		(uint64_t)&endOfKernel
		+ PageSize * 8				//The size of the stack itself, 32KiB
		- sizeof(uint64_t)			//Begin at the top of the stack
	);
}

void * initializeKernelBinary()
{
	char buffer[10];

	ncPrint("[x64BareBones]");
	ncNewline();

	ncPrint("CPU Vendor:");
	ncPrint(cpuVendor(buffer));
	ncNewline();

	ncPrint("[Loading modules]");
	ncNewline();
	void * moduleAddresses[] = {
		sampleCodeModuleAddress,
		sampleDataModuleAddress
	};

	loadModules(&endOfKernelBinary, moduleAddresses);
	ncPrint("[Done]");
	ncNewline();
	ncNewline();

	ncPrint("[Initializing kernel's binary]");
	ncNewline();

	clearBSS(&bss, &endOfKernel - &bss);

	ncPrint("  text: 0x");
	ncPrintHex((uint64_t)&text);
	ncNewline();
	ncPrint("  rodata: 0x");
	ncPrintHex((uint64_t)&rodata);
	ncNewline();
	ncPrint("  data: 0x");
	ncPrintHex((uint64_t)&data);
	ncNewline();
	ncPrint("  bss: 0x");
	ncPrintHex((uint64_t)&bss);
	ncNewline();

	ncPrint("[Done]");
	ncNewline();
	ncNewline();
	return getStackBase();
}

int main(){

	load_idt();

	char * str1 = "Now I am become Death, the destroyer of worlds.";

	int i=0;
	while(str1[i]!='\0' && putChar(str1[i]))
		++i;
	
	char str2[i+1];
	readBuffer(str2, i+1);
	printTextDefault(str2, RED, BLACK);
	printNewline();
    printTextDefault(str2, RED, WHITE);
    printTextDefault(str2, RED, YELLOW);

	char * str3 = "Error 404, please introduce your credit card security code";

	int aux = putString(str3);
	char str4[aux+1];
	readBuffer(str4, aux+1);
	printTextDefault(str4, MAGENTA, BLACK);
    char * str5="My name is Maximus Decimus Meridius, commander of the Armies of the North, General of the Felix Legions, loyal servant to the true emperor, Marcus Aurelius. Father to a murdered son, husband to a murdered wife. And I will have my vengeance, in this life or the next.";
    printNewline();
    printTextDefault(str5, BLACK, WHITE);
char str [BUFFER_SIZE] = {'\0'};
scroll(1);
// Para escribir el teclado
	while (1)	{
        blink();
		str[0] = readChar();
		printTextDefault(str, GREEN, BLACK);

	}

	return 0;
}
