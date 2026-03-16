#include "grid.hpp"
#include <raylib.h>

void Grid::Draw()
{
    for(int row = 0; row < rows; row++)
    {
        for(int column = 0; column < columns; column++)
        {
            Color color;

            if(cells[row][column] == 1)
            {
                color = Color{0, 255, 0, 255};
            }

            else
            {
                color = Color{55, 55, 55, 255};  
            }

            DrawRectangle(column * cellSize, row * cellSize, cellSize - 1, cellSize - 1, color);
        }
    }
}

void Grid::SetValue(int row, int column, int value)
{
    if(row > 0 && row <= rows && column > 0 && column <= columns)
    {
        cells[row][column] = value;
    }
}

int Grid::CountLiveNeighbours(int row, int column)
{
    int neighbours = 0;

    //gorny rzad
    if(IsAlive(row - 1, column - 1)) neighbours++;
    if(IsAlive(row - 1, column))     neighbours++;
    if(IsAlive(row - 1, column + 1)) neighbours++;

    // Śsrodkowy rząd (po bokach)
    if(IsAlive(row, column - 1))     neighbours++;
    if(IsAlive(row, column + 1))     neighbours++;

    // dony rzad
    if(IsAlive(row + 1, column - 1)) neighbours++;
    if(IsAlive(row + 1, column))     neighbours++;
    if(IsAlive(row + 1, column + 1)) neighbours++;

    return neighbours;
}

int Grid::IsAlive(int row, int column)
{
    if (row < 0 || row >= rows || column < 0 || column >= columns)
    {
        return false; 
    }

    return cells[row][column] == 1;
}

void Grid::Update()
{
    std::vector<std::vector<int>> nextCells = cells;

    for(int row = 0 ; row < rows; row++)
    {
        for(int column = 0; column < columns; column++)
        {
            int CurrentState = cells[row][column];

            int LiveNeighbours = CountLiveNeighbours(row,column);

            if(CurrentState == 1)
            {
                if(LiveNeighbours == 2 || LiveNeighbours == 3)
                    nextCells[row][column] = 1;
                if(LiveNeighbours < 2)
                    nextCells[row][column] = 0;
                if(LiveNeighbours > 3)
                    nextCells[row][column] = 0;   
            }

            else
            {
                if(LiveNeighbours == 3)
                    nextCells[row][column] = 1;
            }
        }
    }
    cells = nextCells;
}
