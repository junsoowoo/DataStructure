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
		printf("������ ���α׷��� �Է�\n1.Search 2.Insert 3.Delete 4.DeleteAll 5.PrintAll 6.FindMaxHP 7.SortByHP\n");
		scanf("%d", &order);

		if (order == 1)
		{
			char searchname[30];
			printf("ã�� è�Ǿ��� �̸� �Է�: \n");
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
			printf("������ è�Ǿ��� �̸� �Է�: \n");
			scanf("%s", deletename);
			Delete_SL(head, deletename);

		}
		else if (order == 4)
		{
			char deleteposition[30];
			printf("������ �������� �̸� �Է�: \n");
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
		if (head == NULL) //���Ḯ��Ʈ�� �� ���
		{
			newNode->next = newNode; // ��� ����� ���� ��带 �ڱ� �ڽ����� �����Ͽ� ȯ�� ���� ����Ʈ ����
			head = newNode;
		}
		else
		{
			newNode->next = head->next; // ���ο� ����� ���� ��带 head�� ���� ���� ����
			head->next = newNode; // head�� ���� ��带 ���ο� ���� ����
			head = newNode; // head�� ���ο� ���� ������Ʈ
		}
	}

	return head;
}
void Search_SL(Node *head, char searchname[])
{
	if (head == NULL || head->next == head)
	{
		printf("����Ʈ�� ��� �ֽ��ϴ�.\n");
		return;
	}

	Node* current = head;

	while (1)
	{
		if (strcmp(current->data.name, searchname) == 0)
		{
			printf("%s�� ����\n", current->data.name);
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
	printf("�Է��� �̸��� è�Ǿ��� �����ϴ�.\n");
}
void Insert_SL(Node* head)
{
	Dict data;
	printf("�߰��� è�Ǿ��� �̸� �Է�: ");
	scanf("%s", data.name);
	printf("HP �Է�: ");
	scanf("%d", &data.hp);
	printf("MP �Է�: ");
	scanf("%d", &data.mp);
	printf("SPEED �Է�: ");
	scanf("%d", &data.speed);
	printf("RANGE �Է�: ");
	scanf("%d", &data.range);
	printf("POSITION �Է�: ");
	scanf("%s", data.position);

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (head == NULL)
	{
		newNode->next = newNode; // ��尡 �ϳ��� �ִ� ���, �ڱ� �ڽ��� ����Ŵ
		head = newNode; // ��带 ���ο� ���� ����
	}
	else
	{
		Node* current = head;
		while (current->next != head && current->next->data.hp > data.hp)
		{
			current = current->next;
		}
		newNode->next = current->next; // �� ����� ���� ��带 ���� ����� ���� ���� ����
		current->next = newNode; // ���� ����� ���� ��带 �� ���� ����
	}
	printf("è�Ǿ��� ���������� �߰��Ǿ����ϴ�.\n");
}
void Delete_SL(Node* head, char deletename[])
{
	if (head == NULL) 
	{
		printf("����Ʈ�� ��� �ֽ��ϴ�.\n");
		return;
	}
	Node* current = head;
	Node* prev = NULL;
	do {
		if (strcmp(current->data.name, deletename) == 0) 
		{
			// ������ ��带 ã���� �ش� ��带 ����
			if (prev != NULL) 
			{	
				prev->next = current->next;
			}
			else 
			{
				// ������ ��尡 ù ��° ����� ���
				head = current->next;
			}
			printf("%s è�Ǿ��� �����Ǿ����ϴ�.\n", deletename);
			free(current); // �޸� ����
			return;
		}
		prev = current;
		current = current->next;
	} while (current != head); // ����Ʈ�� �� ���� ���Ƽ� ù ��° ���� ���ƿ� ������ �ݺ�

	printf("%s è�Ǿ��� ã�� �� �����ϴ�.\n", deletename);
}
void DeleteAll_SL(Node* head, char deleteposition[]) {
	if (head == NULL) 
	{
		printf("����Ʈ�� ��� �ֽ��ϴ�.\n");
		return;
	}

	Node* current = head;
	Node* prev = NULL;
	int deletedCount = 0;

	do {
		if (strcmp(current->data.position, deleteposition) == 0) 
		{
			if (prev != NULL)   //ù��尡 �ƴ϶��
			{
				prev->next = current->next;  //1�� 3�� ����
			}
			else   //ù�����
			{
				if (current->next == current) // ����Ʈ�� �ϳ��� ��常 �ִ� ���
				{ 
					head = NULL;
					free(current);
					printf("%s �������� �����Ǿ����ϴ�.\n", deleteposition);
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
		printf("%s �������� %d�� �����Ǿ����ϴ�.\n", deleteposition, deletedCount);
	}
	else {
		printf("%s �������� ã�� �� �����ϴ�.\n", deleteposition);
	}
}
void PrintAll_SL(Node *head)
{
	if (head == NULL)
	{
		printf("����Ʈ�� ������ϴ�.\n");
		return;
	}
	Node* current = head;
	while (1)
	{
		printf("%s�� ����\n", current->data.name);
		printf("HP: %d\n", current->data.hp);
		printf("MP: %d\n", current->data.mp);
		printf("SPEED: %d\n", current->data.speed);
		printf("RANGE: %d\n", current->data.range);
		printf("POSITION: %s\n", current->data.position);
		printf("\n");

		current = current->next;

		if (current == head) // ó�� ��忡 �����ϸ� ����
			break;
	}
}
void FindMaxHP_SL(Node *head)
{
	if (head == NULL || head->next == head)
	{
		printf("����Ʈ�� ����ų� �ϳ��� ������ �ֽ��ϴ�.\n");
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
			maxarr[count] = current->data; // ���� è�Ǿ��� ������ ����
			count++;
		}
		else if (current->data.hp == maxHP)
		{
			maxarr[count] = current->data;// ���� è�Ǿ��� ������ ����
			count++;
		}
		current = current->next;
		if (current == head) // ó�� ���� ���ƿ��� �� ���� ����
			break;
	}

	for (int i = 0; i < count; i++)
	{
		printf("%s�� ����\n", maxarr[i].name);
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
		printf("����Ʈ�� ����ų� �ϳ��� ������ �ֽ��ϴ�.\n");
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
	printf("ü�¼����� ����\n");
	PrintAll_SL(head);
}