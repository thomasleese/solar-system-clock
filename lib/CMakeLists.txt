set(LIB_FILES window.cpp texture.cpp clock.cpp planet.cpp layers/layer.cpp layers/solarsystemclock.cpp layers/background.cpp layers/starfield.cpp layers/orbitrings.cpp layers/sun.cpp layers/planets.cpp layers/rocket.cpp layers/sunrisesunset.cpp)

include_directories(../deps/sunset/include)

add_library(solarsystemclock ${LIB_FILES})
