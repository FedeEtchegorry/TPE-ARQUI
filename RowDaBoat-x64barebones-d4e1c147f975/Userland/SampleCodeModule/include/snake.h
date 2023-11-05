#ifndef _SNAKE_H
#define _SNAKE_H

    #include <randlib.h>

    #define ROWS 50
    #define COLUMNS 50
    #define SLOTS ROWS*COLUMNS

    typedef enum Direction { RIGHT, LEFT, DOWN, UP} tDirection;

    struct snakeBody {

        unsigned int x;
        unsigned int y;
        tDirection direction;
    };

    struct snake    {

        struct snakeBody body[SLOTS];
        unsigned int headPos;
        unsigned char eating;   // flag
    };

    typedef struct snake* tSnake;

        struct apple    {

        unsigned int x;
        unsigned int y;
    };

    typedef struct apple * tApple;

// TO DO: empieza el juego snake(dibuja el mapa y spawnea la serpiente), falta implementar las funciones
//      para dibujar los cuadraditos.
    void drawSnake(tSnake snake, tApple apple);

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
//  Instantaneamente despues debe llamarse a refreshSnakeDirections().

//  Retorna 1 si hubo una colision entre la cabeza y algun cuerpo o muro.

// TO DO: Si bien se tuvo en cuenta que este comiendo, no se implemento
//  el encuentro con comida. Pendiente para cuando se implemente la comida.

    int moveSnake(tSnake snake);

// refreshSnakeDirections():

//  Actualiza la posicion de cada cuerpo de la serpiente con el del siguiente.
//  Luego de llamar a moveSnake() se debe llamar a refreshSnakeDirections().

    void refreshSnakeDirections(tSnake snake);

// printSnakeInfo():

//  Imprime la informacion de la serpiente.
//  Los bodies se cuentan de menor a mayor desde la cabeza hasta la cola.
    void printSnakeInfo(tSnake snake);

    void spawnApple(tApple apple, tSnake snake);

    void feedSnake(tApple apple, tSnake snake);

    void printAppleInfo(tApple apple);

#endif