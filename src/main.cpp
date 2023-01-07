#include <iostream>
#include "raylib.h"

int main() {
    std::cout << "hi" << std::endl;
    InitWindow(1366, 768, "game");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();
}