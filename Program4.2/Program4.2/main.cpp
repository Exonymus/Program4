//
//  main.cpp
//  Program4.2
//
//  Created by Игорь Аралин on 10/20/20.
//

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
    int length, kol = 0, k = 0;
    
    cout << "Введите размерность матрицы: ";
    cin >> length;
    
    int **matrix = new int*[length];
    
    for (int i = 0; i < length; i++)
    {
        matrix[i] = new int[length];
        for (int j = 0; j < length; j++)
        {
            matrix[i][j] = rand() % 19 - 9;
            cout << setw(2) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    for (int i = 1; i < length; i++)
        {
            k = length - i;
            for (int j = k; j < length; j++)
            if (matrix[i][j] > 0) kol++;
        }
    
    cout << "Количество положительных чисел: " << kol << endl;
    
    for (int i = 0; i < length; i++)
        delete matrix[i];
    delete[] matrix;
    
    return 0;
}
