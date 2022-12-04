#include <vector>

class SunSet;

namespace solarsystemclock {

    class Planet;

    class Clock {
    public:
        Clock();

        ~Clock();

        void resize(int width, int height);
        void update();

        float size() const;

        double seconds_angle() const;
        double minutes_angle() const;
        double hours_angle() const;
        double sunrise_angle() const;
        double sunset_angle() const;

        float orbits_size() const;
        double orbits_scale() const;
        double orbits_start() const;
        double orbits_gap() const;
        float orbits_radius(int orbit) const;

        const std::vector<Planet *> &planets() const {
            return m_planets;
        }

        Planet *planet(int orbit) const {
            return m_planets[orbit];
        }

    private:
        float m_size;
        SunSet *m_sun;
        std::vector<Planet *> m_planets;

        long m_start_ms;
    };

}
