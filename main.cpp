#include <raylib.h>
#include "grid.hpp"

int main()
{
    Color GREY = { 29, 29, 29, 255};
    const int Window_Width = 750;
    const int Window_Height = 750;
    const int Cell_Size = 25;
    int FPS = 10;

    bool IsRunning = false;

    InitWindow(Window_Width, Window_Height, "Conway's Game of Life");
    SetTargetFPS(FPS);
    Grid grid{Window_Width, Window_Height, Cell_Size};

    while(WindowShouldClose() == false)
    {
        if(IsKeyPressed(KEY_SPACE))
        {
            IsRunning = true;
        }
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT) == true)
        {
            int x, y;
            x = GetMouseX();
            y = GetMouseY();
            int clicolumn, clirow;

            clicolumn = x / Cell_Size;
            clirow = y / Cell_Size;

            grid.SetValue(clirow, clicolumn, 1);
        }
        if(IsRunning == true)
        {
            grid.Update();
        }

        // drawing
        BeginDrawing();
        ClearBackground(GRAY);

        grid.Draw();

        EndDrawing();
    }

    CloseWindow();
}
