#include <iostream>

using namespace std;

int main()
{
    int counter = 20;
    bool found = false;
        do{
        counter++;
        for(int i = 2;i <= 20; i++)
        {
            if(!(counter%i == 0)){
                break;
            }else if (i == 20)
            {
                found = true;
            }
        }
        }while(!found);
    cout << counter << endl;
    return 0;
}
