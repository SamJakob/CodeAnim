#pragma once

#include "Production.hpp"
#include "ProductionRenderer.hpp"

#include <gtkmm.h>

namespace CodeAnim {

class ProductionViewer : public Gtk::Window {
  private:
    Production* production;
    ProductionRenderer* renderer;

    bool on_window_key_pressed(guint keyVal, guint keycode, Gdk::ModifierType state);

  public:
    explicit ProductionViewer(Production* production);
    ~ProductionViewer() override;
};

} // namespace CodeAnim