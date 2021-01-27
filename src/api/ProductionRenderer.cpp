#include "ProductionRenderer.hpp"

#include <iostream>

namespace CodeAnim {

ProductionRenderer::ProductionRenderer(Production* production) {
    this->production = production;
    set_draw_func(sigc::mem_fun(*this, &ProductionRenderer::on_draw));
}
ProductionRenderer::~ProductionRenderer() = default;

void ProductionRenderer::on_draw(Cairo::RefPtr<Cairo::Context> const& cairo, int width,
                                 int height) {
    // TODO: Draw frame.
}

} // namespace CodeAnim