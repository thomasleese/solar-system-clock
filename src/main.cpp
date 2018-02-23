#include "solar-system-clock/window.h"

using namespace solarsystemclock;

int main(int argc, char *argv[]) {
    initialise_sdl();

    Window window(800, 600);
    window.mainloop();

    deinitialise_sdl();

    return 0;
}
