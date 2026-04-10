#include "../inc/World.hpp"

int	World::totalObjects_ = 0;

//-------------------Constructor----------------------------------
World::World()
{
}

World::World(const World& other)
:	objects_(other.objects_)
{
}

World& World::operator=(const World& other)
{
	if (this != &other)
	{
		for (unsigned int i = 0; i < other.objects_.size(); ++i)
		{
			objects_.push_back(other.objects_[i]);
			totalObjects_++;
		}
	}
	return (*this);
}


//-------------------Destructor----------------------------------
World::~World()
{
	objects_.clear();
}


//-------------------Member Functions----------------------------------
void	World::addObject(const Shape& object)
{
	objects_.push_back(object);
	totalObjects_++;
}


void	World::removeObject()
{
	objects_.pop_back();
	totalObjects_--;
}
