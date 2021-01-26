#include "Production.hpp"

namespace CodeAnim {

Production::Production(int width, int height) {
    this->width = width;
    this->height = height;
};

int Production::getWidth() { return this->width; }
int Production::getHeight() { return this->height; }

} // namespace CodeAnim
