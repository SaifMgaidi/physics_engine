#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>
#include "Shape.hpp"


class World
{
public:
	// Constructor
	World();
	World(const World& other);
	World& operator=(const World& other);
	
	// Destructor
	~World();

	// Member Functions
	void	addObject(const Shape& object);
	void	removeObject();
private:
	std::vector<Shape>	objects_;
	static	int			totalObjects_;
};

#endif