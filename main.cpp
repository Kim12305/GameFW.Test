#include <SDL.h>

//윈도우 관련 정보를 저장하는 구조체
SDL_Window* g_pWindow = 0; 
//렌더링 상태를 포함하는 구조체
SDL_Renderer* g_pRenderer = 0;
bool g_bRunning = false;

bool init(const char* title, int xpos, int ypos,
          int height, int width, int flags)
{
  if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
  {
    //윈도우 생성하려는 함수
    g_pWindow = SDL_CreateWindow(title, 
        xpos,
        ypos,
        height, width,
        flags);

    if(g_pWindow != 0)
    {
      //렌더러 생성
      g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
    }

  }

  else //실패하면 false 출력
  {
    return false;
  }

  SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

  return true;
}

void render()
{
  SDL_RenderClear(g_pRenderer);
  SDL_RenderPresent(g_pRenderer);
}

int main(int argc, char* args[])
{
  if(init("SDL1", 
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    640, 480,
    SDL_WINDOW_SHOWN))

    g_bRunning = true;
  
  else return 1;

  while (g_bRunning)
  {
    render();
  }
  
  //SDL_Delay(5000); //5초대기
  SDL_Quit();

  return 0;

}






