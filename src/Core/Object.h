#ifndef ___OBJECT_H___
#define ___OBJECT_H___

#include "SFML/Graphics.hpp"

class Object {
public:
    friend class Window;

    Object();
    virtual ~Object();

protected:
    virtual void Update() = 0;
    virtual void Draw(sf::RenderWindow& window) = 0;

private:
    Object* next_ = nullptr;
    Object* prev_ = nullptr;
    static Object* Head_; // Ptr to head of Object list
};

#endif // ___OBJECT_H___