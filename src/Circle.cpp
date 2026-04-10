#include "../inc/Circle.hpp"

//--------------------Constructor--------------------------------
Circle::Circle(RenderContext& ctx)
:	Shape(ctx), radius_(0)
{
}

Circle::Circle(RenderContext& ctx, float x, float y, float vx, float vy, float radius, uint32_t color)
:	Shape(ctx, x, y, vx, vy, 0, 0, color), radius_(radius)
{
}

Circle::Circle(const Circle& other)
:	Shape(other), radius_(other.radius_)
{
}

Circle&	Circle::operator=(const Circle& other)
{
	if (this != &other)
	{
		pos_		= other.pos_;
		velocity_	= other.velocity_;
		width_		= other.width_;
		height_		= other.height_;
		color_		= other.color_;
		radius_		= other.radius_;
	}
	return (*this);
}



//--------------------Destructor--------------------------------
Circle::~Circle()
{
}



//--------------------Member Functions--------------------------------

float	Circle::getRadius() const
{
	return (radius_);
}
