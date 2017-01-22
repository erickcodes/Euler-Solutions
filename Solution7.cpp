#include <iostream>

using namespace std;

bool isPrime(int x)
{
    for(int i = 2; i < x; i++)
    {
        if(x%i == 0 && i != x)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int counter = 2;
    for (int i = 1; i < 10001; i++)
    {
        do{
                counter++;
        }while(!isPrime(counter));

    }
    cout << counter << endl;
    return 0;
}
