#include "../inc/Renderer.hpp"

//--------------------Constructor-----------------------------

Renderer::Renderer(RenderContext& ctx)
:   ctx_(ctx)
{
}


//--------------------Destructor-----------------------------

Renderer::~Renderer()
{
}



void	Renderer::drawRect(const Shape& shape)
{
	int	screenY			= 0;
	int	screenX			= 0;
	int	baseY			= static_cast<int>(shape.getPosition().y);
	int	baseX			= static_cast<int>(shape.getPosition().y);
	int	w				= static_cast<int>(shape.getWidth());
	int	h				= static_cast<int>(shape.getHeight());
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
			ctx_.buff[currentPixel] = shape.getColor();
		}
	}
}

void	Renderer::drawCircle(const Shape& shape)
{
	int	screenY				= 0;
	int	screenX				= 0;
	int	screenXMirror		= 0;
	int	baseY				= static_cast<int>(shape.getPosition().y);
	int	baseX				= static_cast<int>(shape.getPosition().x);
	int	h					= static_cast<int>(shape.getRadius() * 2.0f);
	int	radius				= static_cast<int>(shape.getRadius());
	int	currentLine			= 0;
	int	currentPixel		= 0;
	int	currentPixelMirror	= 0;
	int	dx 					= 0;
	int	dy					= 0;

	for (int i = 0; i < h ; ++i)
	{
		screenY = baseY - radius + i;
		if (screenY < 0 || screenY >= ctx_.height)
			continue;
		currentLine = screenY * ctx_.width;
		for (int j = 0; j < radius; ++j)
		{
			screenX = baseX - radius + j;
			if (screenX < 0 || screenX >= ctx_.width)
				continue;
			dx = screenX - baseX;
			dy = screenY - baseY;
			if ((dx*dx) + (dy*dy) > radius*radius)
				continue;
			currentPixel = currentLine + screenX;
			ctx_.buff[currentPixel] = shape.getColor();
			screenXMirror = baseX + radius - j;
			if (screenXMirror < 0 || screenXMirror >= ctx_.width)
				continue;
			currentPixelMirror = currentLine + screenXMirror;
			ctx_.buff[currentPixelMirror] = shape.getColor();
		}
	}
}