#include "../inc/MyWindow.hpp"

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

	pixels_ = new u_int32_t[width_ * height_];

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

void	MyWindow::display(void)
{
	int		x = width_ / 2;
	int		y = height_ / 2;

	clear();
	if (x < width_ && x > -1 && y < height_ && y > -1)
		pixels_[y * width_ + x] = 0x00FFFFFF;
	XPutImage(dpy_, win_, GC_, img, 0, 0, 0, 0, width_, height_);
}

void	MyWindow::run(void)
{
	XEvent	event;
	KeySym	key;
	char	text[255];
	int		running = 1;

	XMapWindow(dpy_, win_);
	while (running)
	{

		while (XPending(dpy_) > 0)
		{
			XNextEvent(dpy_, &event);
			if (event.type == ClientMessage)
			{
				if ((Atom)event.xclient.data.l[0] == wmDeleteMessage_)
					running = 0;
			}
			if (event.type == KeyPress)
			{
				XLookupString(&event.xkey, text, 255, &key, NULL);
				if (key == XK_Escape)
					running = 0;
			}
		}
		display();
		XFlush(dpy_);
	}
}