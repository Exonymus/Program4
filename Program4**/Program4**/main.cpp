//
//  main.cpp
//  Program4**
//
//  Created by Игорь Аралин on 15.11.20.
//

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
    int str, stol;
    
    cout << "Введите количество строк матрицы: ";
    cin >> str;
    cout << "Введите количество столбцов матрицы: ";
    cin >> stol;
    
    int **matrix = new int*[str];
    int **matrix2 = new int*[str];
    
//    Создание исходной и доп. матрицы, заполнение исходной
    cout << "Исходная матрица:" << endl;
    for (int i = 0; i < str; i++)
    {
        matrix[i] = new int[stol];
        matrix2[i] = new int[stol];
        
        for (int j = 0; j < stol; j++)
        {
            matrix[i][j] = rand() % 101;
            matrix2[i][j] = NULL;
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
//    Подсчет элементов - заполнение доп матрицы
    for (int i = 0; i < str; i++)
        for (int j = 0; j< stol; j++)
        {
            for (int k = 0; k < stol; k++)
            {
                if (matrix[i][j] == matrix[i][k])
                {
                    matrix2[i][j]++;
                    if (matrix2[i][k] > 1 &&  j != k) {matrix2[i][k] = 1;}
                }
            }
        }
    
//    Вывод Новой матрицы
    int r = 0;
    cout << "Новая матрица:" << endl;
    for (int i = 0; i < str; i++)
    {
        r = 0;
        for (int j = 0; j < stol; j++)
        {
            if (matrix2[i][j] > 1)
            {
                for (int m = 0; m < matrix2[i][j]; m++)
                {
                    cout << setw(3) << matrix[i][j] << " ";
                    r++;
                }
            }
        }
        if (r!=0) {cout << endl;};
    }
    
    for (int i = 0; i < str; i++)
        delete matrix[i];
    delete[] matrix;
    
    return 0;
}
