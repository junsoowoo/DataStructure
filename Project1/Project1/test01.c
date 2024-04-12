#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void put_black();
void put_white();
void draw_board();
//�ʱⰪ ����
char board[19][19];
int b_cnt = 0;
int w_cnt = 0;

int main()
{
	//�ʱ� ������ �׸���
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			board[i][j] = '+';
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	//�� ���� ����Ŭ
	while (1)
	{
		put_black();
		put_white();
	}
	return 0;
}
//�� ���� ��Ȳ �׸��� �Լ�
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
//���� �� ���� �Լ�
void put_black()
{
	int x, y;

	printf("�������� ���� ��ǥ�� �Է��ϼ���.(0~18).\n");
	scanf("%d%d", &x, &y);
	if (x < 0 || x >= 19 || y < 0 || y >= 19 || board[x][y] != '+')
	{
		printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n");
		put_black(); 
		return;
	}
	b_cnt++;
	board[x][y] = 'B';
	draw_board();

	printf("�������� ����:%d\n", b_cnt);
	printf("���� ����:%d\n", w_cnt);
}
//�� ���� �Լ�
void put_white()
{
	int x, y;

	printf("���� ���� ��ǥ�� �Է��ϼ���.(0~18).\n");
	scanf("%d%d", &x, &y);
	if (x < 0 || x >= 19 || y < 0 || y >= 19 || board[x][y] != '+')
	{
		printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n");
		put_white(); 
		return;
	}
	w_cnt++;
	board[x][y] = 'W';
	draw_board();

	printf("�������� ����:%d\n", b_cnt);
	printf("���� ����:%d\n", w_cnt);
}
