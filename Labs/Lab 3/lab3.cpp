#include <iostream>
using namespace std;

int flipEven(int array[], int size)
{
    int evenNumbers = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] % 2 == 0 && array[i] != 0)
        {
            evenNumbers++;
            if (array[i] > 0)
            {
                array[i] -= (array[i] * 2);
            }
            else if (array[i] < 0)
            {
                array[i] += (-array[i] * 2);
            }
}
    }
    return evenNumbers;
}

int main()
{
    int num_array[100];
    int num;
    int num_array_index = 0;
    while (num != 0)
    {
        cout << "Enter a number (0 when done): ";
        cin >> num;
        num_array[num_array_index] = num;
        num_array_index++;
    }
    cout << "Original array: ";
    for (int i = 0; i < num_array_index - 1; i++)
    {
        cout << num_array[i] << " ";
    }
    cout << "\nThere are " << flipEven(num_array, num_array_index) << " even numbers in the array\n";
    cout << "Modified array: ";
    for (int i = 0; i < num_array_index - 1; i++)
    {
        cout << num_array[i] << " ";
    }
    cout << endl;
}