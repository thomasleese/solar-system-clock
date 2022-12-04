add_library(solarsystemclock_layers
    layer.cpp
    background.cpp
    starfield.cpp
    orbitrings.cpp
    sun.cpp
    planets.cpp
    rocket.cpp
    sunrisesunset.cpp
    clockhands.cpp
)

target_include_directories(solarsystemclock_layers
    PUBLIC ../include solarsystemclock_sdl
)

target_link_libraries(solarsystemclock_layers PUBLIC solarsystemclock_sdl)

target_compile_features(solarsystemclock_layers PRIVATE cxx_std_20)
target_compile_options(solarsystemclock_layers PRIVATE -Wall -pedantic)
