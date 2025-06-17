#include "../headers/NPU.h"
#include <iostream>
#include <iomanip>
#include <sstream>

NPU::NPU() {
    for (int i = 0; i < OUTPUT_SIZE/4; i++) {
        this->output_data[i] = 0;
    }

    memory = new Memory();

    this->processingData(); 
}

void NPU::processingData() {
    for (int i = 0; i < PROCESSING_SIZE; ++i) {
        output_data[i]     = memory->mem_0[i] * raw_0[0] +
                                 memory->mem_1[i] * raw_1[0] +
                                 memory->mem_2[i] * raw_2[0] +
                                 memory->mem_3[i] * raw_3[0];

        output_data[i + 8192] = memory->mem_0[i] * raw_0[1] +
                                 memory->mem_1[i] * raw_1[1] +
                                 memory->mem_2[i] * raw_2[1] +
                                 memory->mem_3[i] * raw_3[1];

        output_data[i + 16384] = memory->mem_0[i] * raw_0[2] +
                                 memory->mem_1[i] * raw_1[2] +
                                 memory->mem_2[i] * raw_2[2] +
                                 memory->mem_3[i] * raw_3[2];

        output_data[i + 24576] = memory->mem_0[i] * raw_0[3] +
                                 memory->mem_1[i] * raw_1[3] +
                                 memory->mem_2[i] * raw_2[3] +
                                 memory->mem_3[i] * raw_3[3];
    }
    std::cout << output_data[8192] << std::endl; 
    this->exportOutputToFile("Files/output_emulator.txt"); 
   
}

void NPU::exportOutputToFile(const std::string& filename) {
    FileManipulator exporter;
    exporter.data.clear();

    for (int i = 0; i < OUTPUT_SIZE; ++i) {
        std::stringstream ss;
        ss << std::uppercase << std::setfill('0') << std::setw(4) << std::hex << (output_data[i] & 0xFFFF);
        exporter.data.push_back(ss.str());
    }

    if (!exporter.saveToFile(filename)) {
        std::cerr << "Error writing output to " << filename << std::endl;
    } else {
        std::cout << "Output written successfully to " << filename << std::endl;
    }
}