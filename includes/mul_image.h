#pragma once
#include <string>

class MulImage {
public:
    void load(const std::string& filepath);
    void clear();
    int getWidth() const;
    int getHeight() const;
    int getComponents() const;
    const unsigned char* getData() const;
private:
    int width = 0; 
    int height = 0;
    int components = 0;
    unsigned char* data = nullptr; // TODO
};