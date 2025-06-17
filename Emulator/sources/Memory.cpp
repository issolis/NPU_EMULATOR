#include "../headers/Memory.h"
#include <iomanip> 



Memory::Memory() {

    for (int i = 0; i < SIZE; i++) {
        this->mem_0[i] = 0; 
        this->mem_1[i] = 0;
        this->mem_2[i] = 0; 
        this->mem_3[i] = 0; 
    }

    this->fileManipulator = new FileManipulator(); 

    this->setMemories(); 

}

void Memory::setMemories() {
    this->fileManipulator->loadFromFile("Files/mem_0.txt");
    std::vector<std::string> temp_mem_0 = this->fileManipulator->data;

    this->fileManipulator->loadFromFile("Files/mem_1.txt");
    std::vector<std::string> temp_mem_1 = this->fileManipulator->data;
    
    this->fileManipulator->loadFromFile("Files/mem_2.txt");
    std::vector<std::string> temp_mem_2 = this->fileManipulator->data;

    this->fileManipulator->loadFromFile("Files/mem_3.txt");
    std::vector<std::string> temp_mem_3 = this->fileManipulator->data;

    for (int i = 0; i < SIZE; i++){
        this->mem_0[i] = static_cast<int16_t>(std::stoul(temp_mem_0[i], nullptr, 16));
        this->mem_1[i] = static_cast<int16_t>(std::stoul(temp_mem_1[i], nullptr, 16));
        this->mem_2[i] = static_cast<int16_t>(std::stoul(temp_mem_2[i], nullptr, 16));
        this->mem_3[i] = static_cast<int16_t>(std::stoul(temp_mem_3[i], nullptr, 16));
    }

    std::cout << "mem_0[1]: 0x" << std::hex << std::setw(4) << std::setfill('0') 
              << (static_cast<uint16_t>(this->mem_0[1])) << std::endl;
    std::cout << "mem_1[1]: 0x" << std::hex << std::setw(4) << std::setfill('0') 
              << (static_cast<uint16_t>(this->mem_1[1])) << std::endl;
    std::cout << "mem_2[1]: 0x" << std::hex << std::setw(4) << std::setfill('0') 
              << (static_cast<uint16_t>(this->mem_2[1])) << std::endl;
    std::cout << "mem_3[1]: 0x" << std::hex << std::setw(4) << std::setfill('0') 
              << (static_cast<uint16_t>(this->mem_3[1])) << std::endl;
}

