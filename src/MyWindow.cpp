#include "../inc/MyWindow.hpp"
#include "../inc/RenderContext.hpp"

// ---------------------Constructor-----------------------------------

MyWindow::MyWindow(int w, int h)
:	width_(w), height_(h)
{
	dpy_ = XOpenDisplay(NULL);
	if (!dpy_)
	{
		throw std::runtime_error("Unable to connect to X11");
		return ;
	}
	scr_ = DefaultScreen(dpy_);
	root_ = RootWindow(dpy_, scr_);
	visual_ = XDefaultVisual(dpy_, scr_);
	depth_ = XDefaultDepth(dpy_, scr_);
	win_ = XCreateSimpleWindow(
		dpy_,
		root_,
		100, 100,
		width_, height_,
		1,
		BlackPixel(dpy_, scr_),
		BlackPixel(dpy_, scr_)
	);

	XSelectInput(dpy_, win_, ExposureMask | KeyPressMask);
	wmDeleteMessage_ = XInternAtom(dpy_, "WM_DELETE_WINDOW", false);
	XSetWMProtocols(dpy_, win_, &wmDeleteMessage_, 1);

	pixels_ = new u_int32_t[width_ * height_]();

	img = XCreateImage(
		dpy_, visual_, depth_, ZPixmap, 0, reinterpret_cast<char*>(pixels_),
		width_, height_, 32, width_ * sizeof(u_int32_t)
	);

	if (!img)
	{
		delete[] pixels_;
		throw std::runtime_error("Create XImage failed");
	}
	GC_ = XDefaultGC(dpy_, scr_);
	XMapWindow(dpy_, win_);
}

// ---------------------Destructor-----------------------------------

MyWindow::~MyWindow()
{
	if (dpy_)
	{
		img->data = NULL;
		XDestroyImage(img);
		delete[] pixels_;
		XDestroyWindow(dpy_, win_);
		XCloseDisplay(dpy_);
	}
}


// ---------------------Member Functions-----------------------------------

void	MyWindow::clear(void)
{
	memset(pixels_, 0, width_ * height_ * sizeof(u_int32_t));
}

void	MyWindow::display()
{
	clear();
}

uint32_t*	MyWindow::getPixels() const
{
	return (pixels_);
}

Atom	MyWindow::getWmDeleteMessage() const
{
	return (wmDeleteMessage_);
}

Display*	MyWindow::getDpy() const
{
	return (dpy_);
}

int	MyWindow::getWidth() const
{
	return (width_);
}

int	MyWindow::getHeight() const
{
	return (height_);
}
