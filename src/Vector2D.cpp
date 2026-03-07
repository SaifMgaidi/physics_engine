#include "../inc/Vector2D.hpp"

//---------------Constructor------------------------------

Vector2D::Vector2D()
:	x(0), y(0)
{
}

Vector2D::Vector2D(float a, float b)
:	x(a), y(b)
{
}

Vector2D::Vector2D(const Vector2D& other)
:	x(other.x), y(other.y)
{
}

Vector2D&	Vector2D::operator=(const Vector2D& other)
{
	if (this != &other)
	{
		x = other.x;
		y = other.y;
	}
	return (*this);
}


//---------------Destructor------------------------------

Vector2D::~Vector2D()
{
}



//---------------Member Functions------------------------------

float	Vector2D::getX() const
{
	return (x);
}

float	Vector2D::getY() const
{
	return (y);
}

void	Vector2D::setX(float a)
{
	x = a;
}

void	Vector2D::setY(float a)
{
	y = a;
}