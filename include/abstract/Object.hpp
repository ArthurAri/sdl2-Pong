#ifndef OBJECT_H
#define OBJECT_H

#include <utils/math.hpp>
#include "component.hpp"
#include <vector>

using namespace Math;

class Object {
    public:
        void Init();
        void Start();
        void Update(float dt);

        void AddComponent(Component Component){};
        
        Vector3 position;
        Object(Vector3 position) : position(position){};
    private:
        std::vector<Component> components;
};

#endif