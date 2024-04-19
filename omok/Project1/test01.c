#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void put_black();
void put_white();
void draw_board();
//초기값 설정
char board[19][19];
int b_cnt = 0;
int w_cnt = 0;

int main()
{
	//초기 보드판 그리기
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			board[i][j] = '+';
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	//돌 놓는 사이클
	while (1)
	{
		put_black();
		put_white();
	}
	return 0;
}
//현 보드 상황 그리는 함수
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
//검은 돌 놓는 함수
void put_black()
{
	int x, y;

	printf("검은돌이 놓일 좌표를 입력하세요.(0~18).\n");
	scanf("%d%d", &x, &y);
	if (x < 0 || x >= 19 || y < 0 || y >= 19 || board[x][y] != '+')
	{
		printf("잘못된 입력입니다. 다시 입력하세요.\n");
		put_black(); 
		return;
	}
	b_cnt++;
	board[x][y] = 'B';
	draw_board();

	printf("검은돌의 개수:%d\n", b_cnt);
	printf("흰돌의 개수:%d\n", w_cnt);
}
//흰돌 놓는 함수
void put_white()
{
	int x, y;

	printf("흰돌이 놓일 좌표를 입력하세요.(0~18).\n");
	scanf("%d%d", &x, &y);
	if (x < 0 || x >= 19 || y < 0 || y >= 19 || board[x][y] != '+')
	{
		printf("잘못된 입력입니다. 다시 입력하세요.\n");
		put_white(); 
		return;
	}
	w_cnt++;
	board[x][y] = 'W';
	draw_board();

	printf("검은돌의 개수:%d\n", b_cnt);
	printf("흰돌의 개수:%d\n", w_cnt);
}
