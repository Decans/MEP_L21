#ifndef MIROS_H
#define MIROS_H

#include <stdint.h>


/// @brief OS Thread Object
typedef struct
{
    void* sp; // Stack Pointer
} OSThread_t; // OS thread object


/// @brief Thread task wrapper function
typedef void(*OSThreadHandler)(void);


/// @brief Initialize OS
/// @param  
void OS_init(void);


/// @brief Start an OS thread
/// @param me OS thread specific object
/// @param threadHandler Function wrapped around thread tasks
/// @param stkSto Pointer to thread stack
/// @param stkSize Stack size
void OSThread_start(
    OSThread_t *me,
    OSThreadHandler threadHandler,
    void *stkSto,
    uint32_t stkSize
);

#endif // MIROS_H