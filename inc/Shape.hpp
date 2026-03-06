#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "../inc/Vector2D.hpp"
#include <stdint.h>
#include <iostream>
#include <string>


class Shape
{
public:
	// Constructor
	Shape();
	Shape(float x, float y, float vx, float vy, float width, float height, uint32_t color);
	Shape(const Shape& other);
	Shape& operator=(const Shape& other);
	
	// Destructor
	~Shape();

	// Member Functions
	float			getWidth() const;
	float			getHeight() const;
	unsigned int	getColor() const;

	void			setWidth(float width);
	void			setHeight(float height);
	void			setColor(unsigned int color);

	virtual void	draw() const = 0;

protected:
	Vector2D	pos_;
	Vector2D	velocity_;
	float		width_;
	float		height_;
	uint32_t	color_;
	uint32_t&	buff_;
};

#endif