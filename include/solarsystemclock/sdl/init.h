#ifndef SOLARSYSTEMCLOCK_SDL_INIT_H
#define SOLARSYSTEMCLOCK_SDL_INIT_H

#include <memory>

namespace spdlog {
    class logger;
}

namespace solarsystemclock::sdl {

    class Init {
    public:
        Init();
        ~Init();

    private:
        std::shared_ptr<spdlog::logger> m_logger;
    };

}

#endif // SOLARSYSTEMCLOCK_SDL_INIT_H
