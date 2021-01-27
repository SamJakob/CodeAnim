#include "Production.hpp"
#include <gtkmm/drawingarea.h>

namespace CodeAnim {

class ProductionRenderer : public Gtk::DrawingArea {
  private:
    Production* production;

  public:
    explicit ProductionRenderer(Production* production);
    ~ProductionRenderer() override;

  protected:
    void on_draw(const Cairo::RefPtr<Cairo::Context>& cairo, int width, int height);
};

} // namespace CodeAnim
