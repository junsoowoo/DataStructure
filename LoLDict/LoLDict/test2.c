#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_CHAMPIONS 256
//è�Ǿ� ����ü ����
typedef struct {
	char name[30];
	int hp, mp, speed, range;
	char position[10];

} Dict;
//�Լ� ����
void Search(Dict list[], int size ,char Searchname);
void Insert(Dict list[], int size);
void Delete(char name);
void DeleteAll(char postion);
void PrintAll();
void FindMaxHP();
void SortHP(int a);
//���� �迭 ����

//����
int main()
{
	Dict list[256] = {
		{"Jayce", 3466, 8307, 452, 73, "mid"},
		{"Vayne", 3318, 2790, 390, 60, "support"},
		{"Teemo",1915, 1313, 700, 68, "mid"},
		{"Nami", 2968, 2153, 803, 74, "support"},
		{"Jinx", 2583, 3042, 123, 53, "jungle"},
		{"Cassiopeia",6067,7330	,683,24	, "top"},
		{"Ahri",4573,7079,177,79,"top"},
		{"Fiora",2591,9329,337,81,"jungle"},
		{"Zac",9864	,7272,40,49	, "bottom"},
		{"Janna",4922,2275,690,66, "jungle"},
		{"Ashe",7421,5549,428,31, "top"},
		{"Twitch",2980,7703,204,91, "mid"},
		{"Ezreal",3660,9835,274,44, "mid"},
		{"Sona",5655,8442,252,26,"bottom"},
		{"Lulu",3231,2014,503,32,"support"},
		{"Amumu",6763,3994,427,19, "jungle"},
		{"Master Yi",5737,7168,434,61,"top"},
		{"Jarvan",1895,3070,323,80,"mid"},
		{"Shen",4794, 9220,783,42,"mid"},
		{"Fizz",9864, 1913,433,38,"bottom"},
		{"Taric",6158, 7451,160,36,"bottom"}

	};
	int size = 20;
	int order;
	while (1)
	
	{
		printf("��ɾ �Է��ϼ���.\n(1.Search, 2.Insert, 3.Delete, 4.DeleteAll, 5.PrintAll, 6.FindMaxHP, 7.SortHP)\n");
		scanf("%d", &order);
	
		if (order == 1)
		{
			char Searchname[30];
			printf("ã�� ĳ������ �̸��� �Է�: \n");
			scanf("%s", Searchname);
			Search(list, size, Searchname);
		}

		else if (order == 2)
		{
			Insert(list, size);
		}

		else if (order == 3)
		{

		}

		else if (order == 4)
		{

		}
		else if (order == 5)
		{

		}
		else if (order == 6)
		{

		}
		else if (order == 7)
		{

		}
	}
	return 0;
}

//è�Ǿ� ã�� �Լ�
void Search(Dict list[], int size, char Searchname[])
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(list[i].name, Searchname) == 0)
		{
			printf("è�Ǿ� �̸�: %s\n", list[i].name);
			printf("ü��: %d\n", list[i].hp);
			printf("����: %d\n", list[i].mp);
			printf("�ӵ�: %d\n", list[i].speed);
			printf("��Ÿ�: %d\n", list[i].range);
			printf("������: %s\n", list[i].position);
			return;
		}
	}
	printf("�ش��ϴ� è�Ǿ��� �������� �ʽ��ϴ�.\n");
}
//è�Ǿ� �߰� �Լ�
void Insert(Dict list[], int size)
{
	printf("���ο� è�Ǿ��� ������ �Է��ϼ���.\n");
	printf("�̸�: ");
	scanf("%s", list[size].name);
	printf("ü��: ");
	scanf("%d", &list[size].hp);
	printf("����: ");
	scanf("%d", &list[size].mp);
	printf("�ӵ�: ");
	scanf("%d", &list[size].speed);
	printf("��Ÿ�: ");
	scanf("%d", &list[size].range);
	printf("������: ");
	scanf("%s", list[size].position);
	size++;
}
//è�Ǿ� ���� �Լ�
void Delete(char name)
{

}
//������ ���� �Լ�
void DeleteAll(char postion)
{

}
//��� è�Ǿ��� ���� ��� �Լ�
void PrintAll()
{

}
//���� ü���� ū è�Ǿ��� ���� ��� �Լ�
void FindMaxHP()
{
	int MaxHP = 0;

}
//ü���� ū è�Ǿ���� ������� ����
void SortHP(int a)
{


}
