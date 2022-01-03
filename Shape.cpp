#include "Shape.hpp"
#undef new
//Additional includes go here
#include "MemoryLeakChecker.hpp"

Shape::Shape(double centerX, double centerY)
{
    this->centerX=centerX;
    this->centerY=centerY;
}

Shape::~Shape()
{

}

std::string Shape::Tostring() const
{
    std::string info =" The figure centers in " + std::to_string(centerX) + " and " + std::to_string(centerY);
    return info;
}