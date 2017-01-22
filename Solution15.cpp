#include <iostream>
#include <windows.h>


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

int main()
{
    int num = 2;
    bool blocks [num][num] = {0};
    int counter = 0;
    for(int x = 0 ; x < num; x++)
    {
        for(int y = 0 ; y < num; y++)
        {
            for(int y = 0 ; y < num; y++)
                {
                    blocks [x][y] = 1;
                    counter++;
                }
        }
    }
    cout << counter<< endl;
    return 0;
}
