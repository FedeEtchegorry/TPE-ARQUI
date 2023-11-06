#ifndef _SNAKE_H
#define _SNAKE_H

    #include <randlib.h>

    #define ROWS 28
    #define COLUMNS 28
    #define SLOTS ROWS*COLUMNS

    typedef enum Direction { RIGHT, LEFT, DOWN, UP} tDirection;

    struct snakeBody {

        unsigned int x;
        unsigned int y;
        tDirection direction;
    };

    typedef struct  {

        struct snakeBody body[SLOTS];
        unsigned int headPos;
        struct snakeBody lastPos;       // Posicion de la cola antes de mover. Necesario para dibujar la serpiente.
        unsigned char eating;           // flag.
    } * tSnake;

    typedef struct  {

        unsigned int x;
        unsigned int y;
    } * tApple;


// Parcialmente imprime info de la snake y se puede jugar un poquito (TO DO).
    void startSnake(int players);

//  Instancia snake.
    void spawnSnake(tSnake babySnake);

    void changeSnakeDirection(tSnake snake, tDirection newDirection);

// moveSnake():

//  Aumenta una posicion en la direccion que se esta moviendo
//  cada uno de los cuerpos.

//  Debe llamarse en cada segundo del juego independientemente de que 
//  se haya llamaod a changeSnakeDirection().

//  Retorna 1 si hubo una colision entre la cabeza y algun cuerpo o muro.

    int moveSnake(tSnake snake);

    void spawnApple(tApple apple, tSnake snake);

    void feedSnake(tApple apple, tSnake snake);


#endif