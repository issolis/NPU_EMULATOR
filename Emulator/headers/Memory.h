#ifndef MEMORY_H
#define MEMORY_H
#define SIZE  8192

#include <iostream>
#include <cstdint>
#include "../headers/FileManipulator.h"


class Memory {
public:

    int16_t mem_0[SIZE];
    int16_t mem_1[SIZE];
    int16_t mem_2[SIZE];
    int16_t mem_3[SIZE];

    FileManipulator *fileManipulator; 

    Memory();
    void setMemories();
};

#endif 