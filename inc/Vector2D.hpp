#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

#include <iostream>
#include <string>

class Vector2D
{
public:
	// Constructor
	Vector2D();
	Vector2D(float x, float y);
	Vector2D(const Vector2D& other);
	Vector2D&	operator=(const Vector2D& other);

	// Destructor
	~Vector2D();

	// Member Functions
	float	getX() const;
	float	getY() const;

	void	setX(float x);
	void	setY(float y);

private:
	float	x_;
	float	y_;
};


#endif