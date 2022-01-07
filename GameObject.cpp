#include "GameObject.h"


GameObject::GameObject(const CellPosition & pos)
{
	position = pos; // Sets Position
}

CellPosition GameObject::GetPosition() const
{
	return position;
}

void GameObject::SetPosition(CellPosition p)
{
	position = p;
}

GameObject::~GameObject()
{
}