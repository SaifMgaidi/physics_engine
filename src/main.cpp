#include "../inc/MyWindow.hpp"
#include "../inc/RenderContext.hpp"

void	run(MyWindow& win)
{
	XEvent			event;
	KeySym			key;
	char			text[255];
	int				running = 1;
	RenderContext	ctx(win.getPixels(), win.getWidth(), win.getHeight());

	while (running)
	{
		while (XPending(win.getDpy()) > 0)
		{
			XNextEvent(win.getDpy(), &event);
			if (event.type == ClientMessage)
			{
				if ((Atom)event.xclient.data.l[0] == win.getWmDeleteMessage())
					running = 0;
			}
			if (event.type == KeyPress)
			{
				XLookupString(&event.xkey, text, 255, &key, NULL);
				if (key == XK_Escape)
					running = 0;
			}
		}
		win.display();
		XFlush(win.getDpy());
	}
}


int	main(void)
{
	int	width = 500;
	int	height = 500;

	try
	{
		MyWindow	win(width, height);
		run(win);
	}
	catch(const std::exception& e)
	{
		std::cerr << "error: " << e.what() << '\n';
		return (1);
	}
	return (0);
}