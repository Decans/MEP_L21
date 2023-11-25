#ifndef MIROS_H
#define MIROS_H

#include <stdint.h>

typedef struct
{
    void* sp; // Stack Pointer
} OSThread_t;

typedef void(*OSThreadHandler)(void);

void OS_init(void);

void OSThread_start(
    OSThread_t *me,
    OSThreadHandler threadHandler,
    void *stkSto,
    uint32_t stkSize
);

#endif // MIROS_H