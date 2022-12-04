add_subdirectory(layers)
add_subdirectory(sdl)

add_library(solarsystemclock_lib
    clock.cpp
    planet.cpp
    solarsystemclock.cpp
)

target_include_directories(solarsystemclock_lib
    PUBLIC ../include solarsystemclock_layers
)

target_link_libraries(solarsystemclock_lib PUBLIC solarsystemclock_layers sunset)

target_compile_features(solarsystemclock_lib PRIVATE cxx_std_20)
target_compile_options(solarsystemclock_lib PRIVATE -Wall -pedantic)
