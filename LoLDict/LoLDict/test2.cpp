#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>

//챔피언 구조체 선언
typedef struct {
	char name, postion;
	int hp, mp, speed, range;

} Dict;
//함수 선언
void Search(char name);
void Insert();
void Delete(char name);
void DeleteAll(char postion);
void PrintAll();
void FindMaxHP();
void SortHP(int a);
//사전 배열 선언
Dict list [100];

//메인
int main()
{
	int order;
	printf("명령어를 입력하세요.\n(1.Search, 2.Insert, 3.Delete, 4.DeleteAll, 5.PrintAll, 6.FindMaxHP, 7.SortHP)\n");
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
//챔피언 찾기 함수
void Search(char name)
{

}
//챔피언 추가 함수
void Insert()
{

}
//챔피언 삭제 함수
void Delete(char name)
{

}
//포지션 삭제 함수
void DeleteAll(char postion)
{

}
//모든 챔피언의 정보 출력 함수
void PrintAll()
{

}
//가장 체력이 큰 챔피언의 정보 출력 함수
void FindMaxHP()
{
	int MaxHP = 0;

}
//체력이 큰 챔피언부터 순서대로 저장
void SortHP(int a)
{


}
