#pragma once
#include <engine.h>
#include <aiv_game_object.h>


namespace AivEngine
{

    class Component
    {

    private:
        bool IsStarted;

    protected:
        virtual void Start();

    public:
        GameObject* Owner;
        virtual void Update();
        bool IsEnabled;
        Component();
    };

    Component::Component()
    {
        IsEnabled = true;
    }

    void Component::Start()
    {
        IsStarted = true;
    }

    void Component::Update()
    {
        if(!IsStarted) this->Start();       //if not started do start
        std::cout <<"base component updated"<<std::endl;
    }
}


