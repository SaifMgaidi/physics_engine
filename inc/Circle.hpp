#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Shape.hpp"
#include <iostream>
#include <string>


class Circle : public Shape
{
public:
	// Constructor
	Circle(RenderContext& ctx);
	Circle(RenderContext& ctx, float x, float y, float vx, float vy, float radius, uint32_t color);
	Circle(const Circle& other);
	Circle&	operator=(const Circle& other);

	// Destructor
	~Circle();

	// Member Functions
	void	draw() const override;
private:
	float	radius_;
};

#endif