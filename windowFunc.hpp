#include <easyx.h>
#include "luo2ji0Func.hpp"

void DropPiece(ExMessage& msg)
{
	if (msg.message == WM_LBUTTONDOWN)
	{
		int x = msg.x;
		int y = msg.y;

		int index_x = x / 40;
		int index_y = y / 40;

		if (index_x < 0 || index_x >= 15 ||
			index_y < 0 || index_y >= 15)
			return;

		if (chess[index_x][index_y] != '+')
			return;

		chess[index_x][index_y] = CurrentPiece;

		CurrentPiece = (CurrentPiece == 'o') ? 'x' : 'o';
	}
}

void takeMessage(ExMessage& msg)
{
	while (peekmessage(&msg))
	{
		DropPiece(msg);
	}
}

void whoWin(bool& running)
{
	if (nobodyWin())
	{
		running =  0;
		return;
	}
	else if (win('o'))
	{
		MessageBox(GetHWnd(), _T("the black win!"), _T("game over"), MB_OK);
		running =  0;
		return;
	}
	else if (win('x'))
	{
		MessageBox(GetHWnd(), _T("the white win!"), _T("game over"), MB_OK);
		running = 0;
		return;
	}
	running =  1;
}

void DrawChess()
{
	setlinecolor(RGB(128, 64, 0));
	for (short j = 1; j <= 14; j++)
	{
		line(0, j * 40, 600, j * 40);
	}
	for (short i = 1; i <= 14; i++)
	{
		line(i * 40, 0, i * 40, 600);
	}
}

void DrawPiece()
{
	for (short i = 0; i < 15; i++)
	{
		for (short j = 0; j < 15; j++)
		{
			if (chess[i][j] == 'o')
			{
				setfillcolor(BLACK);
				solidcircle(i * 40 + 20, j * 40 + 20, 20);
			}
			else if (chess[i][j] == 'x')
			{
				setfillcolor(WHITE);
				solidcircle(i * 40 + 20, j * 40 + 20, 20);
			}
		}
	}
}

void DrawTipText()
{
	static TCHAR str[64];
	_stprintf_s(str, _T("the %s"), (CurrentPiece == 'o' ? _T("black") : _T("white")));

	settextstyle(24, 0, _T("等线"));

	settextcolor(RGB(225, 125, 45));
	outtextxy(0, 0, str);
}