#include <userlib.h>
#include <shell.h>
#include <snake.h>

int main() {


 	initShell();

 	char buffer[254] = {'\0'};

 	do	{
 	read(buffer);
     getMenu(buffer);
 }	while(1);


 	exit();

//	tSnake mySnake;
//	spawnSnake(mySnake);
//	printSnakeInfo(mySnake);
//
//	changeSnakeDirection(mySnake, UP);
//	print("Change dir to UP"); putnEnters(2);
//	printSnakeInfo(mySnake);
//
//	print("Move");putnEnters(2);
//	moveSnake(mySnake);
//	printSnakeInfo(mySnake);

	return 0;
}