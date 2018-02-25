struct SDL_Renderer;

namespace solarsystemclock {

    class Texture;

    namespace layers {
        class OrbitRingss;
    }

    class Planet {
    public:
        Planet(SDL_Renderer *renderer, int orbit);
        ~Planet();

        void resize(int width, int height, layers::OrbitRingss *orbits);
        void update(float dt);
        void draw();

    private:
        SDL_Renderer *m_renderer;
        Texture *m_bg_texture, *m_ball_texture, *m_shadow_texture;

        int m_orbit;

        int m_cx, m_cy, m_radius;
    };

}
