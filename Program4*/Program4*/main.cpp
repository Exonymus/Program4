//
//  main.cpp
//  Program4*
//
//  Created by Игорь Аралин on 14.11.20.
//

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
    int length, k = 0;
    
    cout << "Введите размерность матрицы: ";
    cin >> length;
    
    int **matrix = new int*[length];
    int *matrix2 = new int[length];
    
    for (int i = 0; i < length; i++)
    {
        matrix[i] = new int[length];
        for (int j = 0; j < length; j++)
        {
            matrix[i][j] = rand() % 19 - 9;
            cout << setw(2) << matrix[i][j] << " ";
            
            if (j>0)
            {
                if (matrix[i][j] == matrix[i][j - 1])
                {matrix2[i]++;} else {matrix2[i] = 1;}
            }
        }
        
        if (i>0)
        {
            if (matrix2[i] > matrix2[i-1])
            {
                k = matrix2[i];
            }
        }
        cout << endl;
    }
    
    if (k!= 0)
    {
        cout << "Строка с самой длинной последовательностью: " << k+1 << endl;
        cout << "Максимум одинаковых элементов: " << matrix2[k] << endl;
    } else
    {
        cout << "Во всех строках элементы не образуют последовательности" << endl;
    }
    
    for (int i = 0; i < length; i++)
        delete matrix[i];
    delete[] matrix;
    delete[] matrix2;
    
    return 0;
}
