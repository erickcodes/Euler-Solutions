#include <iostream>

using namespace std;

int main()
{
    int limit = 4000000;
    int sum = 0;
    int i1 = 1;
    int i2 = 1;

    while (i2 < limit)
        {
            int temp2;
            temp2 = i2;
            i2 += i1;
            i1 = temp2;
            if(i2%2 == 0)
            {
                sum += i2;
            }
        }
    cout << sum << endl;
    return 0;
}
