#include <userlib.h>
#include <snake.h>
#include <frontSnake.h>
#include <defs.h>

#define TICKS_UNTIL_PRINT 900000

void startSnake(unsigned int players){

    setPlayers(players);

    if(incorrectplayers()){
        print("Error en la cantidad de jugadores\n");
        return;
    }

    snakesConfig();

    spawnSnake(snake1);
    snake1->id = 1;
    if(getPlayers()==2) {
        spawnSnake(snake2);
        snake2->id = 2;
    }

	spawnApple(myApple, snake1, snake2);

    drawMap();

    unsigned char key;
    int ticks = TICKS_UNTIL_PRINT;

    while(1)    {

        if(ticks++ == TICKS_UNTIL_PRINT)   {
            
            ticks = 0;        

            if(creep(snake1, myApple))
                return;

        // Necesario para borrar la cola de la snake al mover.
            correctSnakeDraw(snake1, snake2);

            if(snake1->eating)   {

                spawnApple(myApple, snake1, snake2);
                drawApple(myApple);
            }
    
            if(getPlayers()==2) {

                if(creep(snake2, myApple))
                    return;
                
                if(snake2->eating)   {

                    spawnApple(myApple, snake1, snake2);
                    drawApple(myApple);
                }
            }


        }

        key = getChar();

        if(isSnakeKey(key))  {

            if(isUpper(key))    {
                key += 32;  // Lo paso a minusc.
        }
            if( key == 'p')     {
                
                while(getChar()!='p');
        }    
            else if(!useKey(snake1, key, keysSnake1) && getPlayers()==2)    {

                useKey(snake2, key, keysSnake2);
        }            
        
        }

    }

}

int creep(tSnake mySnake, tApple myApple)   {

    if(moveSnake(mySnake))  {

        clear();

        print("You are Dead\n");
        while(getChar()!='\n');

        print("Looser");
        while(getChar()!='\n');

        clear();
        return 1;

    }

    feedSnake(myApple, mySnake);

    drawSnake(mySnake);
    return 0;
}

int useKey(tSnake mySnake, unsigned char key, unsigned char * snakeKeys) {
    
    if (key == snakeKeys[0])    {

        changeSnakeDirection(mySnake, LEFT);
        return 1;
} 
    else if (key == snakeKeys[1])   {
        // Notar que la matriz que imprimer los pixeles crece para abajo.
        changeSnakeDirection(mySnake, UP);
        return 1;
} 
    else if (key == snakeKeys[2])   {
    
        changeSnakeDirection(mySnake, DOWN);
        return 1;
} 
    else if (key == snakeKeys[3])   {

        changeSnakeDirection(mySnake, RIGHT);
        return 1;
} 
    
// No es ninguna de las anteriores.
    return 0;
    
}

void spawnSnake(tSnake babySnake)   {
    
    babySnake->headPos = 2;
    babySnake->eating = 0;

    for(int i=0; i<=babySnake->headPos; i++)  {
        babySnake->body[i].x = (COLUMNS / 2) - 1 + i;
    // Consideracion para que no spawneen las snakes en la misma posicion.
        babySnake->body[i].y = (ROWS / 2) - babySnake->id - 1;
        babySnake->body[i].direction = RIGHT;
        
    }    


}


void spawnApple(tApple apple, tSnake snake1, tSnake snake2)   {
    int x; 
    int y; 
    int tryAgain = 1;

    int i;

    while(tryAgain) {

        x = randInt(1, ROWS-1);
        y = randInt(1, COLUMNS-1);

            i=0;

            do      {          
                tryAgain = snake1->body[i].x == x && snake1->body[i].y == y;
                ++i;
            }
            while(i<=snake1->headPos && !tryAgain);
        
            while(i<=snake2->headPos && !tryAgain)      {          
                tryAgain = snake2->body[i].x == x && snake2->body[i].y == y;
                ++i;
            }
            

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

        int auxX = snake->body[snake->headPos].x; 
        int auxY = snake->body[snake->headPos].y; 
        tDirection auxDirection = snake->body[snake->headPos].direction;

        moveBody(snake, snake->headPos++);

        snake->body[snake->headPos] = snake->body[snake->headPos-1];

        snake->body[snake->headPos-1].x = auxX;
        snake->body[snake->headPos-1].y = auxY;
        snake->body[snake->headPos-1].direction = auxDirection;

        snake->eating = 0;
    }
     
    else    {
        
        behindSnakesXY[snake->id==1? 0 : 2] = snake->body[0].x;
        behindSnakesXY[snake->id==1? 1 : 3] = snake->body[0].y;

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
