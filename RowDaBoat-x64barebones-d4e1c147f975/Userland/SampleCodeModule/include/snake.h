#ifndef _SNAKE_H
#define _SNAKE_H

    #define ROWS 50
    #define COLUMNS 50
    #define SLOTS ROWS*COLUMNS

    typedef enum Direction { RIGHT, LEFT, DOWN, UP} tDirection;

    struct snakeBody {
        unsigned int xy [2];
        tDirection direction;
    };

    struct snake    {
        struct snakeBody body[SLOTS];
        unsigned int headPos;
        unsigned char eating;   // flag
    };

    typedef struct snake* tSnake;


    void spawnSnake(tSnake babySnake);

    void changeSnakeDirection(tDirection newDirection, tSnake snake);

    void refreshSnakeDirections(tSnake snake);

    int moveSnake(tSnake snake);

    int checkCrash(tSnake snake);

#endif