#include "ProductionViewer.hpp"

#include <CodeAnimConfig.h>
#include <iostream>

namespace CodeAnim {

ProductionViewer::ProductionViewer(Production* production) {
    this->production = production;

    set_title(CODEANIM_PROJECT_NAME);
    set_default_size(this->production->getWidth(), this->production->getHeight());

    // Keyboard Events.
    auto controller = Gtk::EventControllerKey::create();
    controller->signal_key_pressed().connect(
        sigc::mem_fun(*this, &ProductionViewer::on_window_key_pressed), false);
    add_controller(controller);
}

ProductionViewer::~ProductionViewer() {}

bool ProductionViewer::on_window_key_pressed(guint keyval, guint keycode, Gdk::ModifierType state) {
    if ((state & Gdk::ModifierType::META_MASK) == Gdk::ModifierType::META_MASK &&
        keyval == GDK_KEY_q) {
        close();
        return true;
    }

    // Event has not been handled (so propagate the event).
    return false;
}

} // namespace CodeAnim