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

// 스택 구조체 정의
typedef struct {
	int x;
	int y;
	char stone_type;
} Stone;

//초기값 설정
#define BOARD_SIZE 19
#define STACK_SIZE 100
char board[19][19];
int b_cnt = 0;
int w_cnt = 0;
Stone undoStack[STACK_SIZE];
Stone redoStack[STACK_SIZE];
int top_undo = -1; // undo 스택의 top을 나타내는 변수
int top_redo = -1; // redo 스택의 top을 나타내는 변수

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
	int choice;
	printf("1. 새 게임\n");
	printf("2. 이어하기\n");
	printf("1번과 2번중 선택: ");
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
		printf("잘못된 입력.\n");
		return 1;
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
	int order;
	printf("저장을 원하면 0, 검은돌 진행을 원하면 1, 무르기를 원하면 2, 다시 놓기를 원하면 3, 돌 변경 4\n");
	scanf("%d", &order);
	if (order == 0)
	{
		save_game();
		printf("저장되었습니다.\n");
		exit(0);
	}
	else if (order == 1)
	{
		printf("검은돌이 놓일 좌표를 입력하세요.(0~18).\n");
		scanf("%d%d", &x, &y);
		if (x < 0 || x >= 19 || y < 0 || y >= 19 || board[x][y] != '+')
		{
			printf("잘못된 입력입니다. 다시 입력하세요.\n");
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
			printf("스택이 비었습니다.\n");
			return;
		}
		pop();
		draw_board();
	}
	else if (order == 3)
	{
		if (top_redo == -1)
		{
			printf("스택이 비었습니다.\n");
			return;
		}
		redo(); // redo 스택에서 돌 좌표를 pop하여 돌을 다시 놓음
	}
	else if (order == 4)
	{
		printf("이제 흰 돌입니다.\n");
		put_white();
	}
	else
	{
		printf("잘못된 입력입니다. 다시 입력하세요.\n");
		put_black();
		return;
	}
	count_rowcolumn();
}
//흰돌 놓는 함수
void put_white()
{
	int x, y;
	int order;
	printf("저장을 원하면 0, 흰돌 진행을 원하면 1, 무르기를 원하면 2, 다시 놓기를 원하면 3, 돌 변경 4\n");
	scanf("%d", &order);
	if (order == 1)
	{
		printf("흰 돌이 놓일 좌표를 입력하세요.(0~18).\n");
		scanf("%d%d", &x, &y);
		if (x < 0 || x >= 19 || y < 0 || y >= 19 || board[x][y] != '+')
		{
			printf("잘못된 입력입니다. 다시 입력하세요.\n");
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
		printf("저장되었습니다.\n");
		exit(0);
	}
	else if (order == 2)
	{
		if (top_undo == -1)
		{
			printf("스택이 비었습니다.\n");
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
			printf("스택이 비었습니다.\n");
			return;
		}
		redo(); // redo 스택에서 돌 좌표를 pop하여 돌을 다시 놓음
	}
	else if (order == 4)
	{
		printf("이제 검은 돌입니다.\n");
		put_black();
	}
	else
	{
		printf("잘못된 입력입니다. 다시 입력하세요.\n");
		put_white();
		return;
	}
	count_rowcolumn();
}
//가로,세로 개수세기 함수
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
		printf("가로%d줄 검은돌 개수: %d\n", i, b_cnt);
		printf("가로%d줄 흰돌 개수: %d\n", i, w_cnt);
	}
	max_count_continuous();
}
//가로,세로 연속된 돌의 최대 개수 세기 함수
void max_count_continuous()
{
	//가로
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
			printf("가로%d줄에서 가장 많이 연속된 돌의 종류: %c 돌의 개수: %d\n", i, max_type, max_continuous);
			printf("시작 좌표: (%d,%d), 끝 좌표: (%d,%d)\n", i, max_start_garo, i, max_end_garo);
		}
	}
	//세로
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
			printf("세로%d줄에서 가장 많이 연속된 돌의 종류: %c 돌의 개수: %d\n", j, max_type_sero, max_continuous);
			printf("시작 좌표: (%d,%d), 끝 좌표: (%d,%d)\n", max_start_sero, j, max_end_sero, j);
		}
	}
}
//세이브 관련 함수
void save_game()
{
	FILE* file = fopen("omok_save.txt", "w");
	if (file == NULL)
	{
		printf("파일 열기 실패.\n");
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
		printf("파일 열기 실패.\n");
		printf("새 게임이 진행됩니다.\n");
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
	printf("게임이 성공적으로 로드되었습니다.\n");
	draw_board();
}
void push(int x, int y, char stone_type)
{
	if (top_undo == STACK_SIZE - 1)
	{
		printf("스택이 가득 찼습니다.\n");
		return;
	}
	top_undo++;
	undoStack[top_undo].x = x;
	undoStack[top_undo].y = y;
	undoStack[top_undo].stone_type = stone_type; // 돌의 타입도 저장
}
void pop()
{
	if (top_undo == -1)
	{
		printf("스택이 비었습니다.\n");
		return;
	}

	// 제거되는 돌의 좌표와 타입을 임시 변수에 저장
	int x = undoStack[top_undo].x;
	int y = undoStack[top_undo].y;
	char stone_type = undoStack[top_undo].stone_type;

	if (top_redo < STACK_SIZE - 1)
	{
		// 스택에서 제거하고 top_undo를 감소시킴
		top_undo--;

		// 보드에서 돌을 제거하고 다시 그림
		board[x][y] = '+';
		top_redo++;
		redoStack[top_redo].x = x;
		redoStack[top_redo].y = y;
		redoStack[top_redo].stone_type = stone_type;
		draw_board();
	}
	else
	{
		printf("redo 스택이 가득 찼습니다.\n");
		return;
	}
}
void redo()
{
	if (top_redo == -1)
	{
		printf("다시 놓을 돌이 없습니다.\n");
		return;
	}
	top_undo++;
	board[redoStack[top_redo].x][redoStack[top_redo].y] = redoStack[top_redo].stone_type; // 돌의 타입에 맞춰서 다시 놓음
	top_redo--;
	draw_board();
}