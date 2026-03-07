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

void	Circle::draw() const
{
	int	screenY			= 0;
	int	screenX			= 0;
	int	baseY			= static_cast<int>(pos_.y);
	int	baseX			= static_cast<int>(pos_.x);
	int	w				= static_cast<int>(radius_ * 2.0f);
	int	h				= static_cast<int>(radius_ * 2.0f);
	int	radius			= static_cast<int>(radius_);
	int	currentLine		= 0;
	int	currentPixel	= 0;
	int	dx 				= 0;
	int	dy				= 0;

	for (int i = 0; i < h ; ++i)
	{
		screenY = baseY - radius + i;
		if (screenY < 0 || screenY >= ctx_.height)
			continue;
		currentLine = screenY * ctx_.width;
		for (int j = 0; j < w; ++j)
		{
			screenX = baseX - radius + j;
			if (screenX < 0 || screenX >= ctx_.width)
				continue;
			dx = screenX - baseX;
			dy = screenY - baseY;
			if ((dx*dx) + (dy*dy) > radius*radius)
				continue;
			currentPixel = currentLine + screenX;
			ctx_.buff[currentPixel] = color_;
		}
	}
}