struct SDL_Window;
struct SDL_Renderer;

namespace solarsystemclock {

    void initialise_sdl();
    void deinitialise_sdl();

    class Starfield;
    class Orbits;

    class Window {
    public:
        Window(int width, int height);
        ~Window();

        void resize(int width, int height);
        void mainloop();

    private:
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;

        Starfield *m_starfield;
        Orbits *m_orbits;
    };

}
