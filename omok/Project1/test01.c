#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void put_black();
void put_white();
void draw_board();
void count_rowcolumn();
void max_count_continuous();
void save_game();
void load_game();
void push(int x, int y, char stone_type);
void pop();
void redo();

// ���� ����ü ����
typedef struct {
	int x;
	int y;
	char stone_type;
} Stone;

//�ʱⰪ ����
#define BOARD_SIZE 19
#define STACK_SIZE 100
char board[19][19];
int b_cnt = 0;
int w_cnt = 0;
Stone undoStack[STACK_SIZE];
Stone redoStack[STACK_SIZE];
int top_undo = -1; // undo ������ top�� ��Ÿ���� ����
int top_redo = -1; // redo ������ top�� ��Ÿ���� ����

int main()
{
	//�ʱ� ������ �׸���
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			board[i][j] = '+';
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	int choice;
	printf("1. �� ����\n");
	printf("2. �̾��ϱ�\n");
	printf("1���� 2���� ����: ");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
		// Start a new game
		break;
	case 2:
		// Load a saved game
		load_game();
		break;
	default:
		printf("�߸��� �Է�.\n");
		return 1;
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
	int order;
	printf("������ ���ϸ� 0, ������ ������ ���ϸ� 1, �����⸦ ���ϸ� 2, �ٽ� ���⸦ ���ϸ� 3, �� ���� 4\n");
	scanf("%d", &order);
	if (order == 0)
	{
		save_game();
		printf("����Ǿ����ϴ�.\n");
		exit(0);
	}
	else if (order == 1)
	{
		printf("�������� ���� ��ǥ�� �Է��ϼ���.(0~18).\n");
		scanf("%d%d", &x, &y);
		if (x < 0 || x >= 19 || y < 0 || y >= 19 || board[x][y] != '+')
		{
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n");
			put_black();
			return;
		}
		board[x][y] = 'B';
		draw_board();
		push(x, y, 'B');
	}
	else if (order == 2)
	{
		if (top_undo == -1)
		{
			printf("������ ������ϴ�.\n");
			return;
		}
		pop();
		draw_board();
	}
	else if (order == 3)
	{
		if (top_redo == -1)
		{
			printf("������ ������ϴ�.\n");
			return;
		}
		redo(); // redo ���ÿ��� �� ��ǥ�� pop�Ͽ� ���� �ٽ� ����
	}
	else if (order == 4)
	{
		printf("���� �� ���Դϴ�.\n");
		put_white();
	}
	else
	{
		printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n");
		put_black();
		return;
	}
	count_rowcolumn();
}
//�� ���� �Լ�
void put_white()
{
	int x, y;
	int order;
	printf("������ ���ϸ� 0, �� ������ ���ϸ� 1, �����⸦ ���ϸ� 2, �ٽ� ���⸦ ���ϸ� 3, �� ���� 4\n");
	scanf("%d", &order);
	if (order == 1)
	{
		printf("�� ���� ���� ��ǥ�� �Է��ϼ���.(0~18).\n");
		scanf("%d%d", &x, &y);
		if (x < 0 || x >= 19 || y < 0 || y >= 19 || board[x][y] != '+')
		{
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n");
			put_white();
			return;
		}
		board[x][y] = 'W';
		draw_board();
		push(x, y, 'W');
	}
	else if (order == 0)
	{
		save_game();
		printf("����Ǿ����ϴ�.\n");
		exit(0);
	}
	else if (order == 2)
	{
		if (top_undo == -1)
		{
			printf("������ ������ϴ�.\n");
			return;
		}
		pop();
		printf("\n");
		draw_board();
	}
	else if (order == 3)
	{
		if (top_redo == -1)
		{
			printf("������ ������ϴ�.\n");
			return;
		}
		redo(); // redo ���ÿ��� �� ��ǥ�� pop�Ͽ� ���� �ٽ� ����
	}
	else if (order == 4)
	{
		printf("���� ���� ���Դϴ�.\n");
		put_black();
	}
	else
	{
		printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n");
		put_white();
		return;
	}
	count_rowcolumn();
}
//����,���� �������� �Լ�
void count_rowcolumn()
{
	for (int i = 0; i < 19; ++i)
	{
		int b_cnt = 0;
		int w_cnt = 0;
		for (int j = 0; j < 19; ++j)
		{
			if (board[i][j] == 'B') ++b_cnt;
			else if (board[i][j] == 'W') ++w_cnt;
		}
		printf("����%d�� ������ ����: %d\n", i, b_cnt);
		printf("����%d�� �� ����: %d\n", i, w_cnt);
	}
	max_count_continuous();
}
//����,���� ���ӵ� ���� �ִ� ���� ���� �Լ�
void max_count_continuous()
{
	//����
	for (int i = 0; i < 19; ++i)
	{
		int max_continuous = 0;
		char max_type = '+';
		int max_start_garo = 0;
		int max_end_garo = 0;

		int b_cont = 0;
		int w_cont = 0;
		char prev_type = '+';
		for (int j = 0; j < 19; ++j)
		{
			if ((board[i][j] == 'B' || board[i][j] == 'W') && board[i][j] != '+')
			{
				if (board[i][j] == 'B')
				{
					++b_cont;
				}
				else
					++w_cont;
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
		if (max_type != '+')
		{
			printf("����%d�ٿ��� ���� ���� ���ӵ� ���� ����: %c ���� ����: %d\n", i, max_type, max_continuous);
			printf("���� ��ǥ: (%d,%d), �� ��ǥ: (%d,%d)\n", i, max_start_garo, i, max_end_garo);
		}
	}
	//����
	for (int j = 0; j < 19; ++j)
	{
		int max_continuous = 0;
		char max_type_sero = '+';
		int max_start_sero = 0;
		int max_end_sero = 0;

		int b_cont = 0;
		int w_cont = 0;
		char prev_type = '+';
		for (int i = 0; i < 19; ++i)
		{
			if ((board[i][j] == 'B' || board[i][j] == 'W') && board[i][j] != '+')
			{
				if (board[i][j] == 'B')
				{
					++b_cont;
				}
				else
					++w_cont;
			}
			else
			{
				if (b_cont > max_continuous)
				{
					max_continuous = b_cont;
					max_type_sero = 'B';
					max_start_sero = i - max_continuous;
					max_end_sero = i - 1;
				}
				else if (w_cont > max_continuous)
				{
					max_continuous = w_cont;
					max_type_sero = 'W';
					max_start_sero = i - max_continuous;
					max_end_sero = i - 1;
				}
				b_cont = (board[i][j] == 'B') ? 1 : 0;
				w_cont = (board[i][j] == 'W') ? 1 : 0;
				prev_type = board[i][j];
			}
		}
		if (b_cont > max_continuous)
		{
			max_continuous = b_cont;
			max_type_sero = 'B';
			max_start_sero = BOARD_SIZE - max_continuous;
			max_end_sero = BOARD_SIZE - 1;
		}
		else if (w_cont > max_continuous)
		{
			max_continuous = w_cont;
			max_type_sero = 'W';
			max_start_sero = BOARD_SIZE - max_continuous;
			max_end_sero = BOARD_SIZE - 1;
		}
		if (max_type_sero != '+')
		{
			printf("����%d�ٿ��� ���� ���� ���ӵ� ���� ����: %c ���� ����: %d\n", j, max_type_sero, max_continuous);
			printf("���� ��ǥ: (%d,%d), �� ��ǥ: (%d,%d)\n", max_start_sero, j, max_end_sero, j);
		}
	}
}
//���̺� ���� �Լ�
void save_game()
{
	FILE* file = fopen("omok_save.txt", "w");
	if (file == NULL)
	{
		printf("���� ���� ����.\n");
		return;
	}

	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			fprintf(file, "%c ", board[i][j]);
		}
		fprintf(file, "\n");
	}

	fclose(file);
}
void load_game()
{
	FILE* file = fopen("omok_save.txt", "r");
	if (file == NULL)
	{
		printf("���� ���� ����.\n");
		printf("�� ������ ����˴ϴ�.\n");
		return;
	}

	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			fscanf(file, " %c", &board[i][j]);
		}
	}

	fclose(file);
	printf("������ ���������� �ε�Ǿ����ϴ�.\n");
	draw_board();
}
void push(int x, int y, char stone_type)
{
	if (top_undo == STACK_SIZE - 1)
	{
		printf("������ ���� á���ϴ�.\n");
		return;
	}
	top_undo++;
	undoStack[top_undo].x = x;
	undoStack[top_undo].y = y;
	undoStack[top_undo].stone_type = stone_type; // ���� Ÿ�Ե� ����
}
void pop()
{
	if (top_undo == -1)
	{
		printf("������ ������ϴ�.\n");
		return;
	}

	// ���ŵǴ� ���� ��ǥ�� Ÿ���� �ӽ� ������ ����
	int x = undoStack[top_undo].x;
	int y = undoStack[top_undo].y;
	char stone_type = undoStack[top_undo].stone_type;

	if (top_redo < STACK_SIZE - 1)
	{
		// ���ÿ��� �����ϰ� top_undo�� ���ҽ�Ŵ
		top_undo--;

		// ���忡�� ���� �����ϰ� �ٽ� �׸�
		board[x][y] = '+';
		top_redo++;
		redoStack[top_redo].x = x;
		redoStack[top_redo].y = y;
		redoStack[top_redo].stone_type = stone_type;
		draw_board();
	}
	else
	{
		printf("redo ������ ���� á���ϴ�.\n");
		return;
	}
}
void redo()
{
	if (top_redo == -1)
	{
		printf("�ٽ� ���� ���� �����ϴ�.\n");
		return;
	}
	top_undo++;
	board[redoStack[top_redo].x][redoStack[top_redo].y] = redoStack[top_redo].stone_type; // ���� Ÿ�Կ� ���缭 �ٽ� ����
	top_redo--;
	draw_board();
}