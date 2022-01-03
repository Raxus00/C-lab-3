#include "Circle.hpp"
#undef new
#include "MemoryLeakChecker.hpp"
#define USE_MATH_DEFINES
#include<cmath>
#include <math.h>
Circle::Circle(double centerX, double centerY, double radius) : Shape(centerX, centerY)
{
    this->centerX=centerX;
    this->centerY=centerY;
    this->radius=radius;
}

Circle::~Circle()
{

}

double Circle::Area() const
{
    return (radius* radius* 3.14159265358979323846); 
}

double Circle::Circumference() const
{
    return (2*radius*3.14159265358979323846);
}

std::unique_ptr<Shape> Circle::Clone() const
{
    std::unique_ptr<Circle> Newcircle = std::make_unique<Circle>(centerX, centerY, radius);
    return Newcircle;
}

bool Circle::Intersects(double xCoord, double yCoord) const 
{
    if(((pow((xCoord - centerX) , 2)) + (pow((yCoord - centerY), 2)) <pow(radius, 2)))
    {
        return true;
    } 
    return false;
}

std::string Circle::Tostring() const 
{
    std::string center = Shape::Tostring();
    std::string info = center + " and has the radius " + std::to_string(radius);
    return info;
}