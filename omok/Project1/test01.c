//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//void put_black();
//void put_white();
//void draw_board();
//void count_rowcolumn();
//void max_count_continuous();
//#define BOARD_SIZE 19;
////�ʱⰪ ����
//char board[19][19];
//int b_cnt = 0;
//int w_cnt = 0;
//
//int main()
//{
//	//�ʱ� ������ �׸���
//	for (int i = 0; i < 19; i++)
//	{
//		for (int j = 0; j < 19; j++)
//		{
//			board[i][j] = '+';
//			printf("%c ", board[i][j]);
//		}
//		printf("\n");
//	}
//	//�� ���� ����Ŭ
//	while (1)
//	{
//		put_black();
//		put_white();
//	}
//	return 0;
//}
////�� ���� ��Ȳ �׸��� �Լ�
//void draw_board()
//{
//	for (int i = 0; i < 19; i++)
//	{
//		for (int j = 0; j < 19; j++)
//		{
//			printf("%c ", board[i][j]);
//		}
//		printf("\n");
//	}
//}
////���� �� ���� �Լ�
//void put_black()
//{
//	int x, y;
//
//	printf("�������� ���� ��ǥ�� �Է��ϼ���.(0~18).\n");
//	scanf("%d%d", &x, &y);
//	if (x < 0 || x >= 19 || y < 0 || y >= 19 || board[x][y] != '+')
//	{
//		printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n");
//		put_black();
//		return;
//	}
//	board[x][y] = 'B';
//	draw_board();
//	count_rowcolumn();
//}
////�� ���� �Լ�
//void put_white()
//{
//	int x, y;
//
//	printf("���� ���� ��ǥ�� �Է��ϼ���.(0~18).\n");
//	scanf("%d%d", &x, &y);
//	if (x < 0 || x >= 19 || y < 0 || y >= 19 || board[x][y] != '+')
//	{
//		printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n");
//		put_white();
//		return;
//	}
//	
//	board[x][y] = 'W';
//	draw_board();
//	count_rowcolumn();
//}
////����,���� �������� �Լ�
//void count_rowcolumn()
//{
//	for (int i = 0; i < 19; ++i)
//	{
//		int b_cnt = 0;
//		int w_cnt = 0;
//		for (int j = 0; j < 19; ++j)
//		{
//			if (board[i][j] == 'B') ++b_cnt;
//			else if (board[i][j] == 'W') ++w_cnt;
//		}
//		printf("����%d�� ������ ����: %d\n", i, b_cnt);
//		printf("����%d�� �� ����: %d\n", i, w_cnt);
//	}
//	max_count_continuous();
//}
////����,���� ���ӵ� ���� �ִ� ���� ���� �Լ�
//void max_count_continuous()
//{
//	//����
//	for (int i = 0; i < 19; ++i)
//	{
//		int max_continuous = 0;
//		char max_type = '+';
//		int max_start_garo = 0;
//		int max_end_garo = 0;
//
//		int b_cont = 0;
//		int w_cont = 0;
//		char prev_type = '+';
//		for (int j = 0; j < 19; ++j)
//		{
//			if ((board[i][j] == 'B' || board[i][j] == 'W') && board[i][j] != '+')
//			{
//				if (board[i][j] == 'B')
//				{
//					++b_cont;
//				}
//				else
//					++w_cont;
//			}
//			else
//			{
//				if (b_cont > max_continuous)
//				{
//					max_continuous = b_cont;
//					max_type = 'B';
//					max_start_garo = j - max_continuous;
//					max_end_garo = j - 1;
//				}
//				else if (w_cont > max_continuous)
//				{
//					max_continuous = w_cont;
//					max_type = 'W';
//					max_start_garo = j - max_continuous;
//					max_end_garo = j - 1;
//				}
//				b_cont = (board[i][j] == 'B') ? 1 : 0;
//				w_cont = (board[i][j] == 'W') ? 1 : 0;
//				prev_type = board[i][j];
//			}
//		}
//		if (b_cont > max_continuous)
//		{
//			max_continuous = b_cont;
//			max_type = 'B';
//			max_start_garo = BOARD_SIZE - max_continuous;
//			max_end_garo = BOARD_SIZE - 1;
//		}
//		else if (w_cont > max_continuous)
//		{
//			max_continuous = w_cont;
//			max_type = 'W';
//			max_start_garo = BOARD_SIZE - max_continuous;
//			max_end_garo = BOARD_SIZE - 1;
//		}
//		if (max_type != '+')
//		{
//			printf("����%d�ٿ��� ���� ���� ���ӵ� ���� ����: %c ���� ����: %d\n", i, max_type, max_continuous);
//			printf("���� ��ǥ: (%d,%d), �� ��ǥ: (%d,%d)\n", i, max_start_garo, i, max_end_garo);
//		}
//	}
//	//����
//	for (int j = 0; j < 19; ++j)
//	{
//		int max_continuous = 0;
//		char max_type_sero = '+';
//		int max_start_sero = 0;
//		int max_end_sero = 0;
//
//		int b_cont = 0;
//		int w_cont = 0;
//		char prev_type = '+';
//		for (int i = 0; i < 19; ++i)
//		{
//			if ((board[i][j] == 'B' || board[i][j] == 'W') && board[i][j] != '+')
//			{
//				if (board[i][j] == 'B')
//				{
//					++b_cont;
//				}
//				else
//					++w_cont;
//			}
//			else
//			{
//				if (b_cont > max_continuous)
//				{
//					max_continuous = b_cont;
//					max_type_sero = 'B';
//					max_start_sero = i - max_continuous;
//					max_end_sero = i - 1;
//				}
//				else if (w_cont > max_continuous)
//				{
//					max_continuous = w_cont;
//					max_type_sero = 'W';
//					max_start_sero = i - max_continuous;
//					max_end_sero = i - 1;
//				}
//				b_cont = (board[i][j] == 'B') ? 1 : 0;
//				w_cont = (board[i][j] == 'W') ? 1 : 0;
//				prev_type = board[i][j];
//			}
//		}
//		if (b_cont > max_continuous)
//		{
//			max_continuous = b_cont;
//			max_type_sero = 'B';
//			max_start_sero = BOARD_SIZE - max_continuous;
//			max_end_sero = BOARD_SIZE - 1;
//		}
//		else if (w_cont > max_continuous)
//		{
//			max_continuous = w_cont;
//			max_type_sero = 'W';
//			max_start_sero = BOARD_SIZE - max_continuous;
//			max_end_sero = BOARD_SIZE - 1;
//		}
//		if (max_type_sero != '+')
//		{
//			printf("����%d�ٿ��� ���� ���� ���ӵ� ���� ����: %c ���� ����: %d\n", j, max_type_sero, max_continuous);
//			printf("���� ��ǥ: (%d,%d), �� ��ǥ: (%d,%d)\n", max_start_sero, j, max_end_sero, j);
//		}
//	}
//}