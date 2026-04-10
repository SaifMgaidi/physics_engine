#ifndef MYWINDOW_HPP
# define MYWINDOW_HPP

#include <iostream>
#include <stdint.h>
#include <cstring>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>

class MyWindow
{
public:
	// Constructor
	MyWindow(int w, int h);

	// Destructor
	~MyWindow();

	// Member Functions
	void		clear();
	void		display();
	uint32_t*	getPixels() const;
	int			getWidth() const;
	int			getHeight() const;
	Atom		getWmDeleteMessage() const;
	Display*	getDpy() const;
private:
	int			width_;
	int			height_;
	Display*	dpy_;
	Visual*		visual_;
	int			depth_;
	int			scr_;
	Window		root_;
	Window		win_;
	Atom		wmDeleteMessage_;
	uint32_t	*pixels_;
	XImage*		img;
	GC			GC_;
};

#endif