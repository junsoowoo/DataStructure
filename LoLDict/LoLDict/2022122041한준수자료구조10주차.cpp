#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAXDICT 256
typedef struct {
	char position[30];
	char name[30];
	int hp, attack, defense;
}Dict;

typedef struct Node {
	Dict data;
	struct Node* next;
	struct Node* prev;
}Node;

Node* array2list_SL(Dict list[], int size);
Node* array2list_DL(Dict list[], int size);
void PrintAll_SL(Node* head);
void FindMaxHP_SL(Node* head);
void SortByName_SL(Node* head);
void PrintAll_DL(Node* head);
void FindMaxHP_DL(Node* head);
void SortByName_DL(Node* head);
int ReadDataFromFile(const char* filename, Dict** list);

int main()
{
	Dict* list;
	int size = ReadDataFromFile("LOLDic.txt", &list);
	if (size < 0)
	{
		printf("Failed to read data from file.\n");
		return 1;
	}
	int order;
	int onetwo;
	Node* head_SL = array2list_SL(list, size);
	Node* head_DL = array2list_SL(list, size);
	free(list);

	while (1)
	{
		printf("������ ���α׷��� �Է�\n1.PrintAll_SL 2.FindMaxHP_SL 3.SortByName_SL 4.PrintAll_DL 5.FindMaxHp_DL 6.SortByName_DL\n");
		scanf("%d", &order);

		if (order == 1)
		{
			PrintAll_SL(head_SL);
		}
		else if (order == 2)
		{
			FindMaxHP_SL(head_SL);
		}
		else if (order == 3)
		{
			SortByName_SL(head_SL);
		}
		else if (order == 4)
		{
			PrintAll_DL(head_DL);
		}
		else if (order == 5)
		{
			FindMaxHP_DL(head_DL);
		}
		else if (order == 6)
		{
			SortByName_DL(head_DL);
		}
	}
}

Node* array2list_SL(Dict list[], int size)
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
			head = newNode;
			head->next = head;
		}
		else
		{
			Node* temp = head;
			while (temp->next != head)
			{
				temp = temp->next;
			}
			temp->next = newNode;
			newNode->next = head;
		}
	}
	return head;
}
Node* array2list_DL(Dict list[], int size)
{
	if (size <= 0) return NULL;

	Node* head = NULL;
	Node* newNode = NULL;
	Node* prevNode = NULL;
	for (int i = 0; i < size; i++) {
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = list[i];
		newNode->next = NULL;  // ���� ���� ����Ʈ������ ���� ���� ���� ��� ��� NULL�� �ʱ�ȭ�մϴ�.

		if (head == NULL) {
			head = newNode;
			head->prev = NULL;  // ù ��° ����� ���� ���� NULL�Դϴ�.
		}
		else {
			prevNode->next = newNode;
			newNode->prev = prevNode;
		}

		prevNode = newNode;  // ���� ��带 ���� ���� �����մϴ�.
	}

	// ������ ����� ���� ��带 ó�� ���� �����Ͽ� ���� ������ ����ϴ�.
	prevNode->next = head;
	head->prev = prevNode;

	return head;
}

void PrintAll_SL(Node* head)
{
	time_t start, end;
	double result;
	start = time(NULL); // ���� �ð� ���� ����

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
		if (current == head) // ó�� ��忡 �����ϸ� ����
			break;
	}
	end = time(NULL); // �ð� ���� ��
	result = (double)(end - start);

	// ��� ���
	printf("%f��\n", result);
}
void FindMaxHP_SL(Node* head)
{
	time_t start, end;
	double result;
	start = time(NULL); // ���� �ð� ���� ����

	if (head == NULL)
	{
		printf("����Ʈ�� ������ϴ�.\n");
		return;
	}

	Node* current = head;
	int maxHP = head->data.hp;

	do
	{
		if (current->data.hp > maxHP)
		{
			maxHP = current->data.hp;
		}
		current = current->next;
	} while (current != head);

	current = head;

	do
	{
		if (current->data.hp == maxHP)
		{
			printf("%s�� ����\n", current->data.name);
			printf("POSITION: %s\n", current->data.position);
			printf("HP: %d\n", current->data.hp);
			printf("ATTACK: %d\n", current->data.attack);
			printf("DEFENSE: %d\n", current->data.defense);
			printf("\n");
		}
		current = current->next;
	} while (current != head);

	end = time(NULL); // �ð� ���� ��
	result = (double)(end - start);

	// ��� ���
	printf("%f��\n", result);
}
void SortByName_SL(Node* head)
{
	time_t start, end;
	double result;
	start = time(NULL); // ���� �ð� ���� ����

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
		while (current->next != head)
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
	end = time(NULL); // �ð� ���� ��
	result = (double)(end - start);

	// ��� ���
	printf("%f��\n", result);
}
void PrintAll_DL(Node* head)
{
	time_t start, end;
	double result;
	start = time(NULL); // ���� �ð� ���� ����

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
		printf("ATTACK: %d\n", current->data.attack);
		printf("DEFENSE: %d\n", current->data.defense);
		printf("\n");

		current = current->next;
		if (current == head) // ó�� ��忡 �����ϸ� ����
			break;
	};
	end = time(NULL); // �ð� ���� ��
	result = (double)(end - start);

	// ��� ���
	printf("%f��\n", result);
}
void FindMaxHP_DL(Node* head)
{
	time_t start, end;
	double result;
	start = time(NULL); // ���� �ð� ���� ����

	if (head == NULL)
	{
		printf("����Ʈ�� ������ϴ�.\n");
		return;
	}

	Node* current = head;
	int maxHP = head->data.hp;

	do
	{
		if (current->data.hp > maxHP)
		{
			maxHP = current->data.hp;
		}
		current = current->next;
	} while (current != head);

	current = head;

	do
	{
		if (current->data.hp == maxHP)
		{
			printf("%s�� ����\n", current->data.name);
			printf("POSITION: %s\n", current->data.position);
			printf("HP: %d\n", current->data.hp);
			printf("ATTACK: %d\n", current->data.attack);
			printf("DEFENSE: %d\n", current->data.defense);
			printf("\n");
		}
		current = current->next;
	} while (current != head);

	end = time(NULL); // �ð� ���� ��
	result = (double)(end - start);

	// ��� ���
	printf("%f��\n", result);
}
void SortByName_DL(Node* head)
{
	time_t start, end;
	double result;
	start = time(NULL); // ���� �ð� ���� ����

	if (head == NULL || head->next == head)
	{
		printf("����Ʈ�� ����ų� �ϳ��� ������ �ֽ��ϴ�.\n");
		return;
	}

	Node* current = head;
	while (1)
	{
		Node* nextNode = current->next;
		while (nextNode != head)
		{
			if (strcmp(current->data.name, nextNode->data.name) > 0)
			{
				// ����� �����͸� ��ȯ�մϴ�.
				Dict temp = current->data;
				current->data = nextNode->data;
				nextNode->data = temp;
			}
			nextNode = nextNode->next;
		}
		current = current->next;
		if (current == head) // ó�� ��忡 �����ϸ� ����
			break;
	}

	printf("�̸� ������ ���ĵ� ����Ʈ:\n");
	PrintAll_DL(head);
	end = time(NULL); // �ð� ���� ��
	result = difftime(end, start);

	// ��� ���
	printf("%f��\n", result);
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
		if (size == 1000)
			break;
	}

	fclose(file);
	return size;
}