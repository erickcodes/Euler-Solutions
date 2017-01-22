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
        char c;
        while(stream.get(c))
        {
            data.push_back(c - '0');
        }
    }
    myfile.close();
    }
    //processing end
    else cout << "Unable to open file";
    return data;
}



int main()
{
    int counter = 0;
    datatype sum [50] = {0};
     for(int i = 0;i < 50; i++)
    {
        sum[i] = 0;
    }
    vector<datatype> data = dataVector();
    for(std::vector<datatype>::size_type i = 0; i < data.size(); i++)
    {
        int digit = (i%50);
        sum[digit] += data[i];
        if(sum[digit] >= 10&& digit != 0)
        {
            sum[digit] -= 10;
            sum[digit-1] += 1;
        }
    }
    char buffer[10];

    for(int i = 0;i < 50; i++)
    {

      cout << sum[i];
    }
    //Answer(buffer);
    return 0;
}
