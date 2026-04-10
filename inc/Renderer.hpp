#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "RenderContext.hpp"
#include "Shape.hpp"

class Renderer
{
public:
    // Constructor
    Renderer(RenderContext& ctx);
    
    // Destructor
    ~Renderer();

    // Member Functions
    void    drawRect(const Shape& shape);
    void    drawCircle(const Shape& shape);
private:
    RenderContext&  ctx_;
};


#endif