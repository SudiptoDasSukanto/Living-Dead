#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_mixer.h>
#include<bits/stdc++.h>
using namespace std;
#define WINDOW_WIDTH (1280)
#define WINDOW_HEIGHT (720)
#define SCROLL_SPEED (300)


int main(int agr, char* args[])
{
     if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );

    }
  //  Mix_Init();
    Mix_Chunk *music=Mix_LoadWAV("/home/sukanto/Desktop/Project/Orin/res/intro.mp3");
    Mix_Chunk *mouse_click=Mix_LoadWAV("/home/sukanto/Desktop/Project/Orin/res/mouseclick.mp3");
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER)>0)
    {
        printf("video and timer: %s\n",SDL_GetError());
    }
    if (!(IMG_Init(IMG_INIT_PNG|IMG_INIT_JPG)))
        printf("image: %s\n",SDL_GetError());

    printf("Initialization Complete\n");

    SDL_Window* win = SDL_CreateWindow("THE LIVING DEAD",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);

    if (!win)
    {
        printf("window: %s\n",SDL_GetError());
        SDL_Quit();
        return 1;
    }
    // Mix_PlayChannel(-1,music,0);
    Uint32 render_flags = SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC;
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);

    if (!rend)
    {
        printf("renderer: %s\n",SDL_GetError());
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    // SDL_Surface* surface = IMG_Load("res/man1.png");

    // if (!surface)
    // {
    //     printf("Redbar Surface Error: %s\n",IMG_GetError());
    //     SDL_DestroyRenderer(rend);
    //     SDL_DestroyWindow(win);
    //     SDL_Quit();
    //     return 1;
    // }

    // SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);

    // SDL_FreeSurface(surface);
    //  SDL_RenderCopy(rend, tex, NULL, NULL);
    //  SDL_RenderPresent(rend);
    //  SDL_Delay(3000);
    SDL_Texture *tex1,*tex2,*coin,*tex4;
    SDL_Surface* surface=IMG_Load("/home/sukanto/Desktop/Project/Orin/res/charli.png");
    if (!surface)
    {
        printf("start Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    tex1=SDL_CreateTextureFromSurface(rend,surface);
   // SDL_SetTextureColorMod(tex1,200,255,255);
    SDL_FreeSurface(surface);

    surface=IMG_Load("/home/sukanto/Desktop/Project/Orin/res/tree.png");
    if (!surface)
    {
        printf("start Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    tex2=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);

    surface=IMG_Load("/home/sukanto/Desktop/Project/Orin/res/moon.png");
     if (!surface)
    {
        printf("start Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    SDL_Texture *moon_tex = SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);

    surface=IMG_Load("res/coin.png");
    if (!surface)
    {
        printf("start Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    //SDL_SetColorKey(surface,SDL_TRUE,SDL_MapRGB(surface->format,255,255,255));
    coin = SDL_CreateTextureFromSurface(rend,surface);
    //SDL_SetTextureColorMod(tex3,200,200,200);
    SDL_FreeSurface(surface);

    surface = IMG_Load("/home/sukanto/Desktop/Project/Orin/res/start.png");
    if (!surface)
    {
        printf("start Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    SDL_Texture *start_tex0 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    if (!start_tex0)
    {
        printf("replayTexture %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    

     surface=IMG_Load("/home/sukanto/Desktop/Project/Orin/res/wallpapersden.com_cod-vanguard-zombies_2048x1152(1).png");
     if (!surface)
    {
        printf("start Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    SDL_Texture *First_Back_tex0=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);

    surface=IMG_Load("/home/sukanto/Desktop/Project/Orin/res/SecBack.png");
     if (!surface)
    {
        printf("start Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    SDL_Texture *Sec_Back_tex0=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);

    surface=IMG_Load("/home/sukanto/Desktop/Project/Orin/res/NewGame.png");
     if (!surface)
    {
        printf("start Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    SDL_Texture *NewGame_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);

    surface=IMG_Load("/home/sukanto/Desktop/Project/Orin/res/instruction.png");
     if (!surface)
    {
        printf("start Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    SDL_Texture *instruction_tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("res/gameover.jpeg");
    if (!surface)
    {
        printf("Green rectangle Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

     SDL_Texture *gameover_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    if (!gameover_tex)
    {
        printf("Green Rectangle Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    SDL_Rect gameover_rect;
    gameover_rect.w = 400;
    gameover_rect.h = 300;
    gameover_rect.x = (WINDOW_WIDTH - gameover_rect.w) / 2;
    gameover_rect.y = (WINDOW_HEIGHT - gameover_rect.h) / 2 - 150;


    surface = IMG_Load("res/replay.png");
    if (!surface)
    {
        printf("replay Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    SDL_Texture *replay_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    if (!replay_tex)
    {
        printf("replayTexture %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }



    SDL_Rect replay_rect;
    replay_rect.w = 300;
    replay_rect.h = 150;
    replay_rect.x = (WINDOW_WIDTH - replay_rect.w) / 2;
    replay_rect.y = (WINDOW_HEIGHT - replay_rect.h) / 2 + 100;

    SDL_Rect dest,dest1[100],dest2,dest22,dest_coin,newgame;
   

  
    SDL_QueryTexture(tex2, NULL, NULL, &dest2.w, &dest2.h);
    SDL_QueryTexture(tex2, NULL, NULL, &dest22.w, &dest22.h);

    SDL_QueryTexture(coin, NULL, NULL, &dest_coin.w, &dest_coin.h);
    SDL_QueryTexture(NewGame_tex, NULL, NULL, &newgame.w, &newgame.h);

    newgame.x = 475 ;
    newgame.y = 140;


    // for(int i=0; i<100; i++)
    // {
    //     dest1[i].w = (int) dest1[i].w * 0.8;
    //     dest1[i].h = (int) dest1[i].h * 0.8;
    //     dest1[i].x = 0;
    //     dest1[i].y = 0;
    // }
    dest2.w=1280;
    dest2.h=720;
    dest2.x=0;
    dest2.y=0;
    dest22.w=1280;
    dest22.h=720;
    dest22.x=-dest22.w;
    dest22.y=0;
    dest_coin= {WINDOW_WIDTH,550,(int)(dest_coin.w*.2),(int)(dest_coin.h*.2)};


      SDL_Rect  playerRect;//rect for a single frame of the sprite sheet
    SDL_Rect playerPosition;//rect for the whole sprite sheet
    //ei rec(square) er moddher kothao texture (runman) load hobe

    

   
    int textureWidth,textureHeight;
    int frameH,frameW;
    SDL_QueryTexture(tex1,NULL,NULL,&textureWidth,&textureHeight);
    frameH=textureHeight/2;
    frameW=textureWidth/4;
    playerRect.w=frameW;
    playerRect.h=frameH;
    playerRect.x=0;
    playerRect.y=0;
    

    playerPosition.x=0;
    playerPosition.y=500;
    playerPosition.w=150;
    playerPosition.h=150;//



    float x_pos =0;

    SDL_Event e;
    int cnt[100]= {},flag[100]= {},one[100]= {};
    int i=0;
    bool start = 1 ;
    int main_game = 0 ;
    int Next_Back = 0 ;
    int gameover = 0 ;
    bool Running=true;
    while(Running)
    {
        
        while( SDL_PollEvent(&e)){
             if(e.type==SDL_QUIT)
             Running =false;
            else if(e.type==SDL_KEYDOWN)
            {
                if(e.key.keysym.sym==SDLK_DOWN)
                {
                    playerRect.x+=frameW;
                    if(playerRect.x+frameW>=textureWidth){

                    playerRect.y+=frameH;
                    playerRect.x=0;
                    
                    }
                  if (playerRect.y + playerRect.h >= textureHeight)
				playerRect.y = 0;
                     playerPosition.y+=4;
                }
                else if(e.key.keysym.sym==SDLK_UP)
                {
                    dest.y-=10;
                      playerRect.x+=frameW;
                    if(playerRect.x+frameW>=textureWidth){

                    playerRect.y+=frameH;
                    playerRect.x=0;}
                  if (playerRect.y + playerRect.h >= textureHeight)
				playerRect.y = 0;
                     playerPosition.y-=4;
                }
                else if(e.key.keysym.sym==SDLK_RIGHT)
                {
                    playerRect.x+=frameW;
                    if(playerRect.x+frameW>=textureWidth){

                    playerRect.y+=frameH;
                    playerRect.x=0;}
                  if (playerRect.y + playerRect.h >= textureHeight)
				playerRect.y = 0;
                playerPosition.x+=4;
                }
                else if(e.key.keysym.sym==SDLK_LEFT)
                {
                    playerRect.x+=frameW;
                    if(playerRect.x+frameW>=textureWidth){

                    playerRect.y+=frameH;
                    playerRect.x=0;}
                  if (playerRect.y + playerRect.h >= textureHeight)
				playerRect.y = 0;
                playerPosition.x-=4;
                    // dest.x-=5;
                    // if(dest.x<=WINDOW_WIDTH)
                    // dest.x=WINDOW_WIDTH;
                    // x_pos-=5;
                }
                // else if(e.key.keysym.sym==SDLK_SPACE)
                // {
                //     cnt[i]=1;
                //     i++;
                //     if(i==100)
                //     {
                //         i=0;
                //     }
                // }

            }
            
        }
        if(main_game)
        {


            // SDL_SetRenderDrawColor(rend,255,255,255,0);
            SDL_RenderClear(rend);


            SDL_RenderCopy(rend, moon_tex, NULL,NULL);
            SDL_RenderCopy(rend, tex2, NULL,&dest2);
            SDL_RenderCopy(rend, tex2, NULL,&dest22);
            SDL_RenderCopy(rend, tex1, &playerRect, &playerPosition);
          //  SDL_RenderCopy(rend, tex1, NULL, NULL);
            SDL_RenderCopyEx(rend,coin,0,&dest_coin,0,0,SDL_FLIP_HORIZONTAL);

             dest_coin.x-=4;
            // dest.x+=3 ;


// s--;
// if(s<dest2.w)
//  s=0;
            dest2.x+=3;
            dest22.x+=3;
            if(dest2.x>=WINDOW_WIDTH)
            {
                dest2.x=0;
                dest22.x=-dest22.w;
            }
            if(dest_coin.x<=-400)
            {
                dest_coin.x=WINDOW_WIDTH;
            }

            // for(int j=0; j<=99; j++)
            // {
            //     if(cnt[j])
            //         cout<<"cnt"<<j<<" "<<cnt[j]<<endl;

                // if(cnt[j])
                // {
                //     if(!one[j])
                //         dest1[j].x=(int)x_pos+270;
                //     one[j]=1;

                //     if(!flag[j])
                //     {
                //         dest1[j].y=dest.y+73;
                //         flag[j]=1;
                //     }

                //     SDL_RenderCopy(rend, tex1, NULL, &dest1[j]);

                //     dest1[j].x+=6;

                //     if(dest1[j].x>=1680)
                //     {
                //         cnt[j]=0;
                //         flag[j]=0;
                //         one[j]=0;
                //     }
                // }
            // }
            // if(x_pos>=WINDOW_WIDTH)
            // {
            //     x_pos=-400;
            // }
            if(dest.y<=380)
            {
                dest.y=WINDOW_HEIGHT*0.45;
            }

             if(playerPosition.x>=WINDOW_WIDTH)
            {
                //SDL_Delay(1500);
                gameover=1;
                main_game=0;
                // playerPosition.y=100;
            }
           
            SDL_RenderPresent(rend);
            //SDL_Delay(1000/40);

                 
        }
        else if(start)
        {
            
            SDL_RenderClear(rend);
            
            SDL_RenderCopy(rend,First_Back_tex0, NULL, NULL);
          
            SDL_RenderPresent(rend);

            // int mousx, mousy;
            // int button = SDL_GetMouseState(&mousx, &mousy);
            //printf("%d %d\n", mousx, mousy);

            // if (button & SDL_BUTTON(1))
            // {
            //     if (mousx >= start_rect.x && mousx <= (start_rect.x + start_rect.w) && mousy >= start_rect.y && mousy <= (start_rect.y + start_rect.h))
            //     {
            //         // Mix_PlayChannel(-1,mouse,4);
            //         // SDL_Delay(1000);
            //         main_game=1;
            //         start=0;

            //     }
            // }
            SDL_Delay(3000);
            
            start = 0;
            Next_Back = 1 ;

           // SDL_Quit();
        }
        else if(Next_Back)
        {
            // Mix_PlayChannel( -1, replay, 0 );
            // Mix_PlayChannel(-1,menu,0);
            SDL_RenderClear(rend);
            //SDL_RenderCopy(rend,fontTex,NULL,&textRect);
            //Mix_PlayChannel(-1,music,0);
            SDL_RenderCopy(rend,Sec_Back_tex0, NULL, NULL);
            SDL_RenderCopy(rend,NewGame_tex, NULL, &newgame);
            SDL_RenderCopy(rend,instruction_tex, NULL, NULL);
           // SDL_RenderCopy(rend,start_tex0, NULL, &start_rect);
            SDL_RenderPresent(rend);

            int mousx, mousy;
            int button = SDL_GetMouseState(&mousx, &mousy);
            //printf("%d %d\n", mousx, mousy);

            if (button & SDL_BUTTON(SDL_BUTTON_LEFT))
            {
                if (mousx >= newgame.x && mousx <= (newgame.x + newgame.w) && mousy >= newgame.y && mousy <= (newgame.y + newgame.h))
                {
                   Mix_PlayChannel(-1,mouse_click,0);
                 //    SDL_Delay(1000);


                    main_game=1;
                    Next_Back = 0 ;

                }
            }
           // SDL_Delay(6000);
            // main_game=1;
            // start = 0;
            // Next_Back =0 ; ;

           // SDL_Quit();
        }

        else if(gameover==1)
        {
            //Mix_PlayChannel( -1, replay1, 0 );
            SDL_RenderClear(rend);
            SDL_RenderCopy(rend, gameover_tex, NULL, &gameover_rect);
            SDL_RenderCopy(rend, replay_tex, NULL, &replay_rect);
            SDL_RenderPresent(rend);

            int mousex, mousey;
            int buttons = SDL_GetMouseState(&mousex, &mousey);

            if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
            {
                if (mousex >= replay_rect.x && mousex <= (replay_rect.x + replay_rect.w) && mousey >= replay_rect.y && mousey <= (replay_rect.y + replay_rect.h))
                {
                     Mix_PlayChannel(-1,mouse_click,0);
                    // y_pos=550.0;
                    playerPosition.x=400;
                    playerPosition.y=500;
                    playerRect.x=playerRect.y=0;

                    // y_pos1=580.0;
                    // boy2_pos.x=500;
                    // boy2_pos.y=550;
                    // boy2.x=boy2.y=0;


                    Next_Back =1 ;
                    gameover==0;

                }
            }
        }

    }

   
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_DestroyTexture(tex1);

    SDL_DestroyTexture(tex1);
    
    SDL_Quit();
    return 0;
}


