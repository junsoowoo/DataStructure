#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>

//è�Ǿ� ����ü ����
typedef struct {
	char name, postion;
	int hp, mp, speed, range;

} Dict;
//�Լ� ����
void Search(char name);
void Insert();
void Delete(char name);
void DeleteAll(char postion);
void PrintAll();
void FindMaxHP();
void SortHP(int a);
//���� �迭 ����
Dict list [100];

//����
int main()
{
	int order;
	printf("��ɾ �Է��ϼ���.\n(1.Search, 2.Insert, 3.Delete, 4.DeleteAll, 5.PrintAll, 6.FindMaxHP, 7.SortHP)\n");
	scanf(" %c",&order);            
	
	if (order == '1')
	{
		
			
	}

	else if (order == '2')
	{
		Insert();
	}

	else if (order == '3')
	{
		
	}

	else if (order == '4')
	{
		
	}
	else if (order == '5')
	{

	}
	else if (order == '6')
	{

	}
	else if (order == '7')
	{
		
	}
	
	return 0;
}
//è�Ǿ� ã�� �Լ�
void Search(char name)
{

}
//è�Ǿ� �߰� �Լ�
void Insert()
{

}
//è�Ǿ� ���� �Լ�
void Delete(char name)
{

}
//������ ���� �Լ�
void DeleteAll(char postion)
{

}
//��� è�Ǿ��� ���� ��� �Լ�
void PrintAll()
{

}
//���� ü���� ū è�Ǿ��� ���� ��� �Լ�
void FindMaxHP()
{
	int MaxHP = 0;

}
//ü���� ū è�Ǿ���� ������� ����
void SortHP(int a)
{


}
