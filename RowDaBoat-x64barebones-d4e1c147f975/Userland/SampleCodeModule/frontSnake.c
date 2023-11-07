// frontSnake.c
#include <frontSnake.h>
#include <snake.h>
#include <userlib.h>

void drawMap()  {
    clear();
    for(int i=0; i<=COLUMNS; ++i)    {
        drawWhiteSquare(i, 0);
        drawWhiteSquare(i, ROWS);
    }
    for(int i=0; i<=ROWS; ++i)    {
        drawWhiteSquare(0, i);
        drawWhiteSquare(COLUMNS, i);
    }
}


void drawSnake(tSnake snake)  {
    if(snake->id == 1){
        for(int i=0; i<snake->headPos; i++)    
            drawGreenSquare(snake->body[i].x, snake->body[i].y);
}
    else    {
        for(int i=0; i<snake->headPos; i++)    
            drawYellowSquare(snake->body[i].x, snake->body[i].y);
    }

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
    if(snake->id == 1)
        
        draw(headModel, snake->body[snake->headPos].x, snake->body[snake->headPos].y, 0x01);

    if(snake->id == 2)
        
        draw(headModel, snake->body[snake->headPos].x, snake->body[snake->headPos].y, 0x02);

}

void correctSnakeDraw(tSnake snake1, tSnake snake2)  {
    
    int todraw = 1;

    // Borramos la posicion anterior del ultimo cuerpito, si es que no coincide con la cabeza.
        if(behindSnakesXY[0] != snake1->body[snake1->headPos].x ||
            behindSnakesXY[1] != snake1->body[snake1->headPos].y)   { 

                if(getPlayers()==2) {
                    for(int i=0; i<=snake2->headPos && todraw; ++i)   {
                        todraw =  (behindSnakesXY[0] != snake2->body[i].x || behindSnakesXY[1] != snake2->body[i].y);
                    }
                }
                if(todraw)
                    drawBLackSquare(behindSnakesXY[0], behindSnakesXY[1]);
            }      
        
        if(getPlayers()==2 && (behindSnakesXY[2] != snake2->body[snake2->headPos].x ||
            behindSnakesXY[3] != snake2->body[snake2->headPos].y))   { 
                
                todraw = 1;

                for(int i=0; i<=snake1->headPos && todraw; ++i)   {
                    todraw =  (behindSnakesXY[2] != snake1->body[i].x || behindSnakesXY[3] != snake1->body[i].y);
                }
                
                if(todraw)
                    drawBLackSquare(behindSnakesXY[2], behindSnakesXY[3]);
            } 
    }

void drawApple(tApple apple)    {
    draw(0x05, apple->x, apple->y, 0x00);
}

// TO DO: Borrar, no lo borro de una por se un sueño frustrado :(
// void drawAppleSimulation(unsigned int iterations)  {

//     tSnake mySnake;
//     tApple myApple; 

// 	spawnSnake(mySnake);

// 	spawnApple(myApple, mySnake);

//     drawMap();
    
//     if(iterations==0)   {
//         while(1)    {
//             spawnApple(myApple, mySnake);
//             drawSnake(mySnake, myApple);
//         }
//         return;
//     }
//     else
//         for(int i=0; i<iterations; ++i)    {
//             spawnApple(myApple, mySnake);
//             drawSnake(mySnake, myApple);
//         }
// }


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

    print("Snake"); printUinteger(snake->id);   putEnter();
    print("Snake length: ");   printUinteger(snake->headPos+1);
    putEnter();
    print("Snake is");
    snake->eating ? print(" ") : print(" not ");
    print("eating");  
    putnEnters(2);

    print("Head info: ");
    printSnakeBody(snake->body[snake->headPos]);


    // for(int i=snake->headPos-1; i>=0; --i)    {
        
    //     putEnter();
    //     print("Body ");
    //     printUinteger(snake->headPos - i);
    //     print(" info:");
    //     printSnakeBody(snake->body[i]);
    //     putEnter();
    // }

}

void printSnakeInfo2(tSnake snake, tApple apple) {

    deleteSnakeInfo();
    
    // print("id:");
    // printUinteger(snake->id);       putChar(' ');
    print("l:");
    printUinteger(snake->headPos+1);putChar(' ');
    print("e?");
    printUinteger(snake->eating);   putChar(' ');
    print("x:");
    printUinteger(snake->body[snake->headPos].x);   putChar(' ');
    print("y:");
    printUinteger(snake->body[snake->headPos].y);   putChar(' ');
    print("ax:");
    printUinteger(apple->x);
    print("ay:");
    printUinteger(apple->y);   

}

void deleteSnakeInfo()  {
    for(int i=0; i<40; ++i) {
        putBackSpace();
    }
}

void printSnakeScore(tSnake snake)  {
    for(int i=0; i<SLOTS/2; i++)
        putBackSpace();

    print("Snake ");  printUinteger(snake->id);
    print(": ");    printUinteger(snake->headPos - 2);

}

void printAppleInfo(tApple apple)    {

    print("Apple: ");

    putEnter();

    print("x: ");   printUinteger(apple->x);
    putEnter();
    print("y: ");   printUinteger(apple->y);

    putEnter();


}