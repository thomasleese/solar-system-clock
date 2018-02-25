struct SDL_Renderer;

namespace solarsystemclock {
    class Texture;

    namespace layers {
        class OrbitRingss;
    }
}

namespace solarsystemclock::sprites {

    class Planet {
    public:
        Planet(SDL_Renderer *renderer, int orbit, int diameter, int red, int green, int blue);
        ~Planet();

        void resize(int width, int height, layers::OrbitRingss *orbit_rings);
        void update(double dt);
        void draw();

    private:
        SDL_Renderer *m_renderer;
        Texture *m_bg_texture, *m_ball_texture, *m_shadow_texture;

        int m_orbit, m_diameter, m_r, m_g, m_b;

        int m_cx, m_cy, m_radius, m_size;

        double m_angle;
    };

}