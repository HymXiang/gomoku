#include "windowFunc.hpp"

int main()
{
	initgraph(600, 600);

	bool running = 1;

	ExMessage msg;

	BeginBatchDraw();

	setbkcolor(RGB(209, 155, 14));

	while (running)
	{
		DWORD startTime = GetTickCount();

		takeMessage(msg);

		cleardevice();

		// Program body

		DrawChess();
		DrawPiece();
		DrawTipText();

		FlushBatchDraw();

		whoWin(running);
		
		DWORD endTime = GetTickCount();
		DWORD deltaTime = endTime - startTime;

		if (deltaTime < 1000 / 60)
		{
			Sleep(1000 / 60 - deltaTime);
		}
	}

	EndBatchDraw();

	return 0;
}