// assignment3.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "AccountManager.h"
#include <Windows.h>

void setConsole(int x,int y){
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD NewSBSize = {x,100};
    SMALL_RECT DisplayArea = {0, 0, x-1, y-1};

    SetConsoleScreenBufferSize(hOut,NewSBSize);
    SetConsoleWindowInfo(hOut,TRUE,&DisplayArea);
}

int _tmain(int argc, _TCHAR* argv[])
{
	setConsole(130,40);
	AccountManager myAccountManager;
	

	myAccountManager.run();
		


	return 0;
}

