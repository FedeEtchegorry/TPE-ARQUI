#include <snake.h>

void spawnSnake(tSnake babySnake)   {
    
    for(int i=0; i<3; i++)  {
        babySnake->body[i].xy[0] = (SLOTS / 2) - 1 + i;
        babySnake->body[i].xy[1] = (SLOTS / 2) - 1 + i;
        babySnake->body[i].direction = RIGHT;
    }
    
    babySnake->headPos = 2;
    babySnake->eating = 0;
}

void changeSnakeDirection(tDirection newDirection, tSnake snake)   {
    snake->body[snake->headPos].direction = newDirection;
}

void refreshSnakeDirections(tSnake snake)    {
    for(int i=0; i<snake->headPos; ++i) 
        snake->body[i].direction = snake->body[i+1].direction;
}

int moveSnake(tSnake snake)    {
   
    if(snake->eating)  {

        snake->body[snake->headPos + 1].xy = snake->body[snake->headPos].xy; 
        snake->body[snake->headPos + 1].direction = snake->body[snake->headPos].direction;
        moveBody(snake, ++(snake->headPos));
    }
     
    else    {
        
        for(int i=0; i<=snake->headPos; ++i) 
            moveBody(snake, i);
    }    
    
    return checkCrash(snake);
}

static void moveBody(tSnake snake, unsigned int bodyPos) {
    snake->body[bodyPos].xy[0] += snake->body[bodyPos].direction == RIGHT ? 1 : -1;
    snake->body[bodyPos].xy[1] += snake->body[bodyPos].direction == UP ? 1 : -1;
}

int checkCrash(tSnake snake)    {
    for(int i=0; i<snake->headPos; ++i) {
        if(snake->body[snake->headPos].xy == snake->body[i].xy)
            return 1;
    }
    return 0;
}