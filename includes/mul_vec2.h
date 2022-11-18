#pragma once

template<typename T>
class Vec2 {
public:
    using ComponentType = T;

    Vec2() = default;
    Vec2(T x, T y);

    T getX() const;
    T getY() const;

    void setX(T newValue);
    void setY(T newValue);

private:
    T m_x = 0;
    T m_y = 0;
};

template<typename T>
Vec2<T>::Vec2(T x, T y) : m_x(x), m_y(y) {}

template<typename T>
T Vec2<T>::getX() const {
    return m_x;
}

template<typename T>
T Vec2<T>::getY() const {
    return m_y;
}

template<typename T>
void Vec2<T>::setX(T newValue) {
    m_x = newValue;
}

template<typename T>
void Vec2<T>::setY(T newValue) {
    m_y = newValue;
}

using Vec2F = Vec2<float>;
using Vec2I = Vec2<int>;