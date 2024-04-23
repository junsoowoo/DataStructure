#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define BOARD_SIZE 19

void put_black();
void put_white();
void draw_board();
void count_rowcolumn();
void count_max_continuous();

char board[BOARD_SIZE][BOARD_SIZE];

int main() 
{
	//초기 보드판 그리기
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			board[i][j] = '+';
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	while (1) 
	{
		put_black();
		put_white();
	}
	return 0;
}

void draw_board() 
{
	for (int i = 0; i < BOARD_SIZE; i++) 
	{
		for (int j = 0; j < BOARD_SIZE; j++) 
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void put_black() 
{
	int x, y;
	printf("검은돌이 놓일 좌표를 입력하세요.(0~18).\n");
	scanf("%d%d", &x, &y);
	if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE || board[x][y] != '+') 
	{
		printf("잘못된 입력입니다. 다시 입력하세요.\n");
		put_black();
		return;
	}
	board[x][y] = 'B';
	draw_board();
	count_rowcolumn();
}
void put_white() 
{
	int x, y;
	printf("흰돌이 놓일 좌표를 입력하세요.(0~18).\n");
	scanf("%d%d", &x, &y);
	if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE || board[x][y] != '+')
	{
		printf("잘못된 입력입니다. 다시 입력하세요.\n");
		put_white();
		return;
	}
	board[x][y] = 'W';
	draw_board();
	count_rowcolumn();
}

void count_rowcolumn()
{
	//1번
	//가로 세기
	for (int i = 0; i < 19; ++i)
	{
		int b_cnt = 0;
		int w_cnt = 0;
		for (int j = 0; j < 19; ++j)
		{
			if (board[i][j] == 'B') b_cnt++;
			else if (board[i][j] == 'W') w_cnt++;
		}
		printf("가로%d의 검은돌 개수: %d\n", i, b_cnt);
		printf("가로%d의 흰돌 개수: %d\n", i, w_cnt);
	}
	//세로 세기
	for (int i = 0; i < 19; ++i)
	{
		int b_cnt = 0;
		int w_cnt = 0;
		for (int j = 0; j < 19; ++j)
		{
			if (board[j][i] == 'B') b_cnt++;
			else if (board[j][i] == 'W') w_cnt++;
		}
		printf("세로%d줄의 검은돌 개수: %d\n", i, b_cnt);
		printf("세로%d줄의 흰돌 개수: %d\n", i, w_cnt);
	}
	//2,4번
	count_max_continuous();
}

void count_max_continuous()
{	
	// 가로
	for (int i = 0; i < BOARD_SIZE; ++i) 
	{
		int max_continuous = 0;
		char max_type = '+';
		int max_start_garo = -1;
		int max_end_garo = -1;

		int b_cont = 0;
		int w_cont = 0;
		char prev_type = '+';

		for (int j = 0; j < BOARD_SIZE; ++j) 
		{
			if ((board[i][j] == 'B' || board[i][j] == 'W') && board[i][j] == prev_type) 
			{
				if (board[i][j] == 'B')
				{
					b_cont++;
				}
				else {
					w_cont++;
				}
			}
			else 
			{
				if (b_cont > max_continuous) 
				{
					max_continuous = b_cont;
					max_type = 'B';
					max_start_garo = j - max_continuous;
					max_end_garo = j - 1;
				}
				else if (w_cont > max_continuous) 
				{
					max_continuous = w_cont;
					max_type = 'W';
					max_start_garo = j - max_continuous;
					max_end_garo = j - 1;
				}
				b_cont = (board[i][j] == 'B') ? 1 : 0;
				w_cont = (board[i][j] == 'W') ? 1 : 0;
				prev_type = board[i][j];
			}
		}

		// 마지막 열까지 연속된 돌이 있는지 확인
		if (b_cont > max_continuous) 
		{
			max_continuous = b_cont;
			max_type = 'B';
			max_start_garo = BOARD_SIZE - max_continuous;
			max_end_garo = BOARD_SIZE - 1;
		}
		else if (w_cont > max_continuous) 
		{
			max_continuous = w_cont;
			max_type = 'W';
			max_start_garo = BOARD_SIZE - max_continuous;
			max_end_garo = BOARD_SIZE - 1;
		}

		// 출력
		if (max_type != '+') 
		{
			printf("가로 %d줄에서 가장 많이 연속된 돌: %c, 개수: %d\n", i, max_type, max_continuous);
			printf("시작 좌표: (%d, %d), 끝 좌표: (%d, %d)\n", i, max_start_garo, i, max_end_garo);
		}
	}
	// 세로
	for (int j = 0; j < BOARD_SIZE; ++j) 
	{
		int max_continuous = 0;
		char max_type = '+';
		int max_start_sero = -1;
		int max_end_sero = -1;

		int b_cont = 0;
		int w_cont = 0;
		char prev_type = '+';

		for (int i = 0; i < BOARD_SIZE; ++i) 
		{
			if ((board[i][j] == 'B' || board[i][j] == 'W') && board[i][j] == prev_type) 
			{
				if (board[i][j] == 'B') 
				{
					b_cont++;
				}
				else 
				{
					w_cont++;
				}
			}
			else {
				if (b_cont > max_continuous) 
				{
					max_continuous = b_cont;
					max_type = 'B';
					max_start_sero = i - max_continuous;
					max_end_sero = i - 1;
				}
				else if (w_cont > max_continuous) 
				{
					max_continuous = w_cont;
					max_type = 'W';
					max_start_sero = i - max_continuous;
					max_end_sero = i - 1;
				}
				b_cont = (board[i][j] == 'B') ? 1 : 0;
				w_cont = (board[i][j] == 'W') ? 1 : 0;
				prev_type = board[i][j];
			}
		}

		// 마지막 행까지 연속된 돌이 있는지 확인
		if (b_cont > max_continuous)
		{
			max_continuous = b_cont;
			max_type = 'B';
			max_start_sero = BOARD_SIZE - max_continuous;
			max_end_sero = BOARD_SIZE - 1;
		}
		else if (w_cont > max_continuous) 
		{
			max_continuous = w_cont;
			max_type = 'W';
			max_start_sero = BOARD_SIZE - max_continuous;
			max_end_sero = BOARD_SIZE - 1;
		}

		// 출력
		if (max_type != '+') 
		{
			printf("세로 %d줄에서 가장 많이 연속된 돌: %c, 개수: %d\n", j, max_type, max_continuous);
			printf("시작 좌표: (%d, %d), 끝 좌표: (%d, %d)\n", max_start_sero, j, max_end_sero, j);
		}
	}
}
