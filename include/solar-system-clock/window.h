struct SDL_Window;
struct SDL_Renderer;

namespace solarsystemclock {

    void initialise_sdl();
    void deinitialise_sdl();

    namespace layers {
        class Starfield;
        class Orbits;
        class Sun;
    }

    class Planet;

    class Window {
    public:
        Window(int width, int height);
        ~Window();

        void resize(int width, int height);
        void mainloop();

    private:
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;

        layers::Starfield *m_starfield;
        layers::Orbits *m_orbits;
        layers::Sun *m_sun;
        Planet *m_planet;
    };

}
