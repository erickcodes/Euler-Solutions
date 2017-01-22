#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <stdlib.h>


#define datatype int


/*

*/

using namespace std;

void Answer(const string &s)
{
    HWND hwnd = GetDesktopWindow();
	OpenClipboard(hwnd);
	EmptyClipboard();
	HGLOBAL hg=GlobalAlloc(GMEM_MOVEABLE,s.size()+1);
	if (!hg){
		CloseClipboard();
		return;
	}
	memcpy(GlobalLock(hg),s.c_str(),s.size()+1);
	GlobalUnlock(hg);
	SetClipboardData(CF_TEXT,hg);
	CloseClipboard();
	GlobalFree(hg);
	cout << s << endl;
}

long long bilgi(long n) {
        long long result = n;
        if (result <= 1){
            return 1;
        }

        if (result % 2 == 0) {
            return result/2;
            }
        return 3*result+1;
    }


int main()
{
    const long long number = 837800;
    long long highest = 0;
    long long winner = 0;


    for(long long i = 2; i < number; i++)
    {
        int counter = 1;
        long long sequence = i;

        while(sequence != 1)
        {
            //cout << sequence << " ";
            sequence = bilgi(sequence);
            counter++;
        }
        //cout << " = " << counter <<endl;

        if(highest < counter)
        {
            highest = counter;
            winner = i;
            cout << i << "\t";
            cout << highest<< endl;
        }
    }
    int sequence = 837799;
    int  counter = 1;
    while(sequence != 1)
        {
            sequence = bilgi(sequence);
            counter++;
        }
        cout << counter;
    //char buffer [40];
    //itoa (winner,buffer,10);
    //Answer(buffer);
    return 0;

}
