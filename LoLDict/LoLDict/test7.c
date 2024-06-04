#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char name[30];
	char position[30];
	int hp, attack, defense;
}Dict;

typedef struct Node {
	Dict data;
	struct Node* next;
}Node;

Node* array2list(Dict list[], int size);
int ReadDataFromFile(const char* filename, Dict** list);
void Search_SL(Node* head, char searchname[]);
void Insert_SL(Node** head);
Node* Delete_SL(Node* head, char deletename[]);
Node* DeleteAll_SL(Node* head, char deleteposition[]);
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
		printf("1.Search 2.Insert 3.Delete 4.DeleteAll 5.PrintAll 6.FindMaxHP 7.SortByName\n");
		scanf("%d", &order);

		if (order == 1)
		{
			char searchname[30];
			printf("찾을 이름 입력: ");
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
			printf("삭제할 이름 입력: ");
			scanf("%s", deletename);
			head = Delete_SL(head, deletename);
		}
		else if (order == 4)
		{
			char deleteposition[30];
			printf("삭제할 포지션 입력: ");
			scanf("%s", deleteposition);
			head= DeleteAll_SL(head, deleteposition);

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
		printf("파일 열기 실패");
		return -1;
	}

	int capacity = 10;
	int size = 0;
	*list = (Dict*)malloc(capacity * sizeof(Dict));
	if (*list == NULL)
	{
		printf("메모리 할당 실패");
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
				printf("메모리 재할당 실패");
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
	return head;//첫 노드 리턴
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
	printf("찾을 수 없습니다.\n");
}
void Insert_SL(Node** head)
{
	Dict data;
	printf("추가할 챔피언 이름: ");
	scanf("%s", data.name);
	printf("POSITION : ");
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
		printf("메모리 할당 실패\n");
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
Node* Delete_SL(Node* head, char deletename[])
{
	Node* current = head;
	Node* prev = NULL;
	int found = 0;

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
			found = 1;
			printf("%s를 삭제했습니다.\n", deletename);
			free(current);
			return head;
		}
		prev = current;
		current = current->next;
	}
	printf("%s가 없습니다.\n", deletename);
}
Node* DeleteAll_SL(Node* head, char deleteposition[])
{
	Node* current = head;
	Node* prev = NULL;
	int found = 0;

	while (current != NULL && strcmp(current->data.position, deleteposition) == 0)
	{
		Node* temp = current;
		head = current->next;
		current = current->next;
		free(temp);
		found = 1;
	}

	while (current != NULL)
	{
		if (strcmp(current->data.position, deleteposition) == 0)
		{
			prev->next = current->next;
			free(current);
			current = prev->next;
			found = 1;
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}

	if (found)
		printf("%s 포지션의 챔피언을 삭제했습니다.\n", deleteposition);
	else
		printf("%s가 없습니다.\n", deleteposition);

	return head;
}
void PrintAll_SL(Node* head)
{
	if (head == NULL)
	{
		printf("리스트가 비었습니다.\n");
		return;
	}
	Node* current = head;
	while (current != NULL)
	{
		printf("%s의 정보\n", current->data.name);
		printf("POSITION: %s\n", current->data.position);
		printf("HP: %d\n", current->data.hp);
		printf("ATtACK: %d\n", current->data.attack);
		printf("DEFENSE: %d\n", current->data.defense);
		printf("\n");

		current = current->next;
	}
}
void SortByName_SL(Node* head)
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
	printf("이름순으로 정렬\n");
	PrintAll_SL(head);
}