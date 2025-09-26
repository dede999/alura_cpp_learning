#include "output_capture.hpp"

OutputCapture::OutputCapture() {
    old_cout = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());
}

OutputCapture::~OutputCapture() {
    std::cout.rdbuf(old_cout);
}

std::string OutputCapture::getOutput() {
    return buffer.str();
}

void OutputCapture::clear() {
    buffer.str("");
    buffer.clear();
}
