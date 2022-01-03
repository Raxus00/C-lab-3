#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#undef new
#include "Shape.hpp"
#include "MemoryLeakChecker.hpp"

class Rectangle : public Shape
{
public:
    Rectangle(double centerx, double centerY, double width, double height);
    virtual ~Rectangle();
    virtual double Area() const;
    virtual double Circumference() const;
    virtual std::unique_ptr<Shape> Clone() const;
    virtual bool Intersects(double xCoord, double yCoord) const;
    virtual std::string Tostring() const;
private:
    double width, height;
};
#endif