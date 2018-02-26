#include <SDL2/SDL.h>

#include "solar-system-clock/layers/layer.h"

using namespace solarsystemclock::layers;

Layer::Layer(SDL_Renderer *renderer, Clock *clock) : m_renderer(renderer), m_clock(clock) {

}

Layer::~Layer() {

}

void Layer::resize(int width, int height) {
    
}

void Layer::draw() {

}
