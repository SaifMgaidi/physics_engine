#include "../inc/Rect.hpp"

Rect::Rect()
:	Shape()
{
}

Rect::Rect(float x, float y, float vx, float vy, float width, float height, unsigned int color)
:	Shape(x, y, vx, vy, width, height, color)
{
}

Rect::Rect(const Rect& other)
:	Shape(other)
{
}

Rect& Rect::operator=(const Rect& other)
{
	if (this != &other)
		Shape::operator=(other);
	return (*this);
}

Rect::~Rect()
{
}


void	Rect::draw() const
{
	
}