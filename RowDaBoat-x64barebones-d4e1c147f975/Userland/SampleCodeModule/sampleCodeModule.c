#include <userlib.h>
#include <shell.h>

int main() {


	initShell();

	char buffer[254] = {'\0'};

	do	{
	read(buffer);
}	while(strEquals(buffer, "exit\n") == 0);

	print("Out\n");

	return 0;
}