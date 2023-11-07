// frontSnake.h

#ifndef _FRONTSNAKE_H
#define _FRONTSNAKE_H

    #include <snake.h>

    void drawMap();

    void drawSnake(tSnake snake);
    void drawApple(tApple apple);
    

    // Simula @iterations spawns de manzanas en snake.
    // Si @iterations = 0, simula infinitamente.
    // void drawAppleSimulation(unsigned int iterations);

    // printSnakeInfo():

    //  Imprime la informacion de la serpiente.
    //  Los bodies se cuentan de menor a mayor desde la cabeza hasta la cola.
    void printSnakeInfo(tSnake snake);

    void printAppleInfo(tApple apple);

    static unsigned int behindSnakesXY[4];
    void correctSnakeDraw(tSnake snake1, tSnake snake2);

#endif