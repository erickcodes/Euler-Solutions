#include <iostream>

using namespace std;

int main()
{
    int counter = 0;
    for(int i = 0; i < 1000; i++)
    {
        if(i%3 == 0 || i%5 == 0)
        {
            counter = counter + i;
         }
    }
    cout << "Answer : " << counter<< endl;
    return 0;
}
