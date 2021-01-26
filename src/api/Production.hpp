#pragma once

#include <gtkmm.h>

namespace CodeAnim {

class Production {
  private:
    int width;
    int height;

  public:
    Production(int, int);

    int getWidth();
    int getHeight();

    void show();
};

} // namespace CodeAnim
