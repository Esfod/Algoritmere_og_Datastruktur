#pragma once
#include "Vector2d.h"
#include <string>

class GameObject {

public:
	GameObject();
	GameObject(const Vector2d& position, std::string navn);
	Vector2d m_postion;
	std::string m_navn;

private:
};

GameObject::GameObject() : m_postion {0}, m_navn{0} {

}

GameObject::GameObject(const Vector2d& position, std::string navn) : m_postion{ position }, m_navn{ navn } {

}
