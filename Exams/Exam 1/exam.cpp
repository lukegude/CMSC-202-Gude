#include <iostream>
using namespace std;

const int ARRAY_SIZE = 5;

void rotateArray(int *arr)
{
    int temp;
    for (int i = ARRAY_SIZE-1; i > 0; i--)
    {
        temp = arr[ARRAY_SIZE-1];
    }
}

int main()
{
    int arr[] = {0, 1, 2, 3, 4};
    rotateArray(arr);
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        cout << arr[i] << " ";
    }
}