include_directories(../deps/sunset/include)

add_library(solarsystemclock_lib window.cpp texture.cpp clock.cpp planet.cpp layers/layer.cpp layers/solarsystemclock.cpp layers/background.cpp layers/starfield.cpp layers/orbitrings.cpp layers/sun.cpp layers/planets.cpp layers/rocket.cpp layers/sunrisesunset.cpp layers/clockhands.cpp)

target_include_directories(solarsystemclock_lib PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_directories(solarsystemclock_lib PUBLIC ${SDL2_LIBRARY_DIRS})
target_link_libraries(solarsystemclock_lib PUBLIC ${SDL2_LIBRARIES})
