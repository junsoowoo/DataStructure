//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <time.h>
//
//#define MAXDICT 256
//typedef struct {
//	char position[30];
//	char name[30];
//	int hp, attack, defense;
//}Dict;
//
//typedef struct Node {
//	Dict data;
//	struct Node* next;
//	struct Node* prev;
//}Node;
//
//Node* array2list_SL(Dict list[], int size);
//Node* array2list_DL(Dict list[], int size);
//void PrintAll_SL(Node* head);
//void FindMaxHP_SL(Node* head);
//void SortByName_SL(Node* head);
//void PrintAll_DL(Node* head);
//void FindMaxHP_DL(Node* head);
//void SortByName_DL(Node* head);
//int ReadDataFromFile(const char* filename, Dict** list);
//
//int main()
//{
//	Dict* list;
//	int size = ReadDataFromFile("LOLDic.txt", &list);
//	if (size < 0) 
//	{
//		printf("파일 열기 실패.\n");
//		return 1;
//	}
//	int order;
//	int onetwo;
//	Node* head_SL = array2list_SL(list, size);
//	free(list);
//
//	while (1)
//	{
//		printf("시작할 프로그램을 입력\n1.PrintAll_SL 2.FindMaxHP_SL 3.SortByName_SL\n");
//		scanf("%d", &order);
//
//		if (order == 1) 
//		{
//			PrintAll_SL(head_SL);
//		}
//		else if (order == 2) 
//		{
//			FindMaxHP_SL(head_SL);
//		}
//		else if (order == 3) 
//		{
//			SortByName_SL(head_SL);
//		}
//	}
//}
//
//Node* array2list_SL(Dict list[], int size)
//{
//	if (size <= 0) return NULL;
//
//	Node* head = NULL;
//	Node* newNode = NULL;
//	for (int i = 0; i < size; i++)
//	{
//		newNode = (Node*)malloc(sizeof(Node));
//		newNode->data = list[i];
//		if (head == NULL)
//		{
//			head = newNode;
//			head->next = head;
//		}
//		else
//		{
//			Node* temp = head;
//			while (temp->next != head)
//			{
//				temp = temp->next;
//			}
//			temp->next = newNode;
//			newNode->next = head;
//		}
//	}
//	return head;
//}
//void PrintAll_SL(Node* head)
//{
//	time_t start, end;
//	double result;
//	start = time(NULL); // 수행 시간 측정 시작
//
//	int num = 1;
//	if (head == NULL)
//	{
//		printf("리스트가 비었습니다.\n");
//		return;
//	}
//	Node* current = head;
//	while (1)
//	{
//		printf("%s의 정보\n", current->data.name);
//		printf("POSITION: %s\n", current->data.position);
//		printf("HP: %d\n", current->data.hp);
//		printf("ATtACK: %d\n", current->data.attack);
//		printf("DEFENSE: %d\n", current->data.defense);
//		printf("%d\n", num);
//		printf("\n");
//
//		current = current->next;
//		++num;
//		if (current == head) // 처음 노드에 도달하면 종료
//			break;
//	}
//	end = time(NULL); // 시간 측정 끝
//	result = (double)(end - start);
//
//	// 결과 출력
//	printf("%f초\n", result);
//}
//void FindMaxHP_SL(Node* head)
//{
//	time_t start, end;
//	double result;
//	start = time(NULL); // 수행 시간 측정 시작
//
//	if (head == NULL)
//	{
//		printf("리스트가 비었습니다.\n");
//		return;
//	}
//
//	Node* current = head;
//	int maxHP = head->data.hp;
//
//	do
//	{
//		if (current->data.hp > maxHP)
//		{
//			maxHP = current->data.hp;
//		}
//		current = current->next;
//	} while (current != head);
//
//	current = head;
//
//	do
//	{
//		if (current->data.hp == maxHP)
//		{
//			printf("%s의 정보\n", current->data.name);
//			printf("POSITION: %s\n", current->data.position);
//			printf("HP: %d\n", current->data.hp);
//			printf("ATTACK: %d\n", current->data.attack);
//			printf("DEFENSE: %d\n", current->data.defense);
//			printf("\n");
//		}
//		current = current->next;
//	} while (current != head);
//
//	end = time(NULL); // 시간 측정 끝
//	result = (double)(end - start);
//
//	// 결과 출력
//	printf("%f초\n", result);
//}
//void SortByName_SL(Node* head)
//{
//	time_t start, end;
//	double result;
//	start = time(NULL); // 수행 시간 측정 시작
//
//	if (head == NULL || head->next == head)
//	{
//		printf("리스트가 비었거나 하나를 가지고 있습니다.\n");
//		return;
//	}
//	int swapped = 1;
//	while (swapped)
//	{
//		swapped = 0;
//		Node* current = head;
//		while (current->next != head)
//		{
//			if (strcmp(current->data.name, current->next->data.name) > 0)
//			{
//				Dict temp = current->data;
//				current->data = current->next->data;
//				current->next->data = temp;
//				swapped = 1;
//			}
//			current = current->next;
//		}
//	}
//	printf("이름순으로 정렬\n");
//	PrintAll_SL(head);
//	end = time(NULL); // 시간 측정 끝
//	result = (double)(end - start);
//
//	// 결과 출력
//	printf("%f초\n", result);
//}
//int ReadDataFromFile(const char* filename, Dict** list)
//{
//	FILE* file = fopen(filename, "r");
//	if (!file) 
//	{
//		printf("파일 열기 실패");
//		return -1;
//	}
//
//	int capacity = 10;
//	int size = 0;
//	*list = (Dict*)malloc(capacity * sizeof(Dict));
//	if (*list == NULL)
//	{
//		printf("메모리 할당 실패");
//		fclose(file);
//		return -1;
//	}
//
//	while (fscanf(file, "%s %s %d %d %d", (*list)[size].position, (*list)[size].name, &(*list)[size].hp, &(*list)[size].attack, &(*list)[size].defense) == 5)
//	{
//		size++;
//		if (size >= capacity)
//		{
//			capacity *= 2;
//			Dict* new_list = (Dict*)realloc(*list, capacity * sizeof(Dict));
//			if (new_list == NULL)
//			{
//				printf("메모리 재할당 실패");
//				free(*list);
//				fclose(file);
//				return -1;
//			}
//			*list = new_list;
//		}
//		if (size == 10000)
//			break;
//	}
//
//	fclose(file);
//	return size;
//}