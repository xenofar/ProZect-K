#include "ProZect K.h"
#include <stdio.h>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <htmlayout.h>

HWND createwindow();

struct _questions questions[500];

int main(){
	HWND hwnd = createwindow();
	HTMLayoutLoadFile(hwnd, L".\\UI.html");
	MSG msg;
	while(GetMessage(&msg, NULL, 0, 0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT CALLBACK wproc (HWND hwnd, UINT msg, WPARAM wparm, LPARAM lparm){
	switch(msg){
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
	}
	return HTMLayoutProc(hwnd, msg, wparm, lparm);
}
