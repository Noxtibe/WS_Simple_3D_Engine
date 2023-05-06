#include "Sphere.h"
#include <Engine/ActorsComponents/MeshComponent.h>
#include <Engine/AssetsManager/Assets.h>

Sphere::Sphere() : Actor()
{
	MeshComponent* mc = new MeshComponent(this);
	mc->setMesh(Assets::getMesh("Mesh_Sphere"));
}