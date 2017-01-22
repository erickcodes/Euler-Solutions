#include <iostream>

using namespace std;

bool isPrime(long long x)
{
    for(long long i = 2; i < x; i++)
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
    long long counter = 2;
    long long sum = 2;
    do{
        do{
            counter++;
        }while(!isPrime(counter));
        if(counter < 2000000){sum += counter;}
    }while(counter < 2000000);

    cout << sum << endl;
    return 0;
}
