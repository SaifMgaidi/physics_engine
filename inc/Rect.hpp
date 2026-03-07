#ifndef RECT_HPP
#define RECT_HPP

#include "Shape.hpp"
#include <iostream>
#include <string>

class Rect : public Shape
{
public:
	// Constructor
	Rect(RenderContext& ctx);
	Rect(RenderContext& ctx, float x, float y, float vx, float vy, float width, float height, unsigned int color);
	Rect(const Rect& other);
	Rect&	operator=(const Rect& other);

	// Destructor
	~Rect();

	// Member Functions
	void	draw() const override;
private:
};

#endif