#include<stdio.h>
void my_fun(void)
{
	printf("全局变量");
}

static void my_static_fun(void)
{
	printf("局部变量");
}