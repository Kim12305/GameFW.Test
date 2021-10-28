#pragma once
#include "SDL.h"
#include <vector>
#include "SDL_image.h"
#include <iostream>

#include "TextureManager.h"
#include "GameObject.h"
#include "SDLGameObject.h"
#include "Player.h"
#include "Enemy.h"


class Game 
{
  private:
  Game() {}
  static Game* s_pInstance;

  public:
  static Game * Instance()
  {
    if(s_pInstance == 0)
    {
      s_pInstance = new Game();
      return s_pInstance;
    }

    return s_pInstance;
  }

  SDL_Renderer* getRenderer() const {return m_pRenderer;}

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

  int speed = 10;
  int m_currentFrame;
  
  std::vector<GameObject*> m_gameObjects;
   
};
typedef Game TheGame;

