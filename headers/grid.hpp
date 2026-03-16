#pragma once
#include <vector>


class Grid
{
    public:
        Grid(int width, int height, int cSize)
        {
            rows = height / cSize;
            columns = width / cSize;
            cellSize = cSize; // zapisujemy rozmiar komorki
            
            //tworzenie i wypelnianie planszy
            cells = std:: vector<std:: vector<int>>(rows, std:: vector<int>(columns,0)); 
            //1. tworzy listę, która ma x miejsc (x = liczba kolumn) i na każdym miejscu przypisz 0
            //2. bierze apsek z x zerami i "klonuje" go w dół o y razy (y = liczba wierszy)  

        }

        void Draw();
        void Update();
        void SetValue(int row, int column, int value);
        int CountLiveNeighbours(int row, int column);
        int IsAlive(int row, int column);

    private:
        int rows;
        int columns;
        int cellSize;
        std:: vector<std:: vector<int>> cells;

};
