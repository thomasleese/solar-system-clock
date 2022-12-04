#include "solarsystemclock/clock.h"
#include "solarsystemclock/sdl/init.h"
#include "solarsystemclock/sdl/window.h"

#include "solarsystemclock/solarsystemclock.h"

using namespace solarsystemclock;

int main(int argc, char *argv[]) {
    SolarSystemClock solarSystemClock;
    solarSystemClock.run();
    return 0;
}
