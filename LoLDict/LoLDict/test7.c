#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXDICT 256
typedef struct {
	char name[30];
	int hp, mp, speed, range;
	char position[30];
}Dict;

typedef struct Node{
	Dict data;
	struct Node* next;
}Node;

Node* array2list(Dict list[], int size);
void Search_SL(Node *head, char searchname[]);
void Insert_SL(Node *head);
void Delete_SL(Node* head, char deletename[]);
void DeleteAll_SL(Node* head, char deleteposition[]);
void PrintAll_SL(Node *head);
void FindMaxHP_SL(Node *head);
void SortByHP_SL(Node*head);

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
	Node* head = array2list(list, size);
	while (1)	
	{
		printf("시작할 프로그램을 입력\n1.Search 2.Insert 3.Delete 4.DeleteAll 5.PrintAll 6.FindMaxHP 7.SortByHP\n");
		scanf("%d", &order);

		if (order == 1)
		{
			char searchname[30];
			printf("찾을 챔피언의 이름 입력: \n");
			scanf("%s", searchname);
			Search_SL(head, searchname);
		}
		else if (order == 2)
		{
			Insert_SL(head);
		}
		else if (order == 3)
		{
			char deletename[30];
			printf("삭제할 챔피언의 이름 입력: \n");
			scanf("%s", deletename);
			Delete_SL(head, deletename);

		}
		else if (order == 4)
		{
			char deleteposition[30];
			printf("삭제할 포지션의 이름 입력: \n");
			scanf("%s", deleteposition);
			DeleteAll_SL(head, deleteposition);

		}
		else if (order == 5)
		{
			PrintAll_SL(head);
		}
		else if (order == 6)
		{
			FindMaxHP_SL(head);
		}
		else if (order == 7)
		{
			SortByHP_SL(head);
		}
	}
}
Node* array2list(Dict list[], int size)
{
	if (size <= 0) return NULL;

	Node* head = NULL;
	Node* newNode = NULL;
	for (int i = 0; i < size; i++)
	{
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = list[i];
		newNode->next = NULL;
		if (head == NULL) //연결리스트가 빈 경우
		{
			newNode->next = newNode; // 헤드 노드의 다음 노드를 자기 자신으로 설정하여 환형 연결 리스트 만듦
			head = newNode;
		}
		else
		{
			newNode->next = head->next; // 새로운 노드의 다음 노드를 head의 다음 노드로 설정
			head->next = newNode; // head의 다음 노드를 새로운 노드로 설정
			head = newNode; // head를 새로운 노드로 업데이트
		}
	}

	return head;
}
void Search_SL(Node *head, char searchname[])
{
	if (head == NULL || head->next == head)
	{
		printf("리스트가 비어 있습니다.\n");
		return;
	}

	Node* current = head;

	while (1)
	{
		if (strcmp(current->data.name, searchname) == 0)
		{
			printf("%s의 정보\n", current->data.name);
			printf("HP: %d\n", current->data.hp);
			printf("MP: %d\n", current->data.mp);
			printf("SPEED: %d\n", current->data.speed);
			printf("RANGE: %d\n", current->data.range);
			printf("POSITION: %s\n", current->data.position);
			return;
		}

		current = current->next;

		if (current == head)
			break;
	}
	printf("입력한 이름의 챔피언이 없습니다.\n");
}
void Insert_SL(Node* head)
{
	Dict data;
	printf("추가할 챔피언의 이름 입력: ");
	scanf("%s", data.name);
	printf("HP 입력: ");
	scanf("%d", &data.hp);
	printf("MP 입력: ");
	scanf("%d", &data.mp);
	printf("SPEED 입력: ");
	scanf("%d", &data.speed);
	printf("RANGE 입력: ");
	scanf("%d", &data.range);
	printf("POSITION 입력: ");
	scanf("%s", data.position);

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (head == NULL)
	{
		newNode->next = newNode; // 노드가 하나만 있는 경우, 자기 자신을 가리킴
		head = newNode; // 헤드를 새로운 노드로 설정
	}
	else
	{
		Node* current = head;
		while (current->next != head && current->next->data.hp > data.hp)
		{
			current = current->next;
		}
		newNode->next = current->next; // 새 노드의 다음 노드를 현재 노드의 다음 노드로 설정
		current->next = newNode; // 현재 노드의 다음 노드를 새 노드로 설정
	}
	printf("챔피언이 성공적으로 추가되었습니다.\n");
}
void Delete_SL(Node* head, char deletename[])
{
	if (head == NULL) 
	{
		printf("리스트가 비어 있습니다.\n");
		return;
	}
	Node* current = head;
	Node* prev = NULL;
	do {
		if (strcmp(current->data.name, deletename) == 0) 
		{
			// 삭제할 노드를 찾으면 해당 노드를 삭제
			if (prev != NULL) 
			{	
				prev->next = current->next;
			}
			else 
			{
				// 삭제할 노드가 첫 번째 노드일 경우
				head = current->next;
			}
			printf("%s 챔피언이 삭제되었습니다.\n", deletename);
			free(current); // 메모리 해제
			return;
		}
		prev = current;
		current = current->next;
	} while (current != head); // 리스트를 한 바퀴 돌아서 첫 번째 노드로 돌아올 때까지 반복

	printf("%s 챔피언을 찾을 수 없습니다.\n", deletename);
}
void DeleteAll_SL(Node* head, char deleteposition[]) {
	if (head == NULL) 
	{
		printf("리스트가 비어 있습니다.\n");
		return;
	}

	Node* current = head;
	Node* prev = NULL;
	int deletedCount = 0;

	do {
		if (strcmp(current->data.position, deleteposition) == 0) 
		{
			if (prev != NULL)   //첫노드가 아니라면
			{
				prev->next = current->next;  //1번 3번 연결
			}
			else   //첫노드라면
			{
				if (current->next == current) // 리스트에 하나의 노드만 있는 경우
				{ 
					head = NULL;
					free(current);
					printf("%s 포지션이 삭제되었습니다.\n", deleteposition);
					return;
				}
				else 
				{
					head = current->next;
				}
			}
			Node* temp = current;
			current = current->next;
			free(temp);
			deletedCount++;
		}
		else {
			prev = current;
			current = current->next;
		}
	} while (current != head);

	if (deletedCount > 0) {
		printf("%s 포지션이 %d개 삭제되었습니다.\n", deleteposition, deletedCount);
	}
	else {
		printf("%s 포지션을 찾을 수 없습니다.\n", deleteposition);
	}
}
void PrintAll_SL(Node *head)
{
	if (head == NULL)
	{
		printf("리스트가 비었습니다.\n");
		return;
	}
	Node* current = head;
	while (1)
	{
		printf("%s의 정보\n", current->data.name);
		printf("HP: %d\n", current->data.hp);
		printf("MP: %d\n", current->data.mp);
		printf("SPEED: %d\n", current->data.speed);
		printf("RANGE: %d\n", current->data.range);
		printf("POSITION: %s\n", current->data.position);
		printf("\n");

		current = current->next;

		if (current == head) // 처음 노드에 도달하면 종료
			break;
	}
}
void FindMaxHP_SL(Node *head)
{
	if (head == NULL || head->next == head)
	{
		printf("리스트가 비었거나 하나를 가지고 있습니다.\n");
		return;
	}

	Node* current = head;

	int count = 0;
	Dict maxarr[MAXDICT];
	int maxHP = 0;

	while (1)
	{
		if (current->data.hp > maxHP)
		{
			maxHP = current->data.hp;
			count = 0;
			maxarr[count] = current->data; // 현재 챔피언의 정보를 저장
			count++;
		}
		else if (current->data.hp == maxHP)
		{
			maxarr[count] = current->data;// 현재 챔피언의 정보를 저장
			count++;
		}
		current = current->next;
		if (current == head) // 처음 노드로 돌아왔을 때 루프 종료
			break;
	}

	for (int i = 0; i < count; i++)
	{
		printf("%s의 정보\n", maxarr[i].name);
		printf("HP: %d\n", maxarr[i].hp);
		printf("MP: %d\n", maxarr[i].mp);
		printf("SPEED: %d\n", maxarr[i].speed);
		printf("RANGE: %d\n", maxarr[i].range);
		printf("POSITION: %s\n", maxarr[i].position);
		printf("\n");
	}
}
void SortByHP_SL(Node *head)
{
	if (head == NULL || head->next == head)
	{
		printf("리스트가 비었거나 하나를 가지고 있습니다.\n");
		return;
	}
	int swapped = 1;
	while (swapped)
	{
		swapped = 0;
		Node* ptr = head;
		while (ptr->next != head)
		{
			if (ptr->data.hp < ptr->next->data.hp)
			{
				Dict temp = ptr->data;
				ptr->data = ptr->next->data;
				ptr->next->data = temp;
				swapped = 1;
			}
			ptr = ptr->next;
		}
	}
	printf("체력순으로 정렬\n");
	PrintAll_SL(head);
}