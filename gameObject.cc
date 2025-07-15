#include "gameObject.h"

// ctor
GameObject::GameObject(char display, int x, int y)
    : display{display}, x{x}, y{y} {
    is_outside_chamber = (display == ' ');
}

// dtor
GameObject::~GameObject() {}

// no implementation for the pure virtual methods:
//      playerCanAccess()
//      enemyCanAccess()

// common methods
ObjectType GameObject::getType() const { return type; }

char GameObject::getDisplay() const {
    return display;
}

int GameObject::getXCoor() const { return x; }

int GameObject::getYCoor() const { return y; }

void GameObject::setXCoor( int xcoor ) { x = xcoor; }

void GameObject::setYCoor( int ycoor ) { y = ycoor; }
