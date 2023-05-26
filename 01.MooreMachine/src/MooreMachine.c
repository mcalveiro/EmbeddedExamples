/*
 ============================================================================
 Name        : MooreMachine.c
 Author      : Miguel A. Calveiro
 Version     :
 Copyright   : UTN - Licenciatura en Automatización y Control
 Description : Moore-Machine in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdint.h>

/* Definición de los estados de la máquina */
typedef enum
{
    STATE_A,
    STATE_B,
    STATE_C
} State;

/* Función para obtener la salida en función del estado actual */
static int32_t getOutput(State state)
{
    switch (state)
    {
        case STATE_A:
            return 0; /* Salida correspondiente al estado A */
        case STATE_B:
            return 1; /* Salida correspondiente al estado B */
        case STATE_C:
            return 0; /* Salida correspondiente al estado C */
        default:
            return -1; /* Estado no válido */
    }
}

/* Función para obtener el nombre del estado */
static const char* getStateName(State state)
{
    switch (state)
    {
        case STATE_A:
            return "STATE_A";
        case STATE_B:
            return "STATE_B";
        case STATE_C:
            return "STATE_C";
        default:
            return "Estado inválido";
    }
}

/* Función para imprimir el estado actual y la salida correspondiente */
static void printState(State state)
{
    int32_t output = getOutput(state);
    const char* stateName = getStateName(state);
    printf("Estado actual: %s, Salida: %d\n", stateName, (int)output);
}

/* Función para realizar la transición de estado */
static State transitionState(State currentState)
{
    switch (currentState)
    {
        case STATE_A:
            return STATE_B; /* Transición al estado B */
        case STATE_B:
            return STATE_C; /* Transición al estado C */
        case STATE_C:
            return STATE_A; /* Transición al estado A */
        default:
            return STATE_A; /* Manejo de estado no válido */
    }
}

/* Función principal */
int main(void)
{
    State currentState = STATE_A; /* Estado inicial */

    /* Simulación de la máquina de Moore */
    for (uint32_t i = 0U; i < 5U; i++)
    {
        printState(currentState); /* Imprimir estado actual y salida correspondiente */

        currentState = transitionState(currentState); /* Transición de estado */
    }

    return 0;
}

