//
//  main.cpp
//  Program4.3
//
//  Created by Игорь Аралин on 14/20/20.
//

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
    int length, str_max = 0, str_min = 0;
    float min = 10, max = -10, k;
    
    cout << "Введите размерность матрицы: ";
    cin >> length;
    
    float **matrix = new float*[length];
    
    for (int i = 0; i < length; i++)
    {
        matrix[i] = new float[length];
        for (int j = 0; j < length; j++)
        {
            matrix[i][j] = rand() % 19 - 9;
            cout << setw(2) << matrix[i][j] << " ";
            
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
                str_max = i;
            }
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
                str_min = i;
            }
        }
        cout << endl;
    }
    
    cout << "Максимальное число: " << max << ", номер строки: " << str_max + 1 << endl;
    cout << "Минимальное число: " << min << ", номер строки: " << str_min + 1 << endl;
    
    if (str_max != str_min)
    {
        cout << "Новая матрица: " << endl;
        for (int i = 0; i < length; i++)
            {
                k = matrix[str_max][i];
                matrix[str_max][i] = matrix[str_min][i];
                matrix[str_min][i] = k;
            }
        for (int i =  0; i < length; i++)
            {
                for (int j = 0; j < length; j++)
                {
                    cout << setw(2) << matrix[i][j] << " ";
                }
                cout << endl;
            }
    }
    else {cout << "Макс. и мин. число находятся в одной строке" << endl;}

    for (int i = 0; i < length; i++)
        delete matrix[i];
    delete[] matrix;
    
    return 0;
}
