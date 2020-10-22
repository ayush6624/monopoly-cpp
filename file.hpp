#ifndef FILE_hpp
#define FILE_hpp
#include <iostream>
#include <fstream>
#include "constants.hpp"
class File
{
private:
    std::string fileName;
    std::string operation;
    std::fstream fileWrite;
    std::fstream fileRead;
    std::fstream fileLog;

public:
    File(std::string s = "");
    ~File();
    std::string read();
    void write(std::string);
    void log(std::string, std::string);
};

#endif