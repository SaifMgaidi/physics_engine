#include "../inc/Shape.hpp"

//---------------Constructor-----------------------

Shape::Shape()
:   pos_(), velocity_(), width_(0.0f), height_(0.0f), color_(0)
{
}

Shape::Shape(float x, float y, float vx, float vy, float width, float height, uint32_t color)
:   pos_(x, y), velocity_(vx, vy), width_(width), height_(height), color_(color)
{
}

Shape::Shape(const Shape& other)
:   pos_(other.pos_), velocity_(other.velocity_), width_(other.width_),
	height_(other.height_), color_(other.color_)
{
}

Shape&	Shape::operator=(const Shape& other)
{
	if (this != &other)
	{
		pos_		= other.pos_;
		velocity_	= other.velocity_;
		width_ 		= other.width_;
		height_		= other.height_;
		color_ 		= other.color_;
	}
	return (*this);
}


//---------------Destructor-----------------------

Shape::~Shape()
{
}


//---------------Member Functions-----------------------

float	Shape::getWidth() const
{
	return (width_);
}

float	Shape::getHeight() const
{
	return (height_);
}

unsigned int	Shape::getColor() const
{
	return (color_);
}


void	Shape::setWidth(float width)
{
	width_ = width;
}

void	Shape::setHeight(float height)
{
	height_ = height;
}

void	Shape::setColor(unsigned int color)
{
	color_ = color;
}