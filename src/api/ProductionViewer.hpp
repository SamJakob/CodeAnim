#pragma once

#include "Production.hpp"
#include <gtkmm.h>

namespace CodeAnim {

class ProductionViewer : public Gtk::Window {
  private:
    Production* production;

    bool on_window_key_pressed(guint keyval, guint keycode, Gdk::ModifierType state);

  public:
    ProductionViewer(Production*);
    virtual ~ProductionViewer();
};

} // namespace CodeAnim