#include <iostream>

using namespace std;

int main()
{
    int sumSquare = 0;
    int squareSum = 0;
    for(int i = 1; i <= 100; ++i)
    {
        sumSquare = sumSquare + (i*i);
        squareSum = squareSum + i;
    }
    cout << ( squareSum*squareSum - sumSquare ) << endl;
    return 0;
}
