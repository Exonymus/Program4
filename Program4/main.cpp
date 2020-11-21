//
//  main.cpp
//  Program4
//
//  Created by Игорь Аралин on 10/20/20.
//

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int length, j = 0;
    
    cout << "Введите длину массива: ";
    cin >> length;
    
    int *arr1 = new int[length];
    int *arr2 = new int[length];
    
    for (int i = 0; i < length; i++)
    {
        arr1[i] = rand() % 19 - 9; // cin >> arr1[i];
        cout << arr1[i] << " ";
        
        if (arr1[i] < 0)
        {
            arr2[j] = arr1[i];
            j++;
        }
    }
    
    cout<< endl;
    
    for (int i = 0; i < length; i++)
    {
        if (arr1[i] >= 0)
        {
            arr2[j] = arr1[i];
            j++;
        }
        cout << arr2[i] << " ";
    }
    
    cout << endl;
    
    delete[] arr1;
    delete[] arr2;
    return 0;
}
