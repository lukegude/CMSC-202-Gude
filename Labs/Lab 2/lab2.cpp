#include <iostream>
using namespace std;

int sumOfInts()
{
    int num_of_integers;
    int sum = 0;
    cout << "How many integers would you like to add together?\n";
    cin >> num_of_integers;
    for (int i = 0; i < num_of_integers; i++)
    {
        int currentNum;
        cout << "Enter an integer: ";
        cin >> currentNum;
        sum += currentNum;
    }
    cout << "Sum: " << sum << endl;
    return sum;
}

void greaterThanTen(int num)
{
    if (num > 10)
    {
        cout << num << " is greater than 10!\n";
    }
    else
    {
        cout << num << " is less than 10!\n";
    }
}

int main()
{
    greaterThanTen(sumOfInts());
}