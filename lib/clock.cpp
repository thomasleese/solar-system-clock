#include <algorithm>
#include <chrono>
#include <ctime>
#include <cmath>
#include <iostream>
#include <sys/time.h>

#include <sunset/sunset.h>

#include "solar-system-clock/planet.h"

#include "solar-system-clock/clock.h"

using namespace solarsystemclock;

Clock::Clock() : m_sun(new SunSet) {
    m_planets.push_back(new Planet(0, 4780, 0x80, 0x80, 0x80, 0.240846, 208.03));
    m_planets.push_back(new Planet(1, 12104, 0xff, 0x90, 0x00, 0.615198, 278.75));
    m_planets.push_back(new Planet(2, 12756, 0x00, 0xc0, 0x50, 1.0, 0.0));
    m_planets.push_back(new Planet(3, 6780, 0xef, 0x10, 0x00, 1.881, 100.99));
    m_planets.push_back(new Planet(4, 139822, 0xe0, 0xa0, 0x70, 11.86, 63.41));
    m_planets.push_back(new Planet(5, 116464, 0xef, 0xb0, 0x20, 29.46, 54.66));
    m_planets.push_back(new Planet(6, 50724, 0x00, 0xb0, 0xc0, 84.01, 149.55));
    m_planets.push_back(new Planet(7, 49248, 0x15, 0x40, 0xff, 164.8, 159.62));

    m_sun->setPosition(51.5349920, 0.0066170, 0);
}

Clock::~Clock() {
    delete m_sun;

    for (auto &planet : m_planets) {
        delete planet;
    }
}

void Clock::resize(int width, int height) {
    m_size = std::min(width, height);

    for (auto &planet : m_planets) {
        planet->resize(this);
    }
}

void Clock::update(double dt) {
    auto t = std::time(nullptr);
    auto tm = std::localtime(&t);

    m_sun->setCurrentDate(tm->tm_year, tm->tm_mon + 1, tm->tm_mday);

    for (auto &planet : m_planets) {
        planet->update(dt);
    }
}

double Clock::size() const {
    return m_size;
}

double Clock::seconds_angle() const {
    timeval tv;
    gettimeofday(&tv, NULL);

    auto t = std::time(nullptr);
    auto tm = std::localtime(&t);

    double seconds = tm->tm_sec + (tv.tv_usec / 1000.0 / 1000.0);
    double proportion = seconds / 60.0;

    return proportion * M_PI * 2.0;
}

double Clock::minutes_angle() const {
    auto t = std::time(nullptr);
    auto tm = std::localtime(&t);

    double minutes = tm->tm_min + (tm->tm_sec / 60.0);
    double proportion = minutes / 60.0;

    return proportion * M_PI * 2.0;
}

double Clock::hours_angle() const {
    auto t = std::time(nullptr);
    auto tm = std::localtime(&t);

    int hour = tm->tm_hour;
    if (hour > 12) {
        hour -= 12;
    }

    double hours = static_cast<double>(hour) + (tm->tm_min / 60.0) + (tm->tm_sec / 60.0 / 60.0);
    double proportion = hours / 12.0;

    return proportion * M_PI * 2.0;
}

double Clock::sunrise_angle() const {
    double sunrise = m_sun->calcSunrise();
    auto proportion = sunrise / (12.0 * 60.0);
    return proportion * M_PI * 2.0;
}

double Clock::sunset_angle() const {
    double sunset = m_sun->calcSunset();
    auto proportion = sunset / (12.0 * 60.0);
    return proportion * M_PI * 2.0;
}

double Clock::orbits_size() const {
    return m_size * 0.8;
}

double Clock::orbits_scale() const {
    return orbits_size() / 1024.0;
}

double Clock::orbits_start() const {
    return orbits_scale() * 100.0;
}

double Clock::orbits_gap() const {
    return orbits_scale() * 55.0;
}

double Clock::orbits_radius(int orbit) const {
    return orbits_start() + orbits_gap() * orbit;
}
