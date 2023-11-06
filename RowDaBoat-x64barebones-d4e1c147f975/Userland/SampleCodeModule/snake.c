#include <userlib.h>
#include <snake.h>
#include <frontSnake.h>
#include <defs.h>

#define TICKS_UNTIL_PRINT 150000

void startSnake(int players){

    unsigned char key;

    tSnake mySnake;
    tApple myApple; 

	spawnSnake(mySnake);
	spawnApple(myApple, mySnake);
    
    drawMap();

    int ticks = TICKS_UNTIL_PRINT;

    while(1)    {

        if(ticks++ == TICKS_UNTIL_PRINT)   {
            
            ticks = 0;

            if(moveSnake(mySnake))  {

                clear();

                print("You are Dead\n");
                while(getChar()!='\n');

                print("Looser");
                while(getChar()!='\n');

                clear();
                return;

            }

            feedSnake(myApple, mySnake);
            if(mySnake->eating)
                spawnApple(myApple, mySnake);

            drawSnake(mySnake, myApple);

        }

        key = getChar();

        if(isSnakeKey(key))  {

            if(isUpper(key))
                key += 32;  // Lo paso a minusc.

            switch(key)   {
            
                case 'a' :  {
                    
                    changeSnakeDirection(mySnake, LEFT);    
                    break;
            }
                case 's' :  {
                    // Notar que la matriz que imprimer los pixeles crece para abajo.
                    changeSnakeDirection(mySnake, UP);
                    break;
            }        
                case 'w' :  {
                    
                    changeSnakeDirection(mySnake, DOWN);
                    break;
            }
                case 'd' :  {
                    
                    changeSnakeDirection(mySnake, RIGHT);   
                    break;
            }
                case 'p' :  {
                    
                    while(getChar()!='p');                    
                    break;
            }
                default :   
                    
                    break;
            }

        }

    }

}

void spawnSnake(tSnake babySnake)   {
    
    babySnake->headPos = 2;
    babySnake->eating = 0;


    for(int i=0; i<=babySnake->headPos; i++)  {
        babySnake->body[i].x = (COLUMNS / 2) - 1 + i;
        babySnake->body[i].y = (ROWS / 2);
        babySnake->body[i].direction = RIGHT;
    }
    
    babySnake->lastPos.x = babySnake->body[0].x-1;
    babySnake->lastPos.y = babySnake->body[0].y-1;
    babySnake->lastPos.direction = babySnake->body[0].direction;

}


void spawnApple(tApple apple, tSnake snake)   {
    int x; 
    int y; 
    int tryAgain = 1;

    int i;

    while(tryAgain) {

        x = randInt(1, ROWS-1);
        y = randInt(1, COLUMNS-1);

        i=0;

        do      {          
            tryAgain = snake->body[i].x == x && snake->body[i].y == y;
            ++i;
        }
        while(i<=snake->headPos && !tryAgain);
    } 

    apple->x = x;

    apple->y = y;

}

static int isOpositeDirection(tDirection dir1, tDirection dir2) {
    
    return  (dir1 == RIGHT && dir2 == LEFT) || (dir1 == LEFT && dir2 == RIGHT) ||
            (dir1 == UP && dir2 == DOWN) || (dir1 == DOWN && dir2 == UP);
            
}

void changeSnakeDirection(tSnake snake, tDirection newDirection)   {
    
// Si la direccion es opuesta a la direccion a la que va el cuerpo proximo a la cabeza, no deberia cambiar de direccion.
// Si es solo una cabeza se contempla que se pueda mover en cualquier direccion.

    if (snake->headPos==0 || 
        !isOpositeDirection(snake->body[snake->headPos-1].direction, newDirection)) 
     
           snake->body[snake->headPos].direction = newDirection;
    
   
}

static void refreshSnakeDirections(tSnake snake)    {
    for(int i=0; i<snake->headPos; ++i) 
        snake->body[i].direction = snake->body[i+1].direction;
}

static void moveBody(tSnake snake, unsigned int bodyPos) {
    
    switch(snake->body[bodyPos].direction)   {

        case RIGHT: {
            snake->body[bodyPos].x++;
            break;
        }
        case LEFT: {
            snake->body[bodyPos].x--;
            break;
        }
        case DOWN: {
            snake->body[bodyPos].y--;
            break;
        }
        case UP: {
            snake->body[bodyPos].y++;
            break;
        }
        
        default:    {
            print("Error in moveSnake function: Direction not defined\n");
            break;
        }
    }

}

static int checkCrash(tSnake snake)    {
    for(int i=0; i<snake->headPos; ++i) {
        if (snake->body[snake->headPos].x == snake->body[i].x &&
            snake->body[snake->headPos].y == snake->body[i].y)  {

                return 1;
            }
            
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

        struct snakeBody newBody;

        newBody.x = snake->body[snake->headPos].x; 
        newBody.y = snake->body[snake->headPos].y; 
        newBody.direction = snake->body[snake->headPos].direction;

        moveBody(snake, snake->headPos++);

        snake->body[snake->headPos] = snake->body[snake->headPos-1];

        snake->body[snake->headPos-1] = newBody;

        snake->eating = 0;
    }
     
    else    {
        
        snake->lastPos.x = snake->body[0].x;
        snake->lastPos.y = snake->body[0].y;
        snake->lastPos.direction = snake->body[0].direction;

        for(int i=0; i<=snake->headPos; ++i) 
            moveBody(snake, i);

        refreshSnakeDirections(snake);

    }    
    
    return checkCrash(snake);
}


void feedSnake(tApple apple, tSnake snake)   {

    if (snake->body[snake->headPos].x == apple->x && 
    snake->body[snake->headPos].y == apple->y)  {
        
        snake->eating = 1;
    }
        
}


int isSnakeKey(unsigned char key)    {
    return snakeKeys[key];
}
