namespace solarsystemclock {

    class Clock;

    class Planet {
    public:
        Planet(int orbit, int diameter, int red, int green, int blue, double orbital_period, double orbit_at_2000);
        ~Planet();

        double size() const;
        double radius() const;

        double angle() const {
            return m_angle;
        }

        int red() const {
            return m_red;
        }

        int green() const {
            return m_green;
        }

        int blue() const {
            return m_blue;
        }

        void resize(Clock *clock);
        void update(long ms);

    private:
        int m_orbit, m_diameter, m_red, m_green, m_blue;
        double m_orbital_period, m_orbit_at_2000;

        double m_size, m_radius, m_angle;
    };

}
