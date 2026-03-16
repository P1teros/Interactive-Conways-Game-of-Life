#include <raylib.h>
#include "grid.hpp"

int main()
{
    Color GREY = { 29, 29, 29, 255};
    const int Window_Width = 750;
    const int Window_Height = 750;
    const int Cell_Size = 25;
    int FPS = 10;

    InitWindow(Window_Width, Window_Height, "Conway's Game of Life");
    SetTargetFPS(FPS);
    Grid grid{Window_Width, Window_Height, Cell_Size};

    while(WindowShouldClose() == false)
    {
        grid.Update();
        // drawing
        BeginDrawing();
        ClearBackground(GRAY);

        grid.Draw();

        EndDrawing();
    }

    CloseWindow();
}
