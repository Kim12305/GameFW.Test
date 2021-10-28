#ifndef __Game__
#define __Game__
#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"

class Game 
{
  public:
  Game() {}
  ~Game() {}

  bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
  void render();
  void update();
  bool running();
  void handleEvents();
  void clean();

  private:
  SDL_Window* m_pWindow; 
  SDL_Renderer* m_pRenderer;
  bool m_bRunning;

  SDL_Texture* m_pTexture;
  //원본 사각형
  SDL_Rect m_sourceRectangle;
  //대상 사각형
  SDL_Rect m_destinationRectangle;

  SDL_Texture* m_pTexture1;
  //원본 사각형
  SDL_Rect m_sourceRectangle1;
  //대상 사각형
  SDL_Rect m_destinationRectangle1;
  
  int speed = 10;

  TextureManager m_textureManager;
  int m_currentFrame;
};

#endif