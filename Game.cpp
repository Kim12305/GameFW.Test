#include "Game.h"
#define SCREEN_HEIGHT 480
#define SCREEN_WIDTH 640

bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
  if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    //윈도우 생성하려는 함수
    m_pWindow = SDL_CreateWindow(title, 
        xpos,
        ypos,
        height, width,
        flags);

    if(m_pWindow != 0)
    {
      //렌더러 생성
      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

      if(m_pRenderer != 0)
      {
          SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
      }

       else
      {
        return false;
      }

    }

    else
    {
      return false;

    }
   
  }

  else //실패하면 false 출력
  {
    return false;
  }

//Texture 생성
  SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/rider.bmp");
  m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
  SDL_FreeSurface(pTempSurface);

  //원본상자 너비높이 설정
  SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);

  //대상상자의 너비높이 설정
  //원본과 동일하게 설정
  m_destinationRectangle.w = m_sourceRectangle.w;

  m_destinationRectangle.h = m_sourceRectangle.h;

  //원본상자 대상상자의 위치 설정
  m_destinationRectangle.x = m_sourceRectangle.x = 0;

  m_destinationRectangle.y = m_sourceRectangle.y = 0;
  
  

  m_bRunning = true;
  return true;
}

void Game::update()
{

}

void Game::render()
{
  SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
  SDL_RenderClear(m_pRenderer);

  SDL_Rect fillRect = {SCREEN_WIDTH/4, SCREEN_HEIGHT/4, SCREEN_WIDTH/2, SCREEN_HEIGHT/2};
  SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
  SDL_RenderFillRect(m_pRenderer, &fillRect);

  SDL_Rect outlineRect = {SCREEN_WIDTH/6, SCREEN_HEIGHT/6, SCREEN_WIDTH* 2/3, SCREEN_HEIGHT* 2/3};
  SDL_SetRenderDrawColor(m_pRenderer, 0, 255, 0, 255);
  SDL_RenderDrawRect(m_pRenderer, &outlineRect);

  SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 255, 255);
  SDL_RenderDrawLine(m_pRenderer, 0, SCREEN_HEIGHT/2, SCREEN_WIDTH, SCREEN_HEIGHT/2);

  SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 0, 255);
  for(int i = 0; i < SCREEN_HEIGHT; i += 4)
  {
    SDL_RenderDrawPoint(m_pRenderer, SCREEN_WIDTH/2, i);
  }






 // SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, & m_destinationRectangle);
  SDL_RenderPresent(m_pRenderer);

}

bool Game::running()
{
  return m_bRunning;
}

void Game::handleEvents()
{
  SDL_Event event;

  if(SDL_PollEvent(&event))
  {
    switch (event.type)
    {
      case SDL_QUIT:
      m_bRunning = false;
      break;

      default:
      break;
    }
  }
}

void Game::clean()
{
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}