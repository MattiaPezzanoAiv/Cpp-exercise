// #pragma once
#include <engine.h>
#include <vector>
#include <algorithm>
#include <component.h>



namespace AivEngine
{
    
class GameObject
{
public:
    // Engine* OwnerEngine;
    Vector3 Position;
    // Vector3 Scale;
    std::string Name;
    bool IsActive;

    GameObject();
    GameObject(std::string name);

    void Update();

    void AddComponent(Component*);

private:
    std::vector<Component*> Components;             //list of components


};

GameObject::GameObject()
{
    this->Position = Vector3();
    this->Name = std::string("Default");

    this->Components = std::vector<Component*>();
    IsActive = true;
}
GameObject::GameObject(std::string name)
{
    this->Position = Vector3();
    this->Name = name;
    IsActive = true;
}
void GameObject::Update()
{
    for(int i = 0; i < this->Components.size(); i++)
    {
        if(this->Components[i]->IsEnabled)
            this->Components[i]->Update();
    }
}
void GameObject::AddComponent(Component* comp)
{
    if(std::find(this->Components.begin(),this->Components.end(),comp) == this->Components.end())
    {
        // comp->Owner = this;
        Components.push_back(comp);
    }
}
}
