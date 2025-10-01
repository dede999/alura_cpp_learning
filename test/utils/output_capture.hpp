#ifndef OUTPUT_CAPTURE_HPP
#define OUTPUT_CAPTURE_HPP

#include <iostream>
#include <sstream>

// Classe helper para capturar output do std::cout
class OutputCapture {
    std::stringstream buffer;
    std::streambuf* old_cout;
    
public:
    OutputCapture();
    ~OutputCapture();
    
    std::string getOutput();
    void clear();
};

#endif