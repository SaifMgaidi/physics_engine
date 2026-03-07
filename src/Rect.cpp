#include "../inc/Rect.hpp"

//-------------------Constructor---------------------------------

Rect::Rect(RenderContext& ctx)
:	Shape(ctx)
{
}

Rect::Rect(RenderContext& ctx, float x, float y, float vx, float vy, float width, float height, unsigned int color)
:	Shape(ctx, x, y, vx, vy, width, height, color)
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


//-------------------Destructor---------------------------------

Rect::~Rect()
{
}



//-------------------Member Functions---------------------------------

void	Rect::draw() const
{
	int	screenY			= 0;
	int	screenX			= 0;
	int	baseY			= static_cast<int>(pos_.y);
	int	baseX			= static_cast<int>(pos_.x);
	int	w				= static_cast<int>(width_);
	int	h				= static_cast<int>(height_);
	int	currentLine		= 0;
	int	currentPixel	= 0;

	for (int i = 0; i < h ; ++i)
	{
		screenY = baseY + i;
		if (screenY < 0 || screenY >= ctx_.height)
			continue;
		currentLine = screenY * ctx_.width;
		for (int j = 0; j < w; ++j)
		{
			screenX = baseX + j;
			if (screenX < 0 || screenX >= ctx_.width)
				continue;
			currentPixel = currentLine + screenX;
			ctx_.buff[currentPixel] = color_;
		}
	}
}