#pragma once

namespace CodeAnim {

class Production {
  private:
    int width;
    int height;

  public:
    Production(int width, int height);

    int getWidth();
    int getHeight();
};

} // namespace CodeAnim
