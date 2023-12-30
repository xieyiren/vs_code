#include<stdio.h>

extern void my_fun(void);
extern void my_static_fun(void);

int main(int argc, char *argv[])
{
	my_static_fun();
	return 0;
}