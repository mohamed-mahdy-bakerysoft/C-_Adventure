#pragma once

class Point2D
{
private:
    int _x, _y;

public:
    Point2D(int x = 0, int y = 0) : _x(x), _y(y) {}

    int getX() const
    {
        return _x;
    }
    int getY() const
    {
        return _y;
    }

    void setX(int x)
    {
        _x = x;
    }
    void setY(int y)
    {
        _y = y;
    }

    // Overload the < operator for use in std::map
    bool operator<(const Point2D& other) const
    {
        return (_x < other._x) || (_x == other._x && _y < other._y);
    }
};
