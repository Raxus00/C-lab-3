#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#undef new
#include "Shape.hpp"
#include "MemoryLeakChecker.hpp"

class Circle : public Shape
{
public:
    Circle(double centerx, double centerY, double radius);
    virtual ~Circle();
    virtual double Area() const;
    virtual double Circumference() const;
    virtual std::unique_ptr<Shape> Clone() const;
    virtual bool Intersects(double xCoord, double yCoord) const;
    virtual std::string Tostring() const;
private:
    double radius;
};
#endif