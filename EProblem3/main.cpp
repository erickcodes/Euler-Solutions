#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long number = 600851475143;
    vector<long long> primes;
    long long rest = number;

    for(long long i = 2; rest > i; i++)
    {
        if(rest%i == 0)
        {
            primes.push_back(i);
            rest = rest/i;
        }
    }
    cout << (int) rest << endl;
    return 0;
}
