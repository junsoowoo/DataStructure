#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void put_black();
void put_white();
void draw_board();
char board[19][19] ;
int black_cnt = 0;
int white_cnt = 0;

int main()
{
	//바둑판 생성
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			board[i][j] = '+';
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("=====================================\n");
	//돌 놓는 사이클
	while (1)
	{
		put_black();
		put_white();
	}
	return 0;
}

// 검은돌 놓기
void put_black()
{
	int x, y;
	printf("검정돌이 놓일 좌표를 입력하세요.(0~18)\n");
	scanf("%d%d", &x, &y);
	if (board[x][y] != '+')
	{
		printf("빈자리가 아닙니다. 다시 입력하세요.\n");
		scanf("%d%d", &x, &y);
	}
	if (x < 0 || x > 18 || y < 0 || y > 18)
	{
		printf("좌표 범위를 벗어났습니다. 다시 입력하세요.\n");
		scanf("%d%d", &x, &y);	
	}
	else
		board[x][y] = 'B';
	draw_board();
	printf("검정돌 개수: %d\n", ++black_cnt);
	printf("흰돌 개수: %d\n", white_cnt);
}

// 흰돌 놓기
void put_white()
{
	int x, y;
	printf("흰돌이 놓일 좌표를 입력하세요.(0~18)\n");
	scanf("%d%d", &x, &y);
	if (board[x][y] != '+')
	{
		printf("빈자리가 아닙니다. 다시 입력하세요.\n");
		scanf("%d%d", &x, &y);
	}
	if (x < 0 || x > 18 || y < 0 || y > 18)
	{
		printf("좌표 범위를 벗어났습니다. 다시 입력하세요.\n");
		scanf("%d%d", &x, &y);
	}
	else
		board[x][y] = 'W';
	draw_board();
	printf("검정돌 개수: %d\n", black_cnt);
	printf("흰돌 개수: %d\n", ++white_cnt);
}

//현 바둑판 상황 그리기
void draw_board()
{
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}