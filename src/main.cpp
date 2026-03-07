#include "../inc/MyWindow.hpp"

int	main(void)
{
	int	width = 500;
	int	height = 500;

	try
	{
		MyWindow	win(width, height);
		win.run();
	}
	catch(const std::exception& e)
	{
		std::cerr << "error: " << e.what() << '\n';
		return (1);
	}
	return (0);
}