#include "ShapeContainer.hpp"
#undef new
#include "MemoryLeakChecker.hpp"

ShapeContainer::ShapeContainer()
{

}

ShapeContainer::~ShapeContainer()
{

}

ShapeContainer& ShapeContainer::operator=(const ShapeContainer& other)
{
	if (this != &other)
	{
		Container.clear();
		for (std::shared_ptr<Shape> ptr : other.Container)
		{
			Container.push_back(ptr->Clone());
		}
	}
	return *this;
}

ShapeContainer::ShapeContainer(const ShapeContainer& other)
{
	for (std::shared_ptr<Shape> ptr : other.Container)
	{
		Container.push_back(ptr->Clone());
	}
}

void ShapeContainer::AddCircle(double centerX, double centerY, double radius)
{
	std::shared_ptr<Shape> NewCircle(new Circle(centerX, centerY, radius));
	Container.push_back(std::move(NewCircle));
}

void ShapeContainer::AddRectangle(double centerX, double centerY, double width, double height)
{
	std::shared_ptr<Shape> NewRectangle (new Rectangle(centerX, centerY, width, height));
	Container.push_back(std::move(NewRectangle));
}

double ShapeContainer::CalculateTotalArea() const
{
	double all_area = 0;
	for (std::shared_ptr<Shape> ptr : Container)
	{
		all_area += ptr->Area();
	}
	return all_area;
}

double ShapeContainer::CalculateTotalCircumference() const
{
	double all_circumference = 0;
	for (std::shared_ptr<Shape> ptr : Container)
	{
		all_circumference += ptr->Circumference();
	}
	return all_circumference;
}

std::string ShapeContainer::ToString() const
{
	std::string info = " ";
	for (std::shared_ptr<Shape> ptr : Container)
	{
		info += ptr->Tostring();
		info += " ";
	}
	return info;
}

bool ShapeContainer::Intersects(double Xcoord, double Ycoord) const
{
	for (std::shared_ptr<Shape> ptr : Container)
	{
		if (ptr->Intersects(Xcoord, Ycoord))
		{
			return true;
		}
	}
	return false;
}