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
  SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/animate.bmp");
  m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
  SDL_FreeSurface(pTempSurface);


  //원본상자 너비높이 설정
  

  m_sourceRectangle.x = 0;
  m_sourceRectangle.y = 0;

  //대상상자의 너비높이 설정
  //원본과 동일하게 설정
  m_sourceRectangle.w = 120;
  m_sourceRectangle.h = 82;

  m_destinationRectangle.w = m_sourceRectangle.w;
  m_destinationRectangle.h = m_sourceRectangle.h;

  //대상상자의 위치 설정
  m_destinationRectangle.x = m_sourceRectangle.x = 0;
  m_destinationRectangle.y= m_sourceRectangle.y = 0;

  m_bRunning = true;
  return true;
}

void Game::update()
{

  //애니메이션은 이것만 추가
  m_sourceRectangle.x = 128 * ((SDL_GetTicks() / 100) % 6);

}

void Game::render()
{
  SDL_RenderClear(m_pRenderer);

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