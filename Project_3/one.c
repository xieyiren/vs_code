#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma pack(2)
typedef struct  
{
	int age;
	char name[32];
	int num;
}STU;
typedef struct
{
	int x;
	int y;
}DATA1;
typedef struct
{
	int a;
	int b;
	DATA1 c;
}DATA2;
void test_01()
{
	STU p;
	printf("%d\n", sizeof(p));
	printf("int age = %u\n", &p.age);
	printf("char name = %u\n", &p.name);
	printf("int num = %u\n", &p.num);
	// 从堆区申请结构体空间
	//p = (STU*)calloc(1, sizeof(STU));
	//if (NULL == p)
	//{
	//	perror("calloc");
	//	return;
	//}
	////printf("%d", sizeof(p));
	//printf("请输入学生的信息 age name num:\n");
	//scanf_s("%d %s %d", &p->age, p->name,32 ,&p->num ); // scanf_s 其中规定了读入字符串的大小，因此，应该在字符串之后加入字符串的大小
	//printf("age = %d,name = %s,num = %d\n", p->age, p->name, p->num);
	//// 释放空间
	//if (p != NULL)
	//{
	//	free(p);
	//	p = NULL;
	//}
}
void test_02()
{
	DATA2 data = { 3,4,{5,6} };
	printf("a = %d\n", data.a);
	printf("b = %d\n", data.b);
	printf("x = %d\n", data.c.x);
	printf("y = %d\n", data.c.y);
}
typedef struct
{
	short d;
	char e;
}DATA3;
typedef struct
{
	short a;
	int b;
	DATA3 c;
	char f;
}DATA4;
void test_03()
{
	DATA4 data;
	printf("a = %u\n", &data.a);
	printf("b = %u\n", &data.b);
	printf("c中的d = %u\n", &data.c.d);
	printf("c中的e = %u\n", &data.c.e);
}
typedef struct
{
	unsigned char a : 2;
	unsigned char : 4;
	unsigned char b : 2;
}DATA5;
void test_04()
{
	DATA5 data;
	memset(&data, 0,sizeof(data));
	printf("DATA5的大小为:%d字节\n", sizeof(DATA5));
	data.a = 0;
	data.b = 3;
	printf("%#x", *(unsigned char*)&data);
}
union data
{
	char a;
	short b;
	int c;
};
void test_05()
{
	printf("%d", sizeof(union data));
}
enum POKER
{
	HONGTAO,
	HEITAO,
	MEIHUA,
	FANGKUAI
};
void test_06()
{
	enum POKER poker_color = 1;
	printf("%s", poker_color);
}

typedef struct stu
{
	int age;
	int num;
	char add[32];

	struct stu* next;
}STU_1;
void test_07()
{
	STU t = *(STU*)malloc(sizeof(STU));

}
void test_08()
{
	int ret;
	ret = strcmp("a", "a");
	printf("%d", ret);
}
int main(int argc, char* argv[])
{
	test_08();
	return 0;
}