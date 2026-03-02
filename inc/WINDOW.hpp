#ifndef WINDOW_HPP
# define WINDOW_HPP

#include <iostream>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>

class WINDOW
{
public:
	// Constructor
	WINDOW(int w, int h);

	// Destructor
	~WINDOW();

	// Member Functions
	void		display(void);
	void		run(void);
private:
	int			width;
	int			height;
	Display*	dpy;
	int			scr;
	Window		root;
	Window		win;
	Atom		wmDeleteMessage;
};

#endif