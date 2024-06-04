//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <time.h>
//
//
//typedef struct {
//	char position[30];
//	char name[30];
//	int hp, attack, defense;
//} Dict;
//
//typedef struct Node {
//	Dict data;
//	struct Node* next;
//	struct Node* prev;
//} Node;
//
//typedef struct tree_pointer {
//	Dict data;
//	struct tree_pointer* left;
//	struct tree_pointer* right;
//} tree_pointer;
//
//Node* array2list_SL(Dict list[], int size);
//int ReadDataFromFile(const char* filename, Dict** list);
//void PrintAll_SL(Node* head);
//void SortByName_SL(Node* head);
//tree_pointer* list2BT(tree_pointer* root, Dict data);
//void SearchByName_BT(tree_pointer* root, const char* key);
//void Insert_BT(tree_pointer** root);
//void Delete_BT(tree_pointer** root, const char* key);
//void PrintAll_BT(tree_pointer* root);
//void SortByName_BT(tree_pointer* root);
//void FreeTree(tree_pointer* root);
//
//int main()
//{
//	Dict* list;
//	int size = ReadDataFromFile("LOLDic.txt", &list);
//	if (size < 0)
//	{
//		printf("���� ���� ����.\n");
//		return 1;
//	}
//
//	Node* head_SL = array2list_SL(list, size);
//	free(list);
//
//	printf("SortByName_SL�� ����ð�\n");
//	//SortByName_SL(head_SL);
//
//	// ���� ����Ʈ�� ���� Ž�� Ʈ���� ��ȯ
//	tree_pointer* root = NULL;
//	Node* current = head_SL;
//	do {
//		root = list2BT(root, current->data);
//		current = current->next;
//	} while (current != head_SL);
//	int order;
//	char key[30];
//	while (1)
//	{
//		printf("������ ���α׷��� �Է�\n1.SearchByName_BT 2.Insert_BT 3.Delete_BT 4.PrintAll_BT 5.SortByName_BT\n");
//		scanf("%d", &order);
//
//		if (order == 1)
//		{
//			printf("�˻��� �̸��� �Է��ϼ���: ");
//			scanf("%s", key);
//			SearchByName_BT(root,key);
//		}
//		else if (order == 2)
//		{
//			Insert_BT(&root);
//		}
//		else if (order == 3)
//		{
//			printf("������ �̸��� �Է��ϼ���: ");
//			scanf("%s", key);
//			Delete_BT(&root,key);
//		}
//		else if (order == 4)
//		{
//			clock_t start, end;
//			double cpu_time;
//			start = clock();
//
//			PrintAll_BT(root);
//
//			end = clock();
//			cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
//			printf("PrintAll_BT �Լ��� ���� �ð�: %f ��\n", cpu_time);
//		}
//		else if (order == 5)
//		{
//			clock_t start, end;
//			double cpu_time;
//			start = clock();
//
//			SortByName_BT(root);
//
//			end = clock();
//			cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
//			printf("PrintAll_BT �Լ��� ���� �ð�: %f ��\n", cpu_time);
//		}
//	}
//	// �޸� ����
//	FreeTree(root);
//
//	return 0;
//}
//
////�����ϱ� ���� �ϴ� 10000���� �о��
//int ReadDataFromFile(const char* filename, Dict** list)
//{
//	FILE* file = fopen(filename, "r");
//	if (!file)
//	{
//		printf("���� ���� ����");
//		return -1;
//	}
//
//	int capacity = 10;
//	int size = 0;
//	*list = (Dict*)malloc(capacity * sizeof(Dict));
//	if (*list == NULL)
//	{
//		printf("�޸� �Ҵ� ����");
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
//				printf("�޸� ���Ҵ� ����");
//				free(*list);
//				fclose(file);
//				return -1;
//			}
//			
//			*list = new_list;
//		}
//		if (size == 10000)
//			break;
//	}
//
//	fclose(file);
//	return size;
//}
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
//	start = time(NULL);
//
//	int num = 1;
//	if (head == NULL)
//	{
//		printf("����Ʈ�� ������ϴ�.\n");
//		return;
//	}
//	Node* current = head;
//	while (1)
//	{
//		printf("%s�� ����\n", current->data.name);
//		printf("POSITION: %s\n", current->data.position);
//		printf("HP: %d\n", current->data.hp);
//		printf("ATtACK: %d\n", current->data.attack);
//		printf("DEFENSE: %d\n", current->data.defense);
//		printf("%d\n", num);
//		printf("\n");
//
//		current = current->next;
//		++num;
//		if (current == head)
//			break;
//	}
//	end = time(NULL);
//	result = (double)(end - start);
//
//	printf("%f��\n", result);
//}
//void SortByName_SL(Node* head)
//{
//	time_t start, end;
//	double result;
//	start = time(NULL);
//
//	if (head == NULL || head->next == head)
//	{
//		printf("����Ʈ�� ����ų� �ϳ��� ������ �ֽ��ϴ�.\n");
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
//	printf("�̸������� ����\n");
//	PrintAll_SL(head);
//	end = time(NULL);
//	result = difftime(end, start);
//	printf("%f��\n", result);
//}
//tree_pointer* list2BT(tree_pointer* root, Dict data) 
//{
//	if (root == NULL) {
//		tree_pointer* newNode = (tree_pointer*)malloc(sizeof(tree_pointer));
//		if (newNode == NULL) {
//			printf("�޸� �Ҵ� ����\n");
//			return NULL;
//		}
//		newNode->data = data;
//		newNode->left = newNode->right = NULL;
//		return newNode;
//	}
//	if (strcmp(data.name, root->data.name) < 0) 
//	{
//		root->left = list2BT(root->left, data);
//	}
//	else 
//	{
//		root->right = list2BT(root->right, data);
//	}
//	return root;
//}
//void SearchByName_BT(tree_pointer* root, const char* key)
//{
//	clock_t start, end;
//	double cpu_time;
//	start = clock();
//	if (root == NULL) 
//	{
//		printf("Ʈ���� ��� �ְų� ��带 ã�� �� �����ϴ�.\n");
//		return;
//	}
//
//	if (strcmp(key, root->data.name) == 0) 
//	{
//		printf("��� ã��: %s�� ����\n", root->data.name);
//		printf("POSITION: %s\n", root->data.position);
//		printf("HP: %d\n", root->data.hp);
//		printf("ATTACK: %d\n", root->data.attack);
//		printf("DEFENSE: %d\n", root->data.defense);
//		printf("\n");
//		end = clock();
//		cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
//		printf("SearchByName_BT �Լ��� ���� �ð�: %f ��\n", cpu_time);
//	}
//	else if (strcmp(key, root->data.name) < 0) 
//	{
//		SearchByName_BT(root->left, key);
//	}
//	else 
//	{
//		SearchByName_BT(root->right, key);
//	}
//	
//}
//void Insert_BT(tree_pointer** root)
//{
//	Dict new_data;
//
//	printf("���ο� �̸��� �Է��ϼ���: ");
//	scanf("%s", new_data.name);
//	printf("�������� �Է��ϼ���: ");
//	scanf("%s", new_data.position);
//	printf("ü���� �Է��ϼ���: ");
//	scanf("%d", &new_data.hp);
//	printf("���ݷ��� �Է��ϼ���: ");
//	scanf("%d", &new_data.attack);
//	printf("������ �Է��ϼ���: ");
//	scanf("%d", &new_data.defense);
//
//	clock_t start, end;
//	double cpu_time;
//	start = clock();
//
//	tree_pointer* new_node = (tree_pointer*)malloc(sizeof(tree_pointer));
//	if (new_node == NULL) 
//	{
//		printf("�޸� �Ҵ� ����\n");
//		return;
//	}
//	new_node->data = new_data;
//	new_node->left = NULL;
//	new_node->right = NULL;
//
//	if (*root == NULL) 
//	{
//		*root = new_node;
//		return;
//	}
//
//	tree_pointer* current = *root;
//	tree_pointer* parent = NULL;
//	while (current != NULL) 
//	{
//		parent = current;
//		if (strcmp(new_data.name, current->data.name) < 0) 
//		{
//			current = current->left;
//		}
//		else 
//		{
//			current = current->right;
//		}
//	}
//
//	if (strcmp(new_data.name, parent->data.name) < 0) 
//	{
//		parent->left = new_node;
//	}
//	else 
//	{
//		parent->right = new_node;
//	}
//	end = clock();
//	cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
//	printf("Insert_BT �Լ��� ���� �ð�: %f ��\n", cpu_time);
//}
//void Delete_BT(tree_pointer** root, const char* key)
//{
//	clock_t start, end;
//	double cpu_time;
//	start = clock();
//	if (*root == NULL) 
//	{
//		printf("Ʈ���� ��� �ְų� ��带 ã�� �� �����ϴ�.\n");
//		return;
//	}
//
//	tree_pointer* current = *root;
//	tree_pointer* parent = NULL;
//	tree_pointer* temp = NULL;
//
//	// ������ ��带 ã�� ����
//	while (current != NULL && strcmp(key, current->data.name) != 0) 
//	{
//		parent = current;
//		if (strcmp(key, current->data.name) < 0) 
//		{
//			current = current->left;
//		}
//		else 
//		{
//			current = current->right;
//		}
//	}
//
//	if (current == NULL) 
//	{
//		printf("��带 ã�� �� �����ϴ�: %s\n", key);
//		return;
//	}
//
//	// �ڽ� ��尡 ���� ���
//	if (current->left == NULL && current->right == NULL) 
//	{
//		if (parent == NULL) 
//		{
//			*root = NULL;
//		}
//		else if (parent->left == current) 
//		{
//			parent->left = NULL;
//		}
//		else 
//		{
//			parent->right = NULL;
//		}
//		free(current);
//	}
//	// �ڽ� ��尡 �ϳ��� ���
//	else if (current->left == NULL || current->right == NULL) 
//	{
//		temp = (current->left != NULL) ? current->left : current->right;
//		if (parent == NULL) 
//		{
//			*root = temp;
//		}
//		else if (parent->left == current) 
//		{
//			parent->left = temp;
//		}
//		else 
//		{
//			parent->right = temp;
//		}
//		free(current);
//	}
//	// �ڽ� ��尡 ���� ���
//	else 
//	{
//		tree_pointer* successor = current->right;
//		tree_pointer* successor_parent = current;
//		while (successor->left != NULL) 
//		{
//			successor_parent = successor;
//			successor = successor->left;
//		}
//		current->data = successor->data;
//		if (successor_parent->left == successor) 
//		{
//			successor_parent->left = successor->right;
//		}
//		else 
//		{
//			successor_parent->right = successor->right;
//		}
//		free(successor);
//	}
//	end = clock();
//	cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
//	printf("Delete_BT �Լ��� ���� �ð�: %f ��\n", cpu_time);
//}
//void PrintAll_BT(tree_pointer* root)
//{
//	if (root != NULL)
//	{
//		PrintAll_BT(root->left);
//		printf("%s�� ����\n", root->data.name);
//		printf("POSITION: %s\n", root->data.position);
//		printf("HP: %d\n", root->data.hp);
//		printf("ATTACK: %d\n", root->data.attack);
//		printf("DEFENSE: %d\n", root->data.defense);
//		printf("\n");
//		PrintAll_BT(root->right);
//	}
//}
//void SortByName_BT(tree_pointer* root) 
//{
//	if (root != NULL) 
//	{
//		SortByName_BT(root->left);
//		printf("%s�� ����\n", root->data.name);
//		printf("POSITION: %s\n", root->data.position);
//		printf("HP: %d\n", root->data.hp);
//		printf("ATTACK: %d\n", root->data.attack);
//		printf("DEFENSE: %d\n", root->data.defense);
//		printf("\n");
//		SortByName_BT(root->right);
//	}
//}
//void FreeTree(tree_pointer* root) 
//{
//	if (root != NULL) 
//	{
//		FreeTree(root->left);
//		FreeTree(root->right);
//		free(root);
//	}
//}
