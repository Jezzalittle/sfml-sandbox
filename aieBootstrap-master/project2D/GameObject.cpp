#include "GameObject.h"
#include "GameManager.h"


GameObject::GameObject()
{
	transform = Transform();
	GameManager::instance().om->addGameObject(this);
}


GameObject::~GameObject()
{

}

void GameObject::Update(float deltaTime)
{
}

void GameObject::Draw(aie::Renderer2D * renderer)
{
}

void GameObject::OnCollision(GameObject & other)
{
}

float GameObject::GetRadius()
{
	return radius;
}

void GameObject::SetRadius(float a_radius)
{
	radius = a_radius;
}

Vector2 GameObject::GetPosition()
{
	return transform.GetPosition();
}

std::string GameObject::GetTag()
{
	return tag;
}

void GameObject::SetTag(std::string a_tag)
{
	tag = a_tag;
}

