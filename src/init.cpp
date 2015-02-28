#include "ProZect K.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

LRESULT CALLBACK wproc (HWND hwnd, UINT msg, WPARAM wparm, LPARAM lparm);

HWND createwindow(){
	HWND hwnd;
	WNDCLASSEX wincl;        /* Data structure for the windowclass */

	/* The Window structure */
	wincl.hInstance = GetModuleHandle(NULL);
	wincl.lpszClassName = "ProZectK";
	wincl.lpfnWndProc =  wproc;      /* This function is called by windows */
	wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
	wincl.cbSize = sizeof (WNDCLASSEX);

//	 Use default icon and mouse-pointer
	wincl.hIcon = NULL;
	wincl.hIconSm = NULL;
	wincl.hCursor = NULL;
//	wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
//	wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
//	wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
	wincl.lpszMenuName = NULL;                 /* No menu */
	wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
	wincl.cbWndExtra = 0;                      /* structure or the window instance */
	/* Use Windows's default colour as the background of the window */
	wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

	/* Register the window class, and if it fails quit the program */
	if (!RegisterClassEx (&wincl))
			return 0;

	/* The class is registered, let's create the program*/
	hwnd = CreateWindowEx (
		 0,                   /* Extended possibilites for variation */
		 "ProZectK",         /* Classname */
		 "ProZect K Intro Window",       /* Title Text */
		 WS_OVERLAPPEDWINDOW, /* default window */
		 CW_USEDEFAULT,       /* Windows decides the position */
		 CW_USEDEFAULT,       /* where the window ends up on the screen */
		 1248,                 /* The programs width */
		 650,                 /* and height in pixels */
		 NULL,        /* The window is a child-window to desktop */
		 NULL,                /* No menu */
		 GetModuleHandle(NULL),       /* Program Instance handler */
		 NULL                 /* No Window Creation data */
	);
	ShowWindow(hwnd, 1);
	return hwnd;
}
