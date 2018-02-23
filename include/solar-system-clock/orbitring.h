namespace solarsystemclock {

    class Texture;

    class OrbitRing {
    public:
        OrbitRing(SDL_Renderer *renderer, int radius, int thickness);
        ~OrbitRing();

        void draw(SDL_Renderer *renderer, int x, int y, int r, int g, int b, int a);

    private:
        Texture *m_texture;
    };

}
