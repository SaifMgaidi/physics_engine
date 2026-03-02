#include "../inc/WINDOW.hpp"

int	main(void)
{
	try
	{
		WINDOW	win(500, 500);
		win.run();
	}
	catch(const std::exception& e)
	{
		std::cerr << "error: " << e.what() << '\n';
		return (1);
	}
	return (0);
}