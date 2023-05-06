#include "Plane.h"
#include <Engine/ActorsComponents/MeshComponent.h>
#include <Engine/AssetsManager/Assets.h>

Plane::Plane() : Actor()
{
	setScale(10.0f);
	MeshComponent* mc = new MeshComponent(this);
	mc->setMesh(Assets::getMesh("Mesh_Plane"));
}