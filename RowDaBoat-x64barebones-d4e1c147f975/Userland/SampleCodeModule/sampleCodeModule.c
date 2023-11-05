#include <userlib.h>
#include <shell.h>
#include <snake.h>
#include <frontSnake.h>

int main() {
    
    // tSnake snake;
    // tApple apple;
    // spawnSnake(snake);
    // spawnApple(apple, snake);
    // startSnake(1);
    // printSnakeSimulation();    

    initShell();
    char buffer[254] = {'\0'};
    do	{
        read(buffer);
        getMenu(buffer);
        // read(buffer);
        // getMenu(buffer);
    }	while(1);

	return 0;
}