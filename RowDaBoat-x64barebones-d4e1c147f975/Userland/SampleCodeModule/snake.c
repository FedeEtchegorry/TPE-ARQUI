#include <userlib.h>
#include <snake.h>

void spawnSnake(tSnake babySnake)   {
    
    for(int i=0; i<3; i++)  {
        babySnake->body[i].x = (COLUMNS / 2) - 1 + i;
        babySnake->body[i].y = (ROWS / 2) - 1 + i;
        babySnake->body[i].direction = RIGHT;
    }
    
    babySnake->headPos = 2;
    babySnake->eating = 0;
}

void changeSnakeDirection(tSnake snake, tDirection newDirection)   {
    snake->body[snake->headPos].direction = newDirection;
}

void refreshSnakeDirections(tSnake snake)    {
    for(int i=0; i<snake->headPos; ++i) 
        snake->body[i].direction = snake->body[i+1].direction;
}

static void moveBody(tSnake snake, unsigned int bodyPos) {
    snake->body[bodyPos].x += snake->body[bodyPos].direction == RIGHT ? 1 : -1;
    snake->body[bodyPos].y += snake->body[bodyPos].direction == UP ? 1 : -1;
}

static int checkCrash(tSnake snake)    {
    for(int i=0; i<snake->headPos; ++i) {
        if (snake->body[snake->headPos].x == snake->body[i].x &&
            snake->body[snake->headPos].y == snake->body[i].y)
            return 1;
    }

// Checkear si toco una pared es simplement checkear si la cabeza toco la pared
// pues el cuerpo nunca debería poder hacerlo.
    
    return snake->body[snake->headPos].x == 0       || 
        snake->body[snake->headPos].x == COLUMNS    ||
        snake->body[snake->headPos].y == 0          ||
        snake->body[snake->headPos].y == ROWS;
}

int moveSnake(tSnake snake)    {
   
    if(snake->eating)  {

        snake->body[snake->headPos + 1].x = snake->body[snake->headPos].x; 
        snake->body[snake->headPos + 1].y = snake->body[snake->headPos].y; 
        snake->body[snake->headPos + 1].direction = snake->body[snake->headPos].direction;
        moveBody(snake, ++(snake->headPos));
    }
     
    else    {
        
        for(int i=0; i<=snake->headPos; ++i) 
            moveBody(snake, i);
    }    
    
    return checkCrash(snake);
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
        printUinteger(i+1);
        print(" info:");
        printSnakeBody(snake->body[i]);
        putEnter();
    }

}