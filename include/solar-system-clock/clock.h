#include <vector>

namespace solarsystemclock {

    class Planet;

    class Clock {
    public:
        Clock();
        ~Clock();

        void resize(int width, int height);
        void update(double dt);

        double size() const;

        double orbits_size() const;
        double orbits_scale() const;
        double orbits_start() const;
        double orbits_gap() const;
        double orbits_radius(int orbit) const;

        const std::vector<Planet *> &planets() const {
            return m_planets;
        }

        Planet *planet(int orbit) const {
            return m_planets[orbit];
        }

    private:
        int m_size;
        std::vector<Planet *> m_planets;
    };

}
