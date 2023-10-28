#include <userlib.h>
#include <shell.h>

int main() {


	print("¡ATENCION!: Estas en USERLAND");
	print("¡TEN CUIDADO! El programador estuvo 5 horas seguidas para que esta poronga ande (yupiii)   \n");
	print("Por eso no corrigio los bugs, pero descuida ¡Pronto lo hara!\n");

	char buffer[254];

// Anda medio para el orto pero creo que es porque el print
// es inificiente.
// Se me ocurre hacer un putChar() pero vamos a necesitar
// implementar un printChar en el videoDriver
	read(buffer);


	return 0;
}