#include <userlib.h>
#include <shell.h>
#include <snake.h>

int main() {


	tSnake mySnake;
	tApple myApple;

	spawnSnake(mySnake);
	spawnApple(myApple, mySnake);

	drawSnake(mySnake, myApple);


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