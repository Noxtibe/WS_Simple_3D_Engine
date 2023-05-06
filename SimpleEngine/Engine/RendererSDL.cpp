/*#include "RendererSDL.h"
#include <Engine/Utilitaire/Log.h>
#include "Window.h"
#include <Engine/Geometry/Rectangle.h>
#include "SDL_image.h"
#include <Engine/AssetsManager/Texture.h>
#include <Engine/Maths/Maths.h>
#include <Engine/ActorsComponents/Actor.h>
#include <Engine/ActorsComponents/SpriteComponent.h>

RendererSDL::RendererSDL() : SDLRenderer(nullptr)
{
}

RendererSDL::~RendererSDL()
{
}

bool RendererSDL::initialize(Window& window)
{
	SDLRenderer = SDL_CreateRenderer(window.getSDLWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!SDLRenderer)
	{
		Log::error(LogCategory::Video, "Failed to create renderer");
		return false;
	}
	if (IMG_Init(IMG_INIT_PNG) == 0)
	{
		Log::error(LogCategory::Video, "Unable to initialize SDL_image");
		return false;
	}
	return true;
}

void RendererSDL::beginDraw()
{
	SDL_SetRenderDrawColor(SDLRenderer, 120, 120, 255, 255);
	SDL_RenderClear(SDLRenderer);
}

void RendererSDL::draw()
{
	drawSprites();
}

void RendererSDL::endDraw()
{
	SDL_RenderPresent(SDLRenderer);
}

void RendererSDL::drawRect(const Rectangle& rect) const
{
	SDL_SetRenderDrawColor(SDLRenderer, 255, 255, 255, 255);
	SDL_Rect SDLRect = rect.toSDLRect();
	SDL_RenderFillRect(SDLRenderer, &SDLRect);
}

void RendererSDL::addSprite(SpriteComponent* sprite)
{
	// Insert the sprite at the right place in fuction of drawOrder
	int spriteDrawOrder = sprite->getDrawOrder();
	auto iter = begin(sprites);
	for (; iter != end(sprites); ++iter)
	{
		if (spriteDrawOrder < (*iter)->getDrawOrder())
			break;
	}
	sprites.insert(iter, sprite);
}

void RendererSDL::removeSprite(SpriteComponent* sprite)
{
	auto iter = std::find(begin(sprites), end(sprites), sprite);
	sprites.erase(iter);
}

void RendererSDL::drawSprites()
{
	for (auto sprite : sprites)
		sprite->draw(*this);
}

void RendererSDL::drawSprite(const Actor& actor, const Texture& tex, Rectangle srcRect, Vector2 origin, Flip flip) const
{
	SDL_Rect dstRect;
	Vector3 position = actor.getPosition();
	float rotation = actor.getRotation();
	float scale = actor.getScale();
	// Scale the width/height by owner's scale
	dstRect.w = static_cast<int>(tex.getWidth() * scale);
	dstRect.h = static_cast<int>(tex.getHeight() * scale);
	// Center the rectangle around the position of the owner
	dstRect.x = static_cast<int>(position.x - origin.x);
	dstRect.y = static_cast<int>(position.y - origin.y);

	SDL_Rect* srcSDL = nullptr;
	if (srcRect != Rectangle::nullRect)
	{
		srcSDL = new SDL_Rect{
			Maths::round(srcRect.x),
			Maths::round(srcRect.y),
			Maths::round(srcRect.width),
			Maths::round(srcRect.height)
		};
	}

	SDL_RenderCopyEx(
		SDLRenderer,
		tex.toSDLTexture(),
		srcSDL,
		&dstRect,
		-Maths::toDegrees(rotation),
		nullptr,		// rotation point, center by default
		SDL_FLIP_NONE);

	delete srcSDL;
}

void RendererSDL::close()
{
	SDL_DestroyRenderer(SDLRenderer);
}
*/