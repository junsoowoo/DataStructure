#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAXDICT 256
typedef struct {
	char name[30];
	int hp, mp, speed, range;
	char position[10];
}Dict;

void Search(Dict list[], int size, char searchname[]);
void Insert(Dict list[], int size);
int Delete(Dict list[], int size, char deletename[]);
int DeleteAll(Dict list[], int size, char deleteposition[]);
void PrintAll(Dict list[], int size);
void FindMaxHP(Dict list[], int size);
void SortByHP(Dict list[], int size);

int main()
{
	int order;
	int size=22;
	Dict list[MAXDICT] = {
		{"Jayce", 3466, 8307, 452, 73, "mid"},
		{"Vayne", 3318, 2790, 390, 60, "support"},
		{"LeeSin",9864,6527,747,19,"support"},
		{"Teemo",1915, 1313, 700, 68, "mid"},
		{"Nami", 2968, 2153, 803, 74, "support"},
		{"Jinx", 2583, 3042, 123, 53, "jungle"},
		{"Cassiopeia",6067,7330	,683,24	,"top"},
		{"Ahri",4573,7079,177,79,"top"},
		{"Fiora",2591,9329,337,81,"jungle"},
		{"Zac",9864	,7272,40,49	, "bottom"},
		{"Janna",4922,2275,690,66, "jungle"},
		{"Ashe",7421,5549,428,31, "top"},
		{"Twitch",2980,7703,204,91,"mid"},
		{"Ezreal",3660,9835,274,44,"mid"},
		{"Sona",5655,8442,252,26,"bottom"},
		{"Lulu",3231,2014,503,32,"support"},
		{"Amumu",6763,3994,427,19, "jungle"},
		{"Master Yi",5737,7168,434,61,"top"},
		{"Jarvan",1895,3070,323,80,"mid"},
		{"Shen",4794, 9220,783,42,"mid"},
		{"Fizz",9864, 1913,433,38,"bottom"},
		{"Taric",6158, 7451,160,36,"bottom"}
	};
	
	while (1)
	{
		printf("시작할 프로그램을 입력\n1.Search 2.Insert 3.Delete 4.DeleteAll 5.PrintAll 6.FindMaxHP 7.SortByHP\n");
		scanf("%d", &order);

		if (order == 1)
		{
			char searchname[30];
			printf("찾을 챔피언의 이름 입력: \n");
			scanf("%s", searchname);
			Search(list, size,searchname);
		}
		else if (order == 2)
		{
			Insert(list, size);
		}
		else if (order == 3)
		{
			char deletename[30];
			printf("삭제할 챔피언의 이름 입력: \n");
			scanf("%s", deletename);
			if (Delete(list, size, deletename))
			{
				size--;
			}
		}
		else if (order == 4)
		{
			char deleteposition[30];
			printf("삭제할 포지션의 이름 입력: \n");
			scanf("%s", deleteposition);
			size=DeleteAll(list, size, deleteposition);
			
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
	for (int i = 0; i <= size; i++)
	{
		if (strcmp(list[i].name , searchname) == 0)
		{
			printf("%s의 정보\n",list[i].name);
			printf("HP: %d\n", list[i].hp);
			printf("MP: %d\n", list[i].mp);
			printf("SPEED: %d\n", list[i].speed);
			printf("RANGE: %d\n", list[i].range);
			printf("POSITION: %s\n", list[i].position);
			return;
		}
	}
	printf("입력한 이름의 챔피언이 없습니다.\n");
}
void Insert(Dict list[], int size)
{
	printf("새로운 챔피언의 정보 입력:\n");
	printf("이름: ");
	scanf("%s", list[size].name);
	printf("HP: ");
	scanf("%d", &list[size].hp);
	printf("MP: ");
	scanf("%d", &list[size].mp);
	printf("SPEED: ");
	scanf("%d", &list[size].speed);
	printf("RANGE: ");
	scanf("%d", &list[size].range);
	printf("POSITION: ");
	scanf("%s", list[size].position);
}
int Delete(Dict list[], int size, char deletename[])
{
	int found = 0;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(list[i].name, deletename) == 0)
		{
			for (int j = i; j < size-1; j++)
			{
				list[j] = list[j + 1];
			}
			found = 1;
			break;
		}
	}
	if (found)
	{
		printf("%s 챔피언이 삭제되었습니다.\n", deletename);
		return 1;
	}
	else
	{
		printf("입력한 이름의 챔피언이 없습니다.\n");
		return 0;
	}
}
int DeleteAll(Dict list[], int size, char deleteposition[])
{
	int found = 0;
	int newsize = size;
	for (int i = 0; i < newsize; i++)
	{
		if (strcmp(list[i].position, deleteposition) == 0)
		{
			found = 1;
			for (int j = i; j < newsize - 1; j++)
			{
				list[j] = list[j + 1];
			}
			newsize--;
			i--;
		}
	}
	if (found)
	{
		printf("%s 챔피언이 삭제되었습니다.\n", deleteposition);
		return newsize;
	}
	else
	{
		printf("%s 챔피언을 찾을 수 없습니다.\n", deleteposition);
		return size;
	}

}
void PrintAll(Dict list[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%s의 정보\n", list[i].name);
		printf("HP: %d\n", list[i].hp);
		printf("MP: %d\n", list[i].mp);
		printf("SPEED: %d\n", list[i].speed);
		printf("RANGE: %d\n", list[i].range);
		printf("POSITION: %s\n", list[i].position);
		printf("\n");
	}
}
void FindMaxHP(Dict list[], int size)
{
	int maxHP = 0;
	for (int i = 0; i < size; i++)
	{
		if (list[i].hp > maxHP)
		{
			maxHP = list[i].hp;
		}
	}
	int maxarr[MAXDICT];
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (list[i].hp == maxHP)
		{
			maxarr[count] = i;
			count++;
		}
	}
	for (int i = 0; i < count; i++)
	{
		printf("%s의 정보\n", list[maxarr[i]].name);
		printf("HP: %d\n", list[maxarr[i]].hp);
		printf("MP: %d\n", list[maxarr[i]].mp);
		printf("SPEED: %d\n", list[maxarr[i]].speed);
		printf("RANGE: %d\n", list[maxarr[i]].range);
		printf("POSITION: %s\n", list[i].position);
		printf("\n");
	}
}
void SortByHP(Dict list[], int size)
{
	Dict temp;
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (list[j].hp < list[j + 1].hp)
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
	printf("체력순으로 정렬\n");
	for (int i = 0; i < size; i++)
	{
		printf("%s의 정보\n", list[i].name);
		printf("HP: %d\n", list[i].hp);
		printf("MP: %d\n", list[i].mp);
		printf("SPEED: %d\n", list[i].speed);
		printf("RANGE: %d\n", list[i].range);
		printf("POSITION: %s\n", list[i].position);
		printf("\n");
	}
}