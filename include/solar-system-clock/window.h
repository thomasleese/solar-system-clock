struct SDL_Window;
struct SDL_Renderer;

namespace solarsystemclock {

    void initialise_sdl();
    void deinitialise_sdl();

    class Window {
    public:
        Window(int width, int height);
        ~Window();

        void mainloop();

    private:
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
    };

}
