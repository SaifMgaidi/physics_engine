#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

struct Vector2D
{
	float	x;
	float	y;

	// Constructor
	Vector2D();
	Vector2D(float a, float b);
	Vector2D(const Vector2D& other);
	Vector2D&	operator=(const Vector2D& other);

	// Destructor
	~Vector2D();

	// Member Functions
	float	getX() const;
	float	getY() const;
	void	setX(float a);
	void	setY(float a);
};

#endif