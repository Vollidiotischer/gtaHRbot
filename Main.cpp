#include <iostream>
#include <windows.h>
#include <array>

void click(); 
void move_mouse(int, int);
int getInput(); 

bool running = true; 

std::array<std::array<int, 2>, 6> positions = 
{ { 
	{700, 700},
	{700, 900},
	{700, 1150},
	{700, 1400},
	{700, 1650},
	{700, 1900}
} };


int main() {

	while (running) {

		int inp = getInput();


		if (inp == 0) {
			running = false; 
			break; 
		}

		if (inp == -1) {
			move_mouse(1900, 2000);
			click(); 
			
			Sleep(20); 

			move_mouse(3000, 1800); 
			click(); 
		}
		else {
			move_mouse(700, positions[inp - 1][1]); // move mouse to the selected horse
			Sleep(20);
			click();
			Sleep(20);

			move_mouse(3050, 1050); //move mouse to the bet increase button
			Sleep(20);

			for (int i = 0; i < 27; i++) {
				click(); // click 27 times pls (to max bet) 
				Sleep(25);

			}

			move_mouse(2600, 1550); // move mouse to "set bet" button
			Sleep(40);
			click();

		}
	}

	return 0; 
}

int getInput() {

	while (true) {
		if (GetKeyState(VK_SPACE) & 0x8000) {
			return -1;
		}
		if (GetKeyState('0') & 0x8000) {
			return 0;
		}
		if (GetKeyState('1') & 0x8000) {
			return 1;
		}
		if (GetKeyState('2') & 0x8000) {
			return 2;
		}
		if (GetKeyState('3') & 0x8000) {
			return 3;
		}
		if (GetKeyState('4') & 0x8000) {
			return 4;
		}
		if (GetKeyState('5') & 0x8000) {
			return 5;
		}
		if (GetKeyState('6') & 0x8000) {
			return 6;
		}
		Sleep(150); 
	}
}

void click() {
	INPUT inp = { 0 }; 
	
	inp.type = INPUT_MOUSE; 
	inp.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	SendInput(1, &inp, sizeof(INPUT)); 
	Sleep(50); 
	ZeroMemory(&inp, sizeof(INPUT)); 

	inp.type = INPUT_MOUSE;
	inp.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	SendInput(1, &inp, sizeof(INPUT));
}

void move_mouse(int x, int y) {

	long screenWidth = 3840; //GetSystemMe0trics(SM_CXSCREEN) - 1; 
	long screenHeight = 2160;  //GetSystemMetrics(SM_CYSCREEN) - 1;	

	INPUT inp = { 0 }; 
	
	inp.type = INPUT_MOUSE; 
	inp.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE; 

	inp.mi.dx = x * (65535.0f / (double)screenWidth);
	inp.mi.dy = y * (65535.0f / (double)screenHeight);
	
	SendInput(1, &inp, sizeof(INPUT)); 

}