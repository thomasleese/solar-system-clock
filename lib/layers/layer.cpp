#include "solarsystemclock/sdl/renderer.h"

#include "solarsystemclock/layers/layer.h"

using namespace solarsystemclock::layers;

Layer::Layer(const sdl::Renderer &renderer, const Clock &clock)
        : m_renderer(renderer), m_clock(clock) {

}

void Layer::resize(int width, int height) {

}

void Layer::draw() {

}
