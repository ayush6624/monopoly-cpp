#ifndef FILE_hpp
#define FILE_hpp
#include <iostream>
#include <fstream>

class File
{
private:
    std::string filenmae;
    std::string operation;
    std::ofstream file;

public:
    File(std::string fileName);
    ~File();
void read();
    void write(std::string);
    // bool compare();
};

#endif