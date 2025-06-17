#ifndef FILEMANIPULATOR_H
#define FILEMANIPULATOR_H

#include <string>
#include <vector>

class FileManipulator {
public:
    std::vector<std::string> data;

    FileManipulator();

    bool loadFromFile(const std::string& filename);
    bool saveToFile(const std::string& filename);
};

#endif 
