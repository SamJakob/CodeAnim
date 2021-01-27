#pragma once

#include <gtkmm.h>

namespace CodeAnim {

class Production {
  private:
    int width;
    int height;
    int fps;

  public:
    Production(int width, int height, int fps);

    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getHeight() const;
    [[nodiscard]] int getFPS() const;

    void show();
};

} // namespace CodeAnim
