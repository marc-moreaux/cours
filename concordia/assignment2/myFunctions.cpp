#include "myFunctions.h"
#include <Windows.h>
#include <iostream>
#include <string>

void setCursorToPosX(int pos, std::string myString){
	COORD cursorPos={0,0};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO SBInfo;
	GetConsoleScreenBufferInfo(hOut, &SBInfo);
	cursorPos.X = pos;
	cursorPos.Y = SBInfo.dwCursorPosition.Y;
	SetConsoleCursorPosition(hOut,cursorPos);
	std::cout << myString;
}
void setCursorToPosrelativeXY(int posX, int posY){
	COORD cursorPos={0,0};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO SBInfo;
	GetConsoleScreenBufferInfo(hOut, &SBInfo);
	cursorPos.X = SBInfo.dwCursorPosition.X + posX;
	cursorPos.Y = SBInfo.dwCursorPosition.Y + posY;
	SetConsoleCursorPosition(hOut,cursorPos);
}
void setConsole(int x,int y){
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD NewSBSize = {x,100};
    SMALL_RECT DisplayArea = {0, 0, x-1, y-1};

    SetConsoleScreenBufferSize(hOut,NewSBSize);
    SetConsoleWindowInfo(hOut,TRUE,&DisplayArea);
}
void showMyTimer(int sec){
	sec = (sec<=0?1:sec) ;
	sec = (sec>=10?9:sec) ;
	
	setCursorToPosrelativeXY(0,-1);
	std::cout << (unsigned char)218 << (unsigned char)196 << (unsigned char)196 << (unsigned char)196 << (unsigned char)196 << (unsigned char)191;
	setCursorToPosrelativeXY(-6,2);
	std::cout << (unsigned char)192 << (unsigned char)196 << (unsigned char)196 << (unsigned char)196 << (unsigned char)196 << (unsigned char)217;
	setCursorToPosrelativeXY(-1,-1);
	for(int i=sec;i>0;i--){
		setCursorToPosrelativeXY(-5,0);
		std::cout << (unsigned char)179 << "    " << (unsigned char)179;
		setCursorToPosrelativeXY(-5,0);
		std::cout <<i;
		for(int j=0;j<3;j++)
			{Sleep(350); std::cout << ".";}
		Sleep(350);
	}
}