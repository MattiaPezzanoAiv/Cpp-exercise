#pragma once
#include <engine.h>
#include <component.h>


namespace AivEngine
{
    class RectRenderer : public Component
    {
    public:
        void Update();
    };

    void RectRenderer::Update()
    {
        // SDL_RenderDrawRect()
        std::cout <<"RENDERER UPDATED"<<std::endl;
    }

}