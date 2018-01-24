#include <engine.h>

using namespace AivEngine;

int main(int argc, char* args[])
{
    Engine Context(500,500);
    GameObject go(std::string("Mattia"));
    std::cout <<"Player Created: "<< go.Name << std::endl;
    std::cout << Context.GameObjectsCount() << std::endl;
    RectRenderer renderer = RectRenderer();
    go.AddComponent(&renderer);
    Context.Spawn(&go);

    while(Context.IsOpened)
    {
        SDL_Event e;
        while(SDL_PollEvent(&e) != 0)       //manage quit event
            if(e.type == SDL_QUIT)
                Context.IsOpened = false;
        Context.Clear();



        Context.Update();       //update objects
        Context.Render();
    }

    std::cout << "done" <<std::endl;
}