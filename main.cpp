#include "raylib.h"
#include <iostream>
#include "point.cpp"

using namespace std;

point p[noPoints];
pair<pair<float,float>,pair<float,float>> r;
float val,penergy,inc;
string te = "T.E:                 J";

int main()
{   
    SetTargetFPS(fps);
    InitWindow(screenWidth, screenHeight, "collision");
    while (!WindowShouldClose())
    {
        if(IsKeyPressed(KEY_SPACE))paused=!paused;
        BeginDrawing();
        ClearBackground(BLACK);
        float energy = 0;
        
        for (int i = 0; i < noPoints; i++)
        {   
            DrawCircle(p[i].x,p[i].y,p[i].m,p[i].color);
            
            if(!paused){
                if(p[i].x>=screenWidth)p[i].xdir = -p[i].xdir;
                if(p[i].x<=0)p[i].xdir = -p[i].xdir;
                if(p[i].y>=screenHeight)p[i].ydir = -p[i].ydir;
                if(p[i].y<=0)p[i].ydir = -p[i].ydir;
                
                for (int j = 0; j < noPoints; j++)
                {
                    if(i!=j){
                        if(CheckCollisionCircles(
                            {p[i].x,p[i].y},p[i].m,
                            {p[j].x,p[j].y},p[j].m)){

                            r = resolve(p[i],p[j]);

                            p[i].xdir = r.first.first;
                            p[i].ydir = r.first.second;
                            p[j].xdir = r.second.first;
                            p[j].ydir = r.second.second;

                        }
                    }
                }
                
                p[i].x+=p[i].xdir;
                p[i].y+=p[i].ydir;

                penergy = 0.5 * (pow(abs(p[i].xdir), 2) + pow(abs(p[i].ydir), 2));

                
                float energyRatio = fmin(penergy / threshold, 1.0f);  
                p[i].color = {
                    (unsigned char)(energyRatio * 255),             //R
                    0,                                              //G
                    (unsigned char)((1.00f - energyRatio) * 255),   //B
                    255                                  
                };
                energy += penergy;
                    
            }
            DrawRectangle(10,10,200,25,BLACK);
            DrawText(std::to_string(energy).c_str(),60,10,20,WHITE);
            DrawText(te.c_str(),10,10,20,WHITE);
            
            
        }

        EndDrawing();
    }

    CloseWindow();


    return 0;
}
