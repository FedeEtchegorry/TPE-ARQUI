// frontSnake.c
#include <frontSnake.h>
#include <snake.h>
#include <userlib.h>

void drawMap()  {
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
    
    
    draw(0xA0, snake->body[0].x, snake->body[0].y);
    
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

void drawAppleSpawning(tApple apple, tSnake snake, unsigned int iterations)  {

    drawMap();
    
    if(iterations==0)   {
        while(1)    {
            drawSnake(snake, apple);
            spawnApple(apple, snake);
        }
    }
    else
        for(int i=0; i<iterations; ++i)    {
            drawSnake(snake, apple);
            spawnApple(apple, snake);
        }
}

void printSnakeSimulation(void){

    tSnake mySnake;
    tApple myApple; // Funciona bien con variables locales

	spawnSnake(mySnake);

	spawnApple(myApple, mySnake);
    
    drawMap();

    int ticks = 19000;

    while(1)    {

        if(ticks == 19000)   {
            
            ticks = 0;

            if(moveSnake(mySnake))  {

                clear();
                killBuffer();
                return;

            }

            feedSnake(myApple, mySnake);
            if(mySnake->eating)
                spawnApple(myApple, mySnake);

            printSnakeInfo(mySnake);
            printAppleInfo(myApple);
            refreshSnakeDirections(mySnake);
        }

        ticks++;

        switch(getChar())   {
        
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

        refreshSnakeDirections(mySnake);

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