#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <stdlib.h>


#define datatype int

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


vector<datatype> dataVector()
{
    ifstream myfile ("data.txt");
    vector<datatype> data;
    if (myfile.is_open())
    {
    //Processing the content in data.txt into a vector
     string line;
     while ( getline (myfile,line))
    {
        stringstream stream(line);
        int n;
        while(stream >> n)
        {
            data.push_back(n);
        }
    }
    myfile.close();
    }
    //processing end
    else cout << "Unable to open file";
    return data;
}

vector<datatype> data = dataVector();


int multiple(int index, int x, int y)
{
    int pos;
    if(4 >= x >= 2){
         pos = 23-x;
      }else if(x == 5){
         pos = -1;
      }else if(6 <= x <= 8){
         pos = x-27;
      }else {
     pos = x;
      }
      pos *= y;
    if(0 <= pos+index && pos+index  < data.size())
        {
            return data[pos+index];
        }
            return 1;
}

int main()
{
    int highest = 0;
    for(std::vector<int>::size_type i = 0; i < data.size(); i++)
    {
        int multiples[4];
                for(int x = 1; x < 9;x++)
                {
                    for(int y = 0; y < 4; y++)
                    {
                        multiples[y] = multiple(i , x, y);
                        if(multiples[y] > 99){
                        cout <<multiples[y] << " " << i << " "<<x<< " " << y <<endl;
                        int pos;
                        }
                    }
                    if(multiples[0]*multiples[1]*multiples[2]*multiples[3] > highest)
                    {
                        cout << multiples[0]<< " * "<< multiples[1]<< " * "<<multiples[2]<< " * "<<multiples[3] << " = ";
                        highest = multiples[0]*multiples[1]*multiples[2]*multiples[3];
                        cout << highest << endl;
                    }
                }

    }
    cout << data.size()<< endl;
    char buffer [40];
    itoa (highest,buffer,10);
    Answer(buffer);
    return 0;
}
