#ifndef SHAPECONTAINER_HPP
#define SHAPECONTAINER_HPP
#undef new
#include "Shape.hpp" 
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "MemoryLeakChecker.hpp"

class ShapeContainer
{
public:
    ShapeContainer();
    ~ShapeContainer();
    void AddCircle(double centerX, double centerY, double radius);
    void AddRectangle(double centerX, double centerY, double width, double height);
    double CalculateTotalArea() const;
    double CalculateTotalCircumference() const;
    std::string ToString() const;
    bool Intersects(double xCoord, double yCoord) const;
    ShapeContainer& operator=(const ShapeContainer& other);
    ShapeContainer(const ShapeContainer& other);
private:
    std::vector<std::shared_ptr<Shape>> Container;
protected:

};
#endif