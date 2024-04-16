#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAXDICT 256
typedef struct {
	char name[30];
	int hp, mp, speed, range;
	char position[10];
}Dict;

void Search_R(int index, Dict list[], int size, char searchname[]);
void Insert_R(int index, Dict list[], int size);
void Delete_R(int index, Dict list[], int size, char deletename[]);
void DeleteAll_R(int index, Dict list[], int size, char deleteposition[]);
void PrintAll_R(int index, Dict list[], int size);
void FindMaxHP_R(int index, Dict list[], int size);
void SortByHP_R(int index, Dict list[], int size);

int main()
{
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
	int size = 22;
	int order;
	while (1)
	{
		printf("시작할 프로그램을 입력\n1.Search 2.Insert 3.Delete 4.DeleteAll 5.PrintAll 6.FindMaxHP 7.SortByHP\n");
		scanf("%d", &order);

		if (order == 1)
		{
			char searchname[30];
			printf("찾을 챔피언의 이름 입력: \n");
			scanf("%s", searchname);
			Search_R(0, list, size, searchname);
		}
		else if (order == 2)
		{
			Insert_R(0, list, size);
		}
		else if (order == 3)
		{
			char deletename[30];
			printf("삭제할 챔피언의 이름 입력: \n");
			scanf("%s", deletename);
			Delete_R(0, list, size, deletename);

		}
		else if (order == 4)
		{
			char deleteposition[30];
			printf("삭제할 포지션의 이름 입력: \n");
			scanf("%s", deleteposition);
			DeleteAll_R(0, list, size, deleteposition);

		}
		else if (order == 5)
		{
			PrintAll_R(0, list, size);
		}
		else if (order == 6)
		{
			FindMaxHP_R(0, list, size);
		}
		else if (order == 7)
		{
			SortByHP_R(0, list, size);
		}
	}
}

void Search_R(int index, Dict list[], int size, char searchname[])
{
	if (index >= size)
	{
		printf("입력한 이름의 챔피언이 없습니다.\n");
		return;
	}
	if (strcmp(list[index].name, searchname) == 0)
	{
		printf("%s의 정보\n", list[index].name);
		printf("HP: %d\n", list[index].hp);
		printf("MP: %d\n", list[index].mp);
		printf("SPEED: %d\n", list[index].speed);
		printf("RANGE: %d\n", list[index].range);
		printf("POSITION: %s\n", list[index].position);
		return;
	}

	else Search_R(index + 1, list, size, searchname);
}
void Insert_R(int index, Dict list[], int size)
{
	if (index == size)
	{
		printf("추가할 챔피언의 정보:\n");
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
		size++;
	}
	else Insert_R(index + 1, list, size);
}
void Delete_R(int index, Dict list[], int size, char deletename[])
{
	if (index >= size) return;
	if (strcmp(list[index].name, deletename) == 0)
	{
		//그냥 삭제한다는 플래그를 만듬. 이 자리의 값에 대해 직접적으로 묻지 않도록 작성 예정.
		printf("%s 챔피언이 삭제되었습니다.\n", deletename);
		list[index].name[0] = '\0';
		Delete_R(index + 1, list, size, deletename);
		return;
	}
	Delete_R(index + 1, list, size, deletename);
}
void DeleteAll_R(int index, Dict list[], int size, char deleteposition[])
{
	if (index >= size)
		return printf("%s 포지션이 삭제되었습니다.\n", deleteposition);
	if (strcmp(list[index].position, deleteposition) == 0)
	{
		//그냥 삭제한다는 플래그를 만듬. 이 자리의 값에 대해 직접적으로 묻지 않도록 작성 예정.
		list[index].name[0] = '\0';
		DeleteAll_R(index + 1, list, size, deleteposition);
		return;
	}
	DeleteAll_R(index + 1, list, size, deleteposition);
}
void PrintAll_R(int index, Dict list[], int size)
{
	if (index >= size) return;
	if (list[index].name[0] != '\0')
	{
		printf("%s의 정보\n", list[index].name);
		printf("HP: %d\n", list[index].hp);
		printf("MP: %d\n", list[index].mp);
		printf("SPEED: %d\n", list[index].speed);
		printf("RANGE: %d\n", list[index].range);
		printf("POSITION: %s\n", list[index].position);
		printf("\n");
	}
	PrintAll_R(index + 1, list, size);
}
void FindMaxHP_R(int index, Dict list[], int size)
{
	static int maxHP = 0;
	static int maxarr[MAXDICT];
	static int count = 0;
	if (index >= size)
	{
		// 최대 체력을 가진 챔피언들의 정보 출력
		for (int i = 0; i < count; i++)
		{
			printf("%s의 정보\n", list[maxarr[i]].name);
			printf("HP: %d\n", list[maxarr[i]].hp);
			printf("MP: %d\n", list[maxarr[i]].mp);
			printf("SPEED: %d\n", list[maxarr[i]].speed);
			printf("RANGE: %d\n", list[maxarr[i]].range);
			printf("POSITION: %s\n", list[maxarr[i]].position);
			printf("\n");
		}
		return;
	}
	if (list[index].hp > maxHP)
	{
		maxHP = list[index].hp;
		count = 0; // 최대 체력을 가진 챔피언들의 개수 초기화
		maxarr[count] = index; // 현재 챔피언의 인덱스 저장
		++count;
	}
	else if (list[index].hp == maxHP)
	{
		count++;	
	}
	FindMaxHP_R(index + 1, list, size);
}
void SortByHP_R(int index, Dict list[], int size)
{
	if (index >= size - 1)
	{
		printf("체력순으로 정렬\n");
		PrintAll_R(0, list, size);
		return;
	}
	//버블정렬
	if (list[index].hp < list[index + 1].hp)
	{
		Dict temp = list[index];
		list[index] = list[index + 1];
		list[index + 1] = temp;
	}
	SortByHP_R(index + 1, list, size);
}
