#include "../inc/WINDOW.hpp"

// ---------------------Constructor-----------------------------------

WINDOW::WINDOW(int w, int h)
:	width(w), height(h)
{
	dpy = XOpenDisplay(NULL);
	if (!dpy)
	{
		throw std::runtime_error("Unable to connect to X11");
		return ;
	}
	scr = DefaultScreen(dpy);
	root = RootWindow(dpy, scr);
	win = XCreateSimpleWindow(
		dpy,
		root,
		100, 100,
		width, height,
		1,
		BlackPixel(dpy, scr),
		BlackPixel(dpy, scr)
	);

	XSelectInput(dpy, win, ExposureMask | KeyPressMask);
	wmDeleteMessage = XInternAtom(dpy, "WM_DELETE_WINDOW", false);
	XSetWMProtocols(dpy, win, &wmDeleteMessage, 1);
}

// ---------------------Destructor-----------------------------------

WINDOW::~WINDOW()
{
	if (dpy)
	{
		XDestroyWindow(dpy, win);
		XCloseDisplay(dpy);
	}
}


// ---------------------Member Functions-----------------------------------

void	WINDOW::display(void)
{
	
}

void	WINDOW::run(void)
{
	XEvent	event;
	KeySym	key;
	char	text[255];
	int		running = 1;

	XMapWindow(dpy, win);
	while (running)
	{

		while (XPending(dpy) > 0)
		{
			XNextEvent(dpy, &event);
			if (event.type == ClientMessage)
			{
				if ((Atom)event.xclient.data.l[0] == wmDeleteMessage)
					running = 0;
			}
			if (event.type == KeyPress)
			{
				XLookupString(&event.xkey, text, 255, &key, NULL);
				if (key == XK_Escape)
					running = 0;
			}
		}
	}
}