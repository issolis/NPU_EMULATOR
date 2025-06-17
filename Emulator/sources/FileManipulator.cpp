#include "FileManipulator.h"
#include <fstream>
#include <iostream>

FileManipulator::FileManipulator() = default;

bool FileManipulator::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return false;
    }

    data.clear();
    std::string line;
    while (std::getline(file, line)) {
        data.push_back(line);
    }

    file.close();
    return true;
}

bool FileManipulator::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file for writing: " << filename << std::endl;
        return false;
    }

    for (const auto& line : data) {
        file << line << "\n";
    }

    file.close();
    return true;
}
