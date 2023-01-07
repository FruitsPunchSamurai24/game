#include <iostream>
#include "raylib.h"

class Player {
public:
    Player(int x, int y, int size_) {
        pos.x = x;
        pos.y = y;
        size = size_;
        vel.x=0;
        vel.y=0;
    }

    void draw() {
        DrawRectangle(pos.x - size / 2, pos.y - size / 2, size, size, RED);
    }

    Vector2 pos;

    int size;

    Vector2 vel;

    void update()
    {
        //player movement
        if (IsKeyDown(KEY_RIGHT)) {pos.x += vel.x * GetFrameTime();vel.x++;}
        else if (IsKeyDown(KEY_LEFT)) {pos.x += vel.x * GetFrameTime();vel.x--;}
        else vel.x=0;
        if (IsKeyDown(KEY_DOWN)) {pos.y += vel.y * GetFrameTime();vel.y++;}
        else if (IsKeyDown(KEY_UP)) {pos.y += vel.y * GetFrameTime();vel.y--;}
        else vel.y=0;
    }
};

int main() {
    int width = 1366, height = 768;
    InitWindow(width, height, "game");
    //SetTargetFPS(60);

    Player p(width / 2, height / 2, 50);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        p.update();
        p.draw();
        DrawFPS(10, 10);
        EndDrawing();

        //constraints for window ends
        if(p.pos.x<(0+(p.size/2)))
            p.pos.x=width-(p.size/2);
        if(p.pos.y<(0+(p.size/2)))
            p.pos.y=height-(p.size/2);
        if(p.pos.x>(width-(p.size/2)))
            p.pos.x=0+(p.size/2);
        if(p.pos.y>(height-(p.size/2)))
            p.pos.y=0+(p.size/2);

    }

    CloseWindow();
}