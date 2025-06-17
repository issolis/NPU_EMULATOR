#ifndef NPU_H
#define NPU_H
#define OUTPUT_SIZE 32768
#define PROCESSING_SIZE 8192

#include <iostream>
#include "../headers/Memory.h"

class NPU
{

public:
    int16_t output_data[OUTPUT_SIZE]; 
    Memory *memory;

    int16_t raw_0[4] = {1,  2,  3,  4};
    int16_t raw_1[4] = {1,  2,  3,  4};
    int16_t raw_2[4] = {1,  2,  3,  4};
    int16_t raw_3[4] = {1,  2,  3,  4};
    
    NPU();

    void processingData(); 
    void exportOutputToFile(const std::string& filename); 
  
};




#endif