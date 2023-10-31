#include <userlib.h>
#include <shell.h>

int main() {


	initShell();

	char buffer[254] = {'\0'};

	do	{
	read(buffer);
    time();
    print(buffer);
}	while(!strEquals(buffer, "exit"));


	exit();

	return 0;
}