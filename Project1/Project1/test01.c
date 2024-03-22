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
	//�ٵ��� ����
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
	//�� ���� ����Ŭ
	while (1)
	{
		put_black();
		put_white();
	}
	return 0;
}

// ������ ����
void put_black()
{
	int x, y;
	printf("�������� ���� ��ǥ�� �Է��ϼ���.(0~18)\n");
	scanf("%d%d", &x, &y);
	if (board[x][y] != '+')
	{
		printf("���ڸ��� �ƴմϴ�. �ٽ� �Է��ϼ���.\n");
		scanf("%d%d", &x, &y);
	}
	if (x < 0 || x > 18 || y < 0 || y > 18)
	{
		printf("��ǥ ������ ������ϴ�. �ٽ� �Է��ϼ���.\n");
		scanf("%d%d", &x, &y);	
	}
	else
		board[x][y] = 'B';
	draw_board();
	printf("������ ����: %d\n", ++black_cnt);
	printf("�� ����: %d\n", white_cnt);
}

// �� ����
void put_white()
{
	int x, y;
	printf("���� ���� ��ǥ�� �Է��ϼ���.(0~18)\n");
	scanf("%d%d", &x, &y);
	if (board[x][y] != '+')
	{
		printf("���ڸ��� �ƴմϴ�. �ٽ� �Է��ϼ���.\n");
		scanf("%d%d", &x, &y);
	}
	if (x < 0 || x > 18 || y < 0 || y > 18)
	{
		printf("��ǥ ������ ������ϴ�. �ٽ� �Է��ϼ���.\n");
		scanf("%d%d", &x, &y);
	}
	else
		board[x][y] = 'W';
	draw_board();
	printf("������ ����: %d\n", black_cnt);
	printf("�� ����: %d\n", ++white_cnt);
}

//�� �ٵ��� ��Ȳ �׸���
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