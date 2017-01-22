#include <iostream>

using namespace std;

int rt(int x)
{
    return x*x;
}

bool check(int a, int b,int c){
    return ((a+b+c) == 1000 && a < b && b < c && (a*a + b*b == c*c));
}

int main()
{
    int a,b,c ;
    c = 0;
    b = 0;
    a = 0;
    for(a = 0;(a+b+c) <= 1000;a++){
        for(b = 0;(a+b+c) <= 1000;b++){
            for(c = 0;(a+b+c) <= 1000;c++){
                if(check(a,b,c)){
                    cout << a*b*c << endl;
                    cout << a <<"\t" << b<< "\t" << c << endl;
                    return 0;
                }
            }
            c = 0;
        }
        b = 0;
    }

    return 0;
}

