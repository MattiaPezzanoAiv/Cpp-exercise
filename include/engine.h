
#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include <aiv_math.h>
#include <aiv_game_object.h>
#include <vector>
// #include <rect_renderer.h>
// #include <component.h>

namespace AivEngine
{
    class Engine
    {
    private:
         SDL_Window* window;
            
         SDL_Renderer* renderer;
         std::vector<GameObject*> GameObjects;

        
    public:
        Engine(int w, int h);
        Engine();
        ~Engine();

        void Update();
        void Clear() const;
        void Render() const;
        bool Spawn(GameObject* obj);         //spawn in game a gameobject and return bool value
        int GameObjectsCount();
        SDL_Renderer* GetRenderer();       //porcata megagalattica

        bool IsOpened;


        
    };
    
//static method
    SDL_Renderer* Engine::GetRenderer()
    {
        return renderer;
    }

    Engine::Engine(int w, int h) 
    {
        if(SDL_Init(SDL_WINDOW_OPENGL) != 0)
        {
            const char* err = SDL_GetError();
            std::cout << err << std::endl;
            return;
        }
        if(SDL_CreateWindowAndRenderer(w,h,0,&window,&renderer) != 0)
        {
            const char* err = SDL_GetError();
            std::cout << err << std::endl;
            return;
        }
        this->IsOpened = true;
        GameObjects = std::vector<GameObject*>();            //this is a list
        
    }
    Engine::Engine()
    {
        if(SDL_Init(SDL_WINDOW_OPENGL) != 0)
        {
            const char* err = SDL_GetError();
            std::cout << err << std::endl;
            return;
        }
        if(SDL_CreateWindowAndRenderer(500,500,0,&window,&renderer) != 0)
        {
            const char* err = SDL_GetError();
            std::cout << err << std::endl;
            return;
        }
        this->IsOpened = true;
        GameObjects = std::vector<GameObject*>();            //this is a list
    }
    Engine::~Engine()
    {
        if(!window) SDL_DestroyWindow(window);
        if(!renderer) SDL_DestroyRenderer(renderer);

        SDL_Quit();
    }

    void Engine::Clear() const
    {
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);
    }
    void Engine::Render() const
    {
        SDL_RenderPresent(renderer);  
    }
    void Engine::Update()
    {
        for(int i = 0; i< GameObjects.size(); i++)
        {
            if(GameObjects[i]->IsActive)
                GameObjects[i]->Update();
        }

    }   
    bool Engine::Spawn(GameObject* obj)
    {
        if(!obj)
        {
            std::cout << "Obj is null"<<std::endl;
            return false;
        }
        GameObjects.push_back(obj);         //add gameobjects to list
        return true;
    }
    int Engine::GameObjectsCount()
    {
        return GameObjects.size();
    }
}
