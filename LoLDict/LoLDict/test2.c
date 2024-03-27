#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_CHAMPIONS 256
//챔피언 구조체 선언
typedef struct {
	char name[30];
	int hp, mp, speed, range;
	char position[10];

} Dict;
//함수 선언
void Search(Dict list[], int size ,char Searchname[]);
void Insert(Dict list[], int size);
int Delete(Dict list[], int size, char Deletename[]);
void DeleteAll(Dict list[], int size, char Deleteposition[]);
void PrintAll(Dict list[], int size);
void FindMaxHP(Dict list[],int size);
void SortHP(Dict list[], int size);

//메인
int main()
{
	//사전 배열 선언
	Dict list[256] = {
		{"Jayce", 3466, 8307, 452, 73, "mid"},
		{"Vayne", 3318, 2790, 390, 60, "support"},
		{"LeeSin",9864,6527,747,19,"support"},
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
	int size = 22;
	int order;
	while (1)
	{
		printf("명령어를 입력하세요.\n(1.Search, 2.Insert, 3.Delete, 4.DeleteAll, 5.PrintAll, 6.FindMaxHP, 7.SortHP)\n");
		scanf("%d", &order);
	
		if (order == 1)
		{
			char Searchname[30];
			printf("찾을 캐릭터의 이름을 입력: \n");
			scanf("%s", Searchname);
			Search(list, size, Searchname);
		}

		else if (order == 2)
		{
			Insert(list, size);
		}

		else if (order == 3)
		{
			char Deletename[30];
			printf("삭제할 캐릭터의 이름을 입력: \n");
			scanf("%s", Deletename);
			Delete(list, size, Deletename);
			size--;

		}

		else if (order == 4)
		{
			char Deletepostion[30];
			printf("삭제할 포지션의 이름을 입력: \n");
			scanf("%s", Deletepostion);
			DeleteAll(list, size, Deletepostion);

		}
		else if (order == 5)
		{
			PrintAll(list, size);
		}
		else if (order == 6)
		{
			FindMaxHP(list,size);
		}
		else if (order == 7)
		{
			SortHP(list, size);
		}
	}
	return 0;
}

//챔피언 찾기 함수
void Search(Dict list[], int size, char Searchname[])
{
	for (int i = 0; i <= size; i++)
	{
		if (strcmp(list[i].name, Searchname) == 0)
		{
			printf("챔피언 이름: %s\n", list[i].name);
			printf("체력: %d\n", list[i].hp);
			printf("마나: %d\n", list[i].mp);
			printf("속도: %d\n", list[i].speed);
			printf("사거리: %d\n", list[i].range);
			printf("포지션: %s\n", list[i].position);
			return;
		}
	}
	printf("해당하는 챔피언이 존재하지 않습니다.\n");
}
//챔피언 추가 함수
void Insert(Dict list[], int size)
{
	printf("새로운 챔피언의 정보를 입력하세요.\n");
	printf("이름: ");
	scanf("%s", list[size].name);
	printf("체력: ");
	scanf("%d", &list[size].hp);
	printf("마나: ");
	scanf("%d", &list[size].mp);
	printf("속도: ");
	scanf("%d", &list[size].speed);
	printf("사거리: ");
	scanf("%d", &list[size].range);
	printf("포지션: ");
	scanf("%s", list[size].position);
	size++;
}
//챔피언 삭제 함수
int Delete(Dict list[], int size, char Deletename[])
{
	int found = 0;
	for (int i = 0; i < size; i++) 
	{
		if (strcmp(list[i].name, Deletename) == 0) 
		{
			for (int j = i; j < size - 1; j++) 
			{
				list[j] = list[j + 1];
			}
			found = 1;
			break;
		}
	}
	if (found) 
	{
		printf("%s 챔피언이 삭제되었습니다.\n", Deletename);
		return 1;
	}
	else 
	{
		printf("%s 챔피언을 찾을 수 없습니다.\n", Deletename);
		return 0;
	}
}
//포지션 삭제 함수
void DeleteAll(Dict list[], int size, char Deleteposition[])
{
	int found = 0;
	for (int i = 0; i < size; i++) 
	{
		if (strcmp(list[i].position, Deleteposition) == 0) 
		{
			for (int j = i; j < size - 1; j++) 
			{
				list[j] = list[j + 1];
			}
			size--;
			found = 1;
		}
	}

	if (found) 
	{
		printf("%s 챔피언이 삭제되었습니다.\n", Deleteposition);
		return 1;
	}
	else 
	{
		printf("%s 챔피언을 찾을 수 없습니다.\n", Deleteposition);
		return 0;
	}
}
//모든 챔피언의 정보 출력 함수
void PrintAll(Dict list[], int size)
{
	printf("모든 챔피언 정보:\n");
	for (int i = 0; i < size; i++) 
	{
		printf("챔피언 이름: %s\n", list[i].name);
		printf("체력: %d\n", list[i].hp);
		printf("마나: %d\n", list[i].mp);
		printf("속도: %d\n", list[i].speed);
		printf("사거리: %d\n", list[i].range);
		printf("포지션: %s\n", list[i].position);
		printf("\n");
	}
}
//가장 체력이 큰 챔피언의 정보 출력 함수
void FindMaxHP(Dict list[], int size)
{
	int maxHP = 0;
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (list[i].hp > maxHP)
		{
			maxHP = list[i].hp;
		}
	}
	int maxarr[MAX_CHAMPIONS];
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
		printf("가장 체력이 큰 챔피언 정보:\n");
		printf("이름: %s\n", list[maxarr[i]].name);
		printf("체력: %d\n", list[maxarr[i]].hp);
		printf("마나: %d\n", list[maxarr[i]].mp);
		printf("속도: %d\n", list[maxarr[i]].speed);
		printf("사거리: %d\n", list[maxarr[i]].range);
		printf("포지션: %s\n", list[maxarr[i]].position);
	}
}
//체력이 큰 챔피언부터 순서대로 저장
void SortHP(Dict list[],int size)
{
	Dict temp;
	for (int i = 0; i < size - 1; i++) 
	{
		for (int j = 0; j < size - i - 1; j++) 
		{
			if (list[j].hp < list[j + 1].hp) 
			{
				//버블정렬
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
	printf("체력 순으로 정렬된 챔피언 정보:\n");
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
