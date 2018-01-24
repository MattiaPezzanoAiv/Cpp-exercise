#pragma once
#include <math.h>
struct Vector3
{
    float x;
    float y;
    float z;

    Vector3()
    {
        x = 0;
        y = 0;
        z = 0;
    }
    Vector3(float n)
    {
        x = n;
        y = n;
        z = n;
    }
    Vector3(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vector3 operator+(Vector3 v2)
    {
        return Vector3(this->x + v2.x,this->y + v2.y, this->z + v2.z);
    }
    Vector3 operator-(Vector3 v2)
    {
        return Vector3(this->x - v2.x,this->y - v2.y, this->z - v2.z);
    }
    Vector3 operator*(Vector3 v2)
    {
        return Vector3(this->x * v2.x,this->y * v2.y, this->z * v2.z);
    }
    
    float Length()
    {
        return (sqrtf(powf(this->x,2)+powf(this->y,2)+powf(this->z,2)));
    }
    Vector3 Normalized()
    {
        float length = Length();
        return Vector3(this->x/length,this->y/length,this->z/length);
    }

    static float Distance(Vector3 V1, Vector3 V2)
    {
        return (V1-V2).Length();
    }
    static Vector3 Direction(Vector3 Start, Vector3 ToLook)
    {
        return (ToLook - Start).Normalized();
    }
};