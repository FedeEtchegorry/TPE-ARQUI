#include <userlib.h>
#include <shell.h>

int main() {


	initShell();

	char buffer[254] = {'\0'};


	read(buffer);
    print(buffer);



	//exit();

	return 0;
}