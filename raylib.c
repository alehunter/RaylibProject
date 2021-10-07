#include "raylib.h"
#include <math.h>
#include <stdio.h>

float distance;

/*modified the CheckCollisionCircles because using two radius
didn't make much sense. 
float radius is input of how close centers of circle can get to each other
*/
bool CirclesCollided(Vector2 center1, Vector2 center2, float radius)
{
    bool collision = false;

    float dx = center2.x - center1.x;      // X distance between centers
    float dy = center2.y - center1.y;      // Y distance between centers

    distance = sqrtf(dx*dx + dy*dy); // Distance between centers

    if (distance <= (radius)) collision = true;

    return collision;
}
void deleteCircleV(Vector2 circle){
    
}


int main(void)
{
	const int screenWidth = 800;
	const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib");

	Vector2 circle1Position = {(float)screenWidth/2, (float)screenHeight/2};
    float circle1Radius = 20;
    float circle2Radius = 20;
    Vector2 circle2Position = {(float)screenWidth/3, (float)screenHeight/3};

    SetTargetFPS(60);


    while(!WindowShouldClose()){
        //Update for Circle 1 (ArrowKeys)
        if (IsKeyDown(KEY_RIGHT)) circle1Position.x += 2.0f;
        if (IsKeyDown(KEY_LEFT)) circle1Position.x -= 2.0f;
        if (IsKeyDown(KEY_UP)) circle1Position.y -= 2.0f;
        if (IsKeyDown(KEY_DOWN)) circle1Position.y += 2.0f;

        //Update for Circle 2 (WASD)
        if (IsKeyDown(KEY_D)) circle2Position.x += 2.0f;
        if (IsKeyDown(KEY_A)) circle2Position.x -= 2.0f;
        if (IsKeyDown(KEY_W)) circle2Position.y -= 2.0f;
        if (IsKeyDown(KEY_S)) circle2Position.y += 2.0f;


    
        //Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("move the ball with arrow keys", 450, 10, 20, MAROON);
            
            //Drawing Circles
            DrawCircleV(circle1Position, 20, MAROON);
            DrawCircleV(circle2Position, 20, LIME);
            
            if(CirclesCollided(circle1Position, circle2Position, 40))
            {
                
                
                DrawText("COLLISION", 10, 10, 20, BLUE);

            }

            


        EndDrawing();



    }

	CloseWindow();




	return 0;
}