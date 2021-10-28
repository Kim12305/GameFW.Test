#include "TextureManager.h"

TextureManager* TextureManager::s_pInstance = 0;

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* pRenderer)
{
  SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
  if(pTempSurface == 0)
  {
    return false;
  }

  SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
  SDL_FreeSurface(pTempSurface);

  if(pTexture != 0)
  {
    m_textureMap[id] = pTexture;

    return true;
  }

  return false;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
  SDL_Rect strRect;
  SDL_Rect destRect;

  strRect.x = 0;
  strRect.y = 0;
  strRect.w = destRect.w = width;
  strRect.h = destRect.h = height;
  destRect.x = x;
  destRect.y = y;

  SDL_RenderCopyEx(pRenderer, m_textureMap[id], &strRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
  SDL_Rect strRect;
  SDL_Rect destRect;

  strRect.x = width* currentFrame;
  strRect.y = height* currentRow;
  strRect.w = destRect.w = width;
  strRect.h = destRect.h = height;
  destRect.x = x;
  destRect.y = y;

  SDL_RenderCopyEx(pRenderer, m_textureMap[id], &strRect, &destRect, 0, 0, flip);
}