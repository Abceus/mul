#include "mul_image.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void MulImage::load(const std::string& filepath) {
    if(data) {
        clear();
    }
    data = stbi_load(filepath.c_str(), &width, &height, &components, 0);
}

void MulImage::clear() {
    stbi_image_free(data);
    data = nullptr;
    width = 0;
    height = 0;
    components = 0;
}

int MulImage::getWidth() const {
    return width;
}

int MulImage::getHeight() const {
    return height;
}

int MulImage::getComponents() const {
    return components;
}

const unsigned char* MulImage::getData() const {
    return data;
}