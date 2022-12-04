add_library(solarsystemclock_sdl
  error.cpp
  font.cpp
  init.cpp
  renderer.cpp
  surface.cpp
  texture.cpp
  window.cpp
)

target_include_directories(solarsystemclock_sdl
  PUBLIC ../../include ${SDL2_INCLUDE_DIRS}
)

target_link_directories(solarsystemclock_sdl PUBLIC ${SDL2_LIBRARY_DIRS})
target_link_libraries(solarsystemclock_sdl PUBLIC ${SDL2_LIBRARIES})

target_compile_features(solarsystemclock_sdl PUBLIC cxx_std_20)
