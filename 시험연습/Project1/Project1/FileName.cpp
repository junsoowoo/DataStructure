#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
	char name[30];
	int hp, mp, speed, range;
	char position[10];
}Dict;

void Search(Dict list[], int size, char searchname[]);
int Insert(Dict list[], int size);
int Delete(Dict list[], int size, char deletenam[]);
int DeleteAll(Dict list[], int size, char deleteposition[]);
void PrintAll(Dict list[], int size);
void FindMaxHP(Dict list[], int size);
void SortByHP(Dict list[], int size);

int main()
{
	Dict list[256] = {
	{"Jayce",3466,8307,452,73,"mid"},
	{"Vayne",3318,2790,90,60,"support"},
	{"Lee Sin",9864,6257,747,19,"support"},
	{"Teemo",1915,1313,700,68,"mid"},
	{"Nami"	,2968,2153,803,74,"support"},
	{"Jinx",2583,3042,123,53,"jungle"},
	{"Cassiopeia",6067,7330,683,24,"top"},
	{"Ahri",4573,7079,177,79,"top"},
	{"Fiora",2591,9329,337,81,"jungle"},
	{"Zac",9864,7272,405,49,"bottom"},
	{"Janna",4922,2275,690,66,"jungle"},
	{"Ashe",7421,5549,428,31,"top"},
	{"Twitch",2980,7703,204,91,"mid"},
	{"Ezreal",3660,9835,274,44,"mid"},
	{"Sona",5655,8442,252,26,"bottom"},
	{"Lulu",3231,2014,503,32,"support"},
	{"Amumu",6763,3994,427,19,"jungle"},
	{"Master Yi",5737,7168,434,61,"top"},
	{"Jarvan",1895,3070,323,80,"mid"},
	{"Shen	",4794,9220,783,42,"mid"},
	{"Fizz	",9864,1913,433,38,"bottom"},
	{"Taric",6158,7451,160,36,"bottom"}
	};

	int order;
	int size = 22;

	while (1)
	{
		printf("������ ���α׷��� ��ȣ�� �Է��ϼ���.\n1.Search 2.Insert 3.Delete 4.DeleteAll 5.PrintAll 6.FindMaxHP 7.SortByHP\n");
		scanf("%d", &order);
		if (order == 1)
		{
			char searchname[30];
			printf("���� ã�� è�Ǿ��� �̸��� �Է��ϼ���.\n");
			scanf("%s", searchname);
			Search(list, size, searchname);
		}
		else if (order == 2)
		{
			size = Insert(list, size);
		}
		else if (order == 3)
		{
			char deletename[30];
			printf("������ è�Ǿ��� �̸��� �Է��ϼ���.\n");
			scanf("%s", deletename);
			size = Delete(list, size, deletename);
		}
		else if (order == 4)
		{
			char deleteposition[30];
			printf("������ �������� �Է��ϼ���.\n");
			scanf("%s", deleteposition);
			size = DeleteAll(list, size, deleteposition);
		}
		else if (order == 5)
		{
			PrintAll(list, size);
		}
		else if (order == 6)
		{
			FindMaxHP(list, size);
		}
		else if (order == 7)
		{
			SortByHP(list, size);
		}
	}
}
void Search(Dict list[], int size, char searchname[])
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(list[i].name, searchname) == 0)
		{
			printf("%s�� ����\n", list[i].name);
			printf("hp: %d\n", list[i].hp);
			printf("mp: %d\n", list[i].mp);
			printf("speed: %d\n", list[i].speed);
			printf("range: %d\n", list[i].range);
			printf("position: %s\n", list[i].position);
			return;
		}
	}
	printf("%s�� ã�� ���߽��ϴ�\n", searchname);

}
//è�Ǿ� �߰�
int Insert(Dict list[], int size)
{
	printf("�߰��� è�Ǿ��� �̸��� �Է��ϼ���.\n");
	scanf("%s", list[size].name);
	printf("�߰��� è�Ǿ��� hp�� �Է��ϼ���.\n");
	scanf("%d", &list[size].hp);
	printf("�߰��� è�Ǿ��� mp�� �Է��ϼ���.\n");
	scanf("%d", &list[size].mp);
	printf("�߰��� è�Ǿ��� speed�� �Է��ϼ���.\n");
	scanf("%d", &list[size].speed);
	printf("�߰��� è�Ǿ��� range�� �Է��ϼ���.\n");
	scanf("%d", &list[size].range);
	printf("�߰��� è�Ǿ��� position�� �Է��ϼ���.\n");
	scanf("%s", list[size].position);
	return size + 1;
}
//�̸��� ����
int Delete(Dict list[], int size, char deletename[])
{
	int found = 0;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(list[i].name, deletename) == 0)
		{
			for (int j = i; j < size - 1; j++)
			{
				list[j] = list[j + 1];
			}
			found = 1;
		}
	}
	if (found)
	{
		printf("%s�� �����߽��ϴ�.\n", deletename);
		return size - 1;

	}
	else
	{
		printf("%s�� ã�� ���߽��ϴ�\n", deletename);
		return size;
	}
}
//�����Ǻ� ����
int DeleteAll(Dict list[], int size, char deleteposition[])
{
	int found = 0;
	int newsize = size;
	for (int i = 0; i < newsize; i++)
	{
		if (strcmp(list[i].position, deleteposition) == 0)
		{
			for (int j = i; j < newsize - 1; j++)
			{
				list[j] = list[j + 1];
			}
			found = 1;
			i--;
			newsize--;
		}
	}
	if (found)
	{
		printf("%s�� �����߽��ϴ�.\n", deleteposition);
		return newsize;

	}
	else
	{
		printf("%s�� ã�� ���߽��ϴ�\n", deleteposition);
		return size;
	}
}
//���� ���
void PrintAll(Dict list[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%s�� ����\n", list[i].name);
		printf("hp: %d\n", list[i].hp);
		printf("mp: %d\n", list[i].mp);
		printf("speed: %d\n", list[i].speed);
		printf("range: %d\n", list[i].range);
		printf("position: %s\n", list[i].position);
		printf("\n");
	}
}
//�ִ밪 ã��
void FindMaxHP(Dict list[], int size)
{
	int MaxHP = 0;
	for (int i = 0; i < size; i++)
	{
		if (list[i].hp > MaxHP)
		{
			MaxHP = list[i].hp;
		}
	}
	int maxarr[256];
	int cnt = 0;
	for (int i = 0; i < size; i++)
	{
		if (list[i].hp == MaxHP)
		{
			//maxarr�� �ִ� hp�� list������ ���� �Ǵϱ�
			maxarr[cnt] = i;
			cnt++;
		}
	}
	for (int i = 0; i < cnt; i++)
	{
		printf("%s�� ����\n", list[maxarr[i]].name);
		printf("hp: %d\n", list[maxarr[i]].hp);
		printf("mp: %d\n", list[maxarr[i]].mp);
		printf("speed: %d\n", list[maxarr[i]].speed);
		printf("range: %d\n", list[maxarr[i]].range);
		printf("position: %s\n", list[maxarr[i]].position);
		printf("\n");
	}
}
//�ִ����� ����
void SortByHP(Dict list[], int size)
{
	Dict temp;
	//��������
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j <= size - 1 - 1; j++)
		{
			if (list[j].hp < list[j + 1].hp)
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
	PrintAll(list, size);
}