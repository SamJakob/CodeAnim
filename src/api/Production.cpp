#include "Production.hpp"
#include "ProductionViewer.hpp"
#include <CodeAnimConfig.h>

#include <gtkmm.h>
#include <iostream>

namespace CodeAnim {

Production::Production(int width, int height, int fps) {
    this->width = width;
    this->height = height;
    this->fps = fps;
};

int Production::getWidth() const { return this->width; }
int Production::getHeight() const { return this->height; }
int Production::getFPS() const { return this->fps; }

void Production::show() {
    auto app = Gtk::Application::create(CODEANIM_APPLICATION_ID);
    auto viewer = new ProductionViewer(this);

    app->signal_startup().connect([&] { app->add_window(*viewer); });

    viewer->show();
    app->run();
}

} // namespace CodeAnim
