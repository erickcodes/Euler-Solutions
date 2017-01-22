#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string to_string(int i)
{
    stringstream ss;
    ss << i;
    return ss.str();
}

bool isPalindrone(int numb)
{
    string digits = to_string(numb);
    for(int i=0; i<digits.length(); ++i)
        {
            if(digits[i] != digits[digits.length() - 1 - i])
            {
                return false;
            }
        }
        return true;
}


int main()
{
    int palindrone = 0;
    for(int a = 100; a < 999; a++)
    {
        for(int b = 100; b < 999; b++)
        {
            if(isPalindrone(a*b) && (a*b > palindrone))
                {
                    palindrone = a*b;
                }
        }
    }
    cout << palindrone << endl;
    return 0;
}


