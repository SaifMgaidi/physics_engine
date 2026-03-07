#ifndef RENDERCONTEXT_HPP
#define RENDERCONTEXT_HPP

#include <stdint.h>
#include <stdexcept>

struct RenderContext
{
	uint32_t	*buff;
	int			width;
	int			height;

	RenderContext(uint32_t* buffer, int w, int h)
	: buff(buffer), width(w), height(h)
	{
		if (!buff)
			throw std::runtime_error("pixels buffer not valid");
	}
};

#endif