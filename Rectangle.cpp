#include "Rectangle.hpp"
#undef new
//Additional includes go here
#include "MemoryLeakChecker.hpp"

Rectangle::Rectangle(double centerX, double centerY, double width, double height) : Shape(centerX,centerY)
{
    this->centerX=centerX;
    this->centerY=centerY;
    this->width=width;
    this->height=height;
}
Rectangle::~Rectangle()
 {

 }


double Rectangle::Area()const
{
    return (width*height);
}

double Rectangle::Circumference() const
{
    return ( (2*width) + (2*height));
}

std::unique_ptr<Shape> Rectangle::Clone() const 
{
    std::unique_ptr<Rectangle> NewRectangle =std::make_unique<Rectangle>(centerX, centerY, width, height);
    return NewRectangle;
}

bool Rectangle::Intersects(double xCoord, double yCoord) const
{
    if(centerX- (width / 2) <=xCoord && centerX+ (width / 2) >=xCoord)
    {
        if(centerY- (height / 2) <=yCoord && centerY+ (height / 2) >=yCoord)
        {
            return true;
        }
    }
    return false;

}

std::string Rectangle::Tostring() const
{
    std::string center = Shape::Tostring();
    std::string info = center + " And has the width " + std::to_string(width) + " and the height " + std::to_string(height);
    return info;
}