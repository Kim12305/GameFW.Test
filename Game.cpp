#include "Game.h"


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

//Texture1 생성
  SDL_Surface* pTempSurface1 = SDL_LoadBMP("Assets/rider.bmp");
  m_pTexture1 = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface1);
  SDL_FreeSurface(pTempSurface1);

  //원본상자 너비높이 설정
  //SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);
  SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);

  m_sourceRectangle.x = 0;
  m_sourceRectangle.y = 0;

  //대상상자의 너비높이 설정
  //원본과 동일하게 설정
  m_sourceRectangle.w = 50;
  m_sourceRectangle.h = 50;

  m_destinationRectangle.w = m_sourceRectangle.w;
  m_destinationRectangle.h = m_sourceRectangle.h;

  //대상상자의 위치 설정
  m_destinationRectangle.x = 0;
  m_destinationRectangle.y = 0;

  ////////////////////////

   SDL_QueryTexture(m_pTexture1, NULL, NULL, &m_sourceRectangle1.w, &m_sourceRectangle1.h);

  m_sourceRectangle1.x = 0;
  m_sourceRectangle1.y = 0;

  //대상상자의 너비높이 설정
  //원본과 동일하게 설정

  m_destinationRectangle1.w = m_sourceRectangle1.w;
  m_destinationRectangle1.h = m_sourceRectangle1.h;

  //대상상자의 위치 설정
  m_destinationRectangle1.x = 0;
  m_destinationRectangle1.y = 0;
  
  

  m_bRunning = true;
  return true;
}

void Game::update()
{

  m_destinationRectangle.x += speed;
  SDL_Delay(100);

  if((0 >= m_destinationRectangle.x)||((m_destinationRectangle.x + 50) >= 150))
  {
    speed *= -1;
    //SDL_Delay(100);
  }

}

void Game::render()
{
  SDL_RenderClear(m_pRenderer);
  
  SDL_RenderCopy(m_pRenderer, m_pTexture1, NULL, NULL);
  SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, & m_destinationRectangle);

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