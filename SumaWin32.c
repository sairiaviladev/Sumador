#include <windows.h>
#include "SumaWin32.h"


/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps; 
	HDC hdc; 
	static HINSTANCE hInstance;
	static HWND hBtnSumar, hEdtNum1, hEdtNum2, hEdtSuma, hEdtSim;
	static HWND hBtnRestar;
	static HWND hBtnMulti;
	static HWND hBtnDiv;
	

	
	switch(Message) {
		 
	case WM_CREATE:{
		hInstance = ((LPCREATESTRUCT)lParam)->hInstance;
		hBtnSumar = CreateWindowEx(0, "BUTTON",   /* Nombre de la clase */
						"Sumar",        /* Texto del título */
						BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE | 
						WS_BORDER | WS_TABSTOP, /* Estilo */
						10, 80,         /* Posición */
						80, 34,         /* Tamaño */
						hwnd,           /* Ventana padre */
						(HMENU)ID_BTNSUMAR, /* Identificador del 
control */
						hInstance,      /* Instancia */
						NULL);          /* Sin datos de creación*/ 
						
						
			hInstance = ((LPCREATESTRUCT)lParam)->hInstance;
		hBtnRestar = CreateWindowEx(0, "BUTTON",   
						"Restar",        
						BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE | 
						WS_BORDER | WS_TABSTOP, 
						10,120,         
						80, 34,        
						hwnd,          
						(HMENU)ID_BTNRESTAR, 
						hInstance,      
						NULL);        
						
		hInstance = ((LPCREATESTRUCT)lParam)->hInstance;
		hBtnMulti = CreateWindowEx(0, "BUTTON",   
						"Multiplicar",        
						BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE | 
						WS_BORDER | WS_TABSTOP, 
						100,80,         
						80, 34,        
						hwnd,          
						(HMENU)ID_BTNMULT, 
						hInstance,      
						NULL);      
						
		hInstance = ((LPCREATESTRUCT)lParam)->hInstance;
		hBtnDiv = CreateWindowEx(0, "BUTTON",   
						"Dividir",        
						BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE | 
						WS_BORDER | WS_TABSTOP, 
						100,120,         
						80, 34,        
						hwnd,          
						(HMENU)ID_BTNDIV, 
						hInstance,      
						NULL);   

		
						

		hEdtNum1 = CreateWindowEx(0,
						"EDIT",         /* Nombre de la clase */
						"",             /* Sin texto de título */
						ES_LEFT | WS_CHILD | WS_VISIBLE | WS_BORDER |
WS_TABSTOP | ES_NUMBER, /* Estilo */ 
						10, 45,         /* Posición */
						35, 25,         /* Tamaño */
						hwnd,           /* Ventana padre */
						(HMENU)ID_EDTNUM1,  /* Identificador del 
control */
						hInstance,      /* Instancia */
						NULL);          /* Sin datos de creación*/ 
			
		hEdtNum2 = CreateWindowEx(0,
						"EDIT",         /* Nombre de la clase */
						"",             /* Sin texto de título*/
						ES_LEFT | WS_CHILD | WS_VISIBLE | WS_BORDER | 
WS_TABSTOP | ES_NUMBER, /* Estilo */ 
						82, 45,         /* Posición */
						35, 25,         /* Tamaño */
						hwnd,           /* Ventana padre */
						(HMENU)ID_EDTNUM2,  /* Identificador del 
control */
						hInstance,      /* Instancia */
						NULL);          /* Sin datos de creación */ 

		hEdtSuma = CreateWindowEx(0,
						"EDIT",         /* Nombre de la clase */
						"",             /* Sin texto de título */
						ES_LEFT | WS_CHILD | WS_VISIBLE | WS_BORDER | 
WS_TABSTOP | ES_NUMBER | ES_READONLY, /* 
Estilo */ 
						140, 45,        /* Posición */
						35, 25,         /* Tamaño */
						hwnd,           /* Ventana padre */
						(HMENU)ID_EDTSUMA,  /* Identificador del 
control */
						hInstance,      /* Instancia */
						NULL);          /* Sin datos de creación */ 
		SetFocus(hEdtNum1);
		
		
		
		hEdtSim = CreateWindowEx(0,
						"EDIT",         /* Nombre de la clase */
						"",             /* Sin texto de título */
						ES_LEFT | WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_NUMBER, /* Estilo */ 
						52, 45,         /* Posición */
						30, 20,         /* Tamaño */
						hwnd,           /* Ventana padre */
						(HMENU)ID_EDTSIM,  /* Identificador del 
control */
						hInstance,      /* Instancia */
						NULL);     
						
		SetFocus(hEdtSim);
		break;
		
		
	}
	
	
 	case WM_COMMAND:{
		int wmId    = LOWORD(wParam);
		int wmEvent = HIWORD(wParam);
		// Analizar las selecciones de comandos:
		switch (wmId)
		{
			case ID_BTNSUMAR:{
				char szNum1[32], szNum2[32], szSim[32], szSuma[32];
				int num1, num2, suma;
				char sim = '+';
/*Obtiene el texto introducido por el usuario
  y lo convierte de texto a entero*/ 
				GetDlgItemText(hwnd, ID_EDTNUM1, szNum1, 31);						num1 = atoi(szNum1);
/*Obtiene el texto introducido por el usuario
  y lo convierte de texto a entero*/
				GetDlgItemText(hwnd, ID_EDTNUM2, szNum2, 31);						num2 = atoi(szNum2);
				suma = num1 + num2;
				sprintf(szSuma,"%d",suma);
				sprintf(szSim,"%c",sim);
				SetDlgItemText(hwnd,ID_EDTSUMA,szSuma);
				SetDlgItemText(hwnd,ID_EDTSIM,szSim);
				break;
			}
			case ID_BTNRESTAR:{
				char szNum1[32], szNum2[32], szSim[32], szSuma[32];
				int num1, num2, restar;
				char sim = '-';
/*Obtiene el texto introducido por el usuario
  y lo convierte de texto a entero*/ 
				GetDlgItemText(hwnd, ID_EDTNUM1, szNum1, 31);						num1 = atoi(szNum1);
/*Obtiene el texto introducido por el usuario
  y lo convierte de texto a entero*/
				GetDlgItemText(hwnd, ID_EDTNUM2, szNum2, 31);						num2 = atoi(szNum2);
				restar = num1 - num2;
				sprintf(szSuma,"%d",restar);
				sprintf(szSim,"%c",sim);
				SetDlgItemText(hwnd,ID_EDTSUMA,szSuma);
				SetDlgItemText(hwnd,ID_EDTSIM,szSim);
				break;
			}
			
			case ID_BTNMULT:{
				char szNum1[32], szNum2[32], szSim[32], szSuma[32];
				int num1, num2, mult;
				char sim='*';
/*Obtiene el texto introducido por el usuario
  y lo convierte de texto a entero*/ 
				GetDlgItemText(hwnd, ID_EDTNUM1, szNum1, 31);						num1 = atoi(szNum1);
/*Obtiene el texto introducido por el usuario
  y lo convierte de texto a entero*/
				GetDlgItemText(hwnd, ID_EDTNUM2, szNum2, 31);						num2 = atoi(szNum2);
				mult = (num1*num2);
				sprintf(szSuma,"%d",mult);
				sprintf(szSim,"%c",sim);
				SetDlgItemText(hwnd,ID_EDTSUMA,szSuma);
				SetDlgItemText(hwnd,ID_EDTSIM,szSim);
				break;
			}
			
			case ID_BTNDIV:{
				char szNum1[32], szNum2[32], szSim[32], szSuma[32];
				int num1, num2, div;
				char sim = '/';
/*Obtiene el texto introducido por el usuario
  y lo convierte de texto a entero*/ 
				GetDlgItemText(hwnd, ID_EDTNUM1, szNum1, 31);						num1 = atoi(szNum1);
/*Obtiene el texto introducido por el usuario
  y lo convierte de texto a entero*/
				GetDlgItemText(hwnd, ID_EDTNUM2, szNum2, 31);						num2 = atoi(szNum2);
				div = num1/num2;
				sprintf(szSuma,"%d",div);
				sprintf(szSim,"%c",sim);
				SetDlgItemText(hwnd,ID_EDTSUMA,szSuma);
				SetDlgItemText(hwnd,ID_EDTSIM,szSim);
				break;
			}	
			
			default:
				return DefWindowProc(hwnd, Message, wParam, lParam);			}
		break;
	}
		
	case WM_PAINT:{
		hdc = BeginPaint(hwnd, &ps); 
			
		TextOut(hdc,10,30,"Num1",strlen("Num1"));
		//TextOut(hdc,50,48,"+",strlen("+"));			
		TextOut(hdc,80,30,"Num2",strlen("Num2"));			
		TextOut(hdc,125,48,"=",strlen("="));			
		TextOut(hdc,140,30,"Producto",strlen("Producto"));	
		
			
		EndPaint(hwnd, &ps); 
		break;
	}

		
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","SumaWin32",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		300, /* width */
		250, /* height */
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
}
