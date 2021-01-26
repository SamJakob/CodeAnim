#include "Production.hpp"
#include "ProductionViewer.hpp"
#include <CodeAnimConfig.h>

#include <gtkmm.h>
#include <iostream>

namespace CodeAnim {

Production::Production(int width, int height) {
    this->width = width;
    this->height = height;
};

int Production::getWidth() { return this->width; }
int Production::getHeight() { return this->height; }

void Production::show() {
    auto app = Gtk::Application::create("com.samjakob.CodeAnim.Production");
    ProductionViewer* viewer = new ProductionViewer(this);

    app->signal_startup().connect([&] { app->add_window(*viewer); });

    viewer->show();
    app->run();
}

} // namespace CodeAnim
