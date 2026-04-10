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

