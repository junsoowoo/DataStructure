#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXDICT 256
typedef struct {
	char name[30];
	char position[30];
	int hp,attack,defense;
}Dict;

typedef struct Node {
	Dict data;
	struct Node* next;
}Node;

Node* array2list(Dict list[], int size);
int ReadDataFromFile(const char* filename, Dict** list);
void Search_SL(Node* head, char searchname[]);
void Insert_SL(Node** head);
void Delete_SL(Node* head, char deletename[]);
void DeleteAll_SL(Node* head, char deleteposition[]);
void PrintAll_SL(Node* head);
void SortByName_SL(Node* head);

int main()
{
	int order;
	Dict* list;
	int size = ReadDataFromFile("LOLDic.txt", &list);
	Node* head = array2list(list, size);
	while (1)
	{
		printf("1.Search 2.Insert 3.Delete 4.DeleteAll 5.PrintAll 6.FindMaxHP 7.SortByHP\n");
		scanf("%d", &order);

		if (order == 1)
		{
			char searchname[30];
			printf("ã�� �̸� �Է�: \n");
			scanf("%s", searchname);
			Search_SL(head, searchname);
		}
		else if (order == 2)
		{
			Insert_SL(&head);
		}
		else if (order == 3)
		{
			char deletename[30];
			printf("������ �̸� �Է�: ");
			scanf("%s", deletename);
			Delete_SL(head, deletename);
		}
		else if (order == 4)
		{
			char deleteposition[30];
			printf("������ ������ �Է�: ");
			scanf("%s", deleteposition);
			DeleteAll_SL(head, deleteposition);

		}
		else if (order == 5)
		{
			PrintAll_SL(head);
		}
		else if (order == 6)
		{
			//FindMaxHP_SL(head);
		}
		else if (order == 7)
		{
			SortByName_SL(head);
		}
	}
}
int ReadDataFromFile(const char* filename, Dict** list)
{
	FILE* file = fopen(filename, "r");
	if (!file)
	{
		printf("���� ���� ����");
		return -1;
	}

	int capacity = 10;
	int size = 0;
	*list = (Dict*)malloc(capacity * sizeof(Dict));
	if (*list == NULL)
	{
		printf("�޸� �Ҵ� ����");
		fclose(file);
		return -1;
	}

	while (fscanf(file, "%s %s %d %d %d", (*list)[size].position, (*list)[size].name, &(*list)[size].hp, &(*list)[size].attack, &(*list)[size].defense) == 5)
	{
		size++;
		if (size >= capacity)
		{
			capacity *= 2;
			Dict* new_list = (Dict*)realloc(*list, capacity * sizeof(Dict));
			if (new_list == NULL)
			{
				printf("�޸� ���Ҵ� ����");
				free(*list);
				fclose(file);
				return -1;
			}
			*list = new_list;
		}
		if (size == 100)
			break;
	}

	fclose(file);
	return size;
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
		if (head == NULL)
		{
			newNode->next = NULL;
			head = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
	}
	return head;//ù ��� ����
}

void Search_SL(Node* head, char searchname[])
{
	Node* current = head;

	while (current != NULL)
	{
		if (strcmp(current->data.name, searchname) == 0)
		{
			printf("NAME: %s\n", current->data.name);
			printf("POSITION: %s\n", current->data.position);
			printf("HP: %d\n", current->data.hp);
			printf("MP: %d\n", current->data.attack);
			printf("SPEED: %d\n", current->data.defense);
			return;
		}
		current = current->next;
	}
	printf("ã�� �� �����ϴ�.\n");
}
void Insert_SL(Node** head)
{
	Dict data;
	printf("�߰��� è�Ǿ� �̸�: ");
	scanf("%s", data.name);
	printf("POSITION ?: ");
	scanf("%s", data.position);
	printf("HP : ");
	scanf("%d", &data.hp);
	printf("MP : ");
	scanf("%d", &data.attack);
	printf("SPEED : ");
	scanf("%d", &data.defense);
	
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) 
	{
		printf("�޸� �Ҵ� ����\n");
		return;
	}
	newNode->data = data;
	newNode->next = NULL;

	if (*head == NULL || (*head)->data.hp <= data.hp) 
	{
		newNode->next = *head;
		*head = newNode;
	}
	else 
	{
		Node* current = *head;
		while (current->next != NULL && current->next->data.hp > data.hp) 
		{
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
}
void Delete_SL(Node* head, char deletename[])
{
	Node* current = head;
	Node* prev = NULL;
	while (current != NULL) 
	{
		if (strcmp(current->data.name, deletename) == 0)
		{
			if (prev != NULL)
			{
				prev->next = current->next;
			}
			else
			{
				head = current->next;
			}
			printf("%s�� �����߽��ϴ�.\n", deletename);
			free(current); 
			return;
		}
		prev = current;
		current = current->next;
	}

	printf("%s�� �����ϴ�.\n", deletename);
}
void PrintAll_SL(Node* head)
{
	int num = 1;
	if (head == NULL)
	{
		printf("����Ʈ�� ������ϴ�.\n");
		return;
	}
	Node* current = head;
	while (1)
	{
		printf("%s�� ����\n", current->data.name);
		printf("POSITION: %s\n", current->data.position);
		printf("HP: %d\n", current->data.hp);
		printf("ATtACK: %d\n", current->data.attack);
		printf("DEFENSE: %d\n", current->data.defense);
		printf("%d\n", num);
		printf("\n");

		current = current->next;
		++num;
		if (current == head)
			break;
	}
	
}
void SortByName_SL(Node* head)
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
		Node* current = head;
		while (current->next != NULL)
		{
			if (strcmp(current->data.name, current->next->data.name) > 0)
			{
				Dict temp = current->data;
				current->data = current->next->data;
				current->next->data = temp;
				swapped = 1;
			}
			current = current->next;
		}
	}
	printf("�̸������� ����\n");
	PrintAll_SL(head);
}