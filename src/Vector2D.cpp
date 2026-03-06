#include "../inc/Vector2D.hpp"


//---------------Constructor-----------------------

Vector2D::Vector2D()
:	x_(0.0f), y_(0.0f)
{
}

Vector2D::Vector2D(float x, float y)
:	x_(x), y_(y)
{
}

Vector2D::Vector2D(const Vector2D& other)
:	x_(other.x_), y_(other.y_)
{
}

Vector2D&	Vector2D::operator=(const Vector2D& other)
{
	if (this != &other)
	{
		x_ = other.x_;
		y_ = other.y_;
	}
	return (*this);
}


//---------------Destructor-----------------------

Vector2D::~Vector2D()
{
}


//---------------Member Functions-----------------------

float	Vector2D::getX() const
{
	return (x_);
}

float	Vector2D::getY() const
{
	return (y_);
}

void	Vector2D::setX(float x)
{
	x_ = x;
}

void	Vector2D::setY(float y)
{
	y_ = y;
}
