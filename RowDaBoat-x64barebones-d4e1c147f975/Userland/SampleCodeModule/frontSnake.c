// frontSnake.c
#include <frontSnake.h>
#include <snake.h>
#include <userlib.h>

void drawMap()  {
    clear();
    for(int i=0; i<=COLUMNS; ++i)    {
        draw(0x04, i, 0);
        draw(0x04, i, ROWS);
    }
    for(int i=0; i<=ROWS; ++i)    {
        draw(0x04, 0, i);
        draw(0x04, COLUMNS, i);
    }
}


void drawSnake(tSnake snake, tApple apple)  {
    
// Borramos la posicion anterior del ultimo cuerpito, si es que no coincide con la cabeza.
    if(snake->lastPos.x != snake->body[snake->headPos].x ||
        snake->lastPos.y != snake->body[snake->headPos].y)   {
            
            draw(0xA0, snake->lastPos.x, snake->lastPos.y);
        }      
        
    
    for(int i=0; i<snake->headPos; i++)    
        draw(0x04, snake->body[i].x, snake->body[i].y);
    
    int headModel;
    switch(snake->body[snake->headPos].direction)    {
        
        case LEFT :    {
            headModel = 0;
            break;
        }
        case RIGHT :    {
            headModel = 1;
            break;
        }
        case UP :    {
            headModel = 3;
            break;
        }
        case DOWN :    {
            headModel = 2;
            break;
        }
    }
    draw(headModel, snake->body[snake->headPos].x, snake->body[snake->headPos].y);
    draw(0x05, apple->x, apple->y);
    
}

void drawAppleSimulation(unsigned int iterations)  {

    tSnake mySnake;
    tApple myApple; 

	spawnSnake(mySnake);

	spawnApple(myApple, mySnake);

    drawMap();
    
    if(iterations==0)   {
        while(1)    {
            spawnApple(myApple, mySnake);
            drawSnake(mySnake, myApple);
        }
        return;
    }
    else
        for(int i=0; i<iterations; ++i)    {
            spawnApple(myApple, mySnake);
            drawSnake(mySnake, myApple);
        }
}


static void printDirection(tDirection direction) {

    switch(direction) {
        
        case RIGHT: {
            print("RIGHT");
            break;
        }
        case LEFT: {
            print("LEFT");
            break;
        }
        case DOWN: {
            print("DOWN");
            break;
        }
        case UP: {
            print("UP");
            break;
        }
        
        default:    {
            print("Direction not defined");
            break;
        }
    }
}



static void printSnakeBody(struct snakeBody body)    {

    putEnter();

    print("x: ");   printUinteger(body.x);
    putEnter();
    print("y: ");   printUinteger(body.y);
    putEnter();
    print("Direction: ");   printDirection(body.direction);

    putEnter();
}


void printSnakeInfo(tSnake snake)   {

    
    print("Snake length: ");   printUinteger(snake->headPos+1);
    putEnter();
    print("Snake is");
    snake->eating ? print(" ") : print(" not ");
    print("eating");  
    putnEnters(2);

    print("Head info: ");
    printSnakeBody(snake->body[snake->headPos]);


    for(int i=snake->headPos-1; i>=0; --i)    {
        
        putEnter();
        print("Body ");
        printUinteger(snake->headPos - i);
        print(" info:");
        printSnakeBody(snake->body[i]);
        putEnter();
    }

}



void printAppleInfo(tApple apple)    {

    print("Apple: ");

    putEnter();

    print("x: ");   printUinteger(apple->x);
    putEnter();
    print("y: ");   printUinteger(apple->y);

    putEnter();


}