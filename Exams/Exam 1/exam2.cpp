#include <iostream>
using namespace std;

const int ARR_SIZE = 10;

int outOfOrder(double *arrScore, int ARR_SIZE);
int main()
{
    double arrScore[] = {1.2, 2.1, 3.3, 3.5, 4.5, 7.9, 5.4, 8.7, 9.9, 1.0};
}

int outOfOrder(double *arrScore, int ARR_SIZE)
{
    bool isNotOrdered = false;
    for (int i = 0; i < ARR_SIZE - 1; i++)
    {
        if (arrScore[i] < arrScore[i + 1])
        {
        }
        else
        {
            isNotOrdered = true;
            return arrScore[i + 1];
        }
    }
    if (isNotOrdered == false)
    {
        return -1;
    }
}
