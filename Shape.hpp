#ifndef SHAPE_HPP
#define SHAPE_HPP
#undef new
#include <iostream>
#include <memory>
#include <string>
#include "MemoryLeakChecker.hpp"

class Shape
{
public:
    Shape(double centerX, double centerY);
    ~Shape();
    virtual double Area() const =0;
    virtual double Circumference() const =0;
    virtual std::unique_ptr<Shape> Clone() const =0;
    virtual bool Intersects(double xCoord, double yCoord) const =0;
    std::string Tostring() const;

private:

protected:
    double centerX, centerY;
};
#endif