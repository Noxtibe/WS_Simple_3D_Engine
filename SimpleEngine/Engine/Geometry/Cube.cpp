#include "Cube.h"
#include <Engine/ActorsComponents/MeshComponent.h>
#include <Engine/AssetsManager/Assets.h>

Cube::Cube()
{
	MeshComponent* mc = new MeshComponent(this);
	mc->setMesh(Assets::getMesh("Mesh_Cube"));
}