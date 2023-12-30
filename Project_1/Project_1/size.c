#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void test_00()
{
    printf("sizeof(char)=%d\n", sizeof(char));
    printf("sizeof(short)=%d\n", sizeof(short));
    printf("sizeof(int)=%d\n", sizeof(int));
    printf("sizeof(long)=%d\n", sizeof(long));
    printf("sizeof(float)=%d\n", sizeof(float));
    printf("sizeof(double)=%d\n", sizeof(double));
    //register int num = 10;  // 寄存器变量不可以取地址
    //printf("%p", &num);
}
void test_01() // 定义一个数，以不同的进制输出
{
	int num = 100;
	// 十进制 %d
	printf("十进制:num = %d\n", num);
	// 八进制 %o
	printf("八进制:num = %#o\n", num);
	// 十六进制 %x
	printf("十六进制:num = %#x\n", num);
}
void test_02()
{
	int num1 = 10;
	printf("num1 = %d\n", num1);
	unsigned int num2 = 10;
	printf("num2 = %u\n", num2);
	long num3 = 10;
	printf("num3 = %ld\n", num3);
	unsigned long num4 = 10;
	printf("num4 = %lu\n", num4);
}

void test_03()
{
	// 不以f结尾的为double类型 占八个字节
	printf("sizeof(3.14) = %d\n", sizeof(3.14));
	// 以f结尾的为float类型 占四个字节
	printf("sizeof(3.14f) = %d\n", sizeof(3.14f));
}
void test_04()
{
	// 定义一个char型变量
	char ch = 'a';
	//%c输出的是变量本身
	printf("a = %c\n", ch);
	//%d输出的是变量的ASCII值
	printf("a = %d\n", ch);
}
void test_05()
{
	char ch = 'a';
	// 占四个字节，'a'代表了ASCII码值 97，占四个字节
	printf("ch = %d\n", sizeof('a')); 
	// 占一个字节
	printf("ch = %d\n", sizeof(char));
}
void test_06()
{
	char ch;
	printf("请输入一个字符:\n");
	//scanf("%c", &ch);
	ch = getchar();
	// 输出ch所代表的字符
	printf("ch = %c\n", ch);
	// 输出ch所代表的ASCLL码值
	printf("ch = %d\n", ch);
}
void test_07()
{
	char ch1, ch2;
	printf("请输入abc:");
	ch1 = getchar();
	getchar();
	ch2 = getchar();
	printf("ch1 = %c\n", ch1);
	printf("ch2 = %c\n", ch2);
}
void test_08()
{
	printf("A: %d\n",'0');
	printf("B: %d\n", '\0');
	printf("C: %d\n", 0);
	printf("D: %p\n", "0");
}
void test_09()
{
	// %s 输出字符串，遇到\0代表结束
	printf("%s\n", "hello");
	// 输出hello的大小，char型字符占一个字节，末尾还有一个/0结束符
	printf("%d\n", sizeof("hello"));
}
void test_10()
{
	// %5d占五个位宽 默认右对齐 %-5d 是左对齐 %05d 不足的位宽补0
	printf("###########\n");
	printf("###%5d###\n", 123);
	printf("###%-5d###\n", 123);
	printf("###%05d###\n", 123);
}
void test_11()
{
	int data1 = -20;
	unsigned int data2 = 10;
	if (data1 + data2 > 0) // 计算之前先将data1转换为无符号数，计算之后就代表很大的一个数
	{
		printf(">0\n");
	}
	else
	{
		printf("<0\n");
	}
}
void test_12()
{
	int num = 0;
	printf("请输入一个数字:");
	scanf("%d", &num);
	if (num % 3 == 0) // 判断一个数能否被3整除
	{
		printf("ok");
	}
	else
	{
		printf("no");
	}
}
void test_13()
{
	int num = 0;
	printf("请输入一个四位数:");
	scanf("%d", &num);
	printf("千位:%d,百位:%d,十位:%d,个位:%d", 
		num / 1000, (num / 100) % 10, (num / 10) % 10, num % 10);
}
void test_14()
{
	char num = 0x85;
	num = num >> 4;
	printf("%#x\n", num); // %#x 带格式输出 %x是十六进制输出
}
void test_15()
{
	int num = 0;
	printf("请输入一个数:");
	scanf("%d", &num); // 获取从键盘输入的值
	if (num % 3 == 0)
	{
		printf("余数为零。\n");
	}
	else if(num % 3 == 1)
	{
		printf("余数为一。\n"); 
	}
	else if (num % 3 == 2)
	{
		printf("余数为二。\n");
	}
}
void test_16()
{
	char ch = 0;
	printf("请输入你的方向:wasd\n");
	ch = getchar();
	switch (ch)
	{
	case 'w':
	case 'W':
		printf("向前移动。\n");
		break;
	case 'a':
	case 'A':
		printf("向左移动。\n");
		break;
	case 's':
	case 'S':
		printf("向后移动。\n");
		break;
	case 'd':
	case 'D':
		printf("向右移动。\n");
		break;
	}
}
void test_17()
{
	int i = 0;
	int sum = 0;
	for (int i = 0; i <=100; i+=2)
	{
		sum += i;
	}
	printf("%d\n", sum);
}
void test_18()
{
	int i = 0;
	int sum = 0;
	while (i <= 100)
	{
		sum += i;
		i++;
	}
	printf("%d\n", sum);
}
void test_19()
{
	int arr[] = { 10,20,30,40,50,1,2,3,4,5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}
void test_20()
{
	char arr[6] = "hello";
	for (int i = 0; i < 6; i++)
	{
		printf("%c", arr[i]);
	}
	printf("\n----------------\n");
	
	printf("%s\n", arr);
}

void test_21()
{
	char buf[10] = "";
	printf("请输入一个字符串:\n");
	//scanf("%s", buf);
	//gets(buf);
	fgets(buf, sizeof(buf), stdin);
	printf("buf = %s\n", buf);
}
// 获取键盘输入的五个数
void arr_input(int arr[5], int n)
{
	printf("请输入五个数:\n");
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &arr[i]);
	}
}
// 通过数组求得最大值
int arr_max(int arr[5], int n)
{
	int tem_max = arr[0];
	for (int i = 0; i < n; i++)
	{
		tem_max = tem_max > arr[i] ? tem_max : arr[i];
	}
	return tem_max;
}
// 通过数组求得最小值
int arr_min(int arr[5], int n)
{
	int tem_min = arr[0];
	for (int i = 0; i < n; i++)
	{
		tem_min = tem_min < arr[i] ? tem_min : arr[i];
	}
	return tem_min;
}

void test_22()
{
	int arr[5] = { 0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	// 输入五个数
	arr_input(arr, n);
	// 求出最大值
	int max = arr_max(arr, n);
	printf("最大值是:%d\n", max);
	// 求出最小值
	int min = arr_min(arr, n);
	printf("最小值是:%d\n", min);
}

// 宏展开的本质就是替换
#define MY_MUL(a,b) a*b


void test_23()
{
	int i = 0;
	printf("请输入字符串:\n");
	char buf[128] = "";
	fgets(buf, sizeof(buf), stdin); // 第三个参数是一个数组，第二个参数是数组的大小，第三个参数是标准是输入
	buf[strlen(buf) - 1] = 0;
	//int j = strlen(buf);
	while (buf[i])
	{
#if 0
		if (buf[i] >= 'A' && buf[i] <=  'Z')
			buf[i] += 32;
#else
		if (buf[i] >= 'a' && buf[i] <= 'z')
			buf[i] -= 32;
#endif 
		i++;
	}
	printf("%s\n", buf);
	return 0;
}
void test_24()
{
	char data = -10;
	char data2 = 10;
	printf("%x\n", data2);
}
void test_25()
{
	printf("char = %d\n", sizeof(char *));
	printf("short = %d\n", sizeof(short *));
	printf("int = %d\n", sizeof(int *));
	printf("float = %d\n", sizeof(float *));
	printf("double = %d\n", sizeof(double *));
	printf("long = %d\n", sizeof(long *));
}
void test_26()
{
	int num = 10;
	int* p;
	p = &num;
	printf("num = %p\n", &num);
	printf("p = %p\n", p);
	printf("num = %d\n", *p);
	*p = 100;
	printf("num = %d\n", num);
}
void test_27()
{
	int num = 0x01020304;

	char* p;
	short* p1;
	int* p2;

	p = &num;
	p1 = &num;
	p2 = &num;

	printf("p = %u\n", p);
	printf("p+1 = %u\n", p+1);
	printf("------------------\n");
	printf("p1 = %u\n", p1);
	printf("p1+1 = %u\n", p1+1);
	printf("------------------\n");
	printf("p2 = %u\n", p2);
	printf("p2+1 = %u\n", p2+1);
	
}
void test_28()
{
	int num = 0x01020304;

	short* p;

	p = &num;

	printf("p = %#x\n", *(p+1));
}
void test_29()
{
	int num = 0x01020304;

	char* p;

	p = &num;

	printf("p = %#x\n", *(p + 3));
}
void test_30()
{
	int num = 0x01020304;
	char* p;
	p = &num;
	printf("%#x\n", *(short*)(p + 1));
}
void test_31()
{
	int num = 20;
	int data = 100;
	int* p = &num;
	int* p1 = &data;
	
	printf("p = %d\n", *p); // *p表示对p对应的地址进行解索引，取地址空间存放的数据
	printf("p1 = %d\n", *p1);
	p = &data;
	printf("p = %d\n", *p);
}
void test_32()
{
	int arr[5] = { 10,20,30,40,50 };
	int* p = &arr;
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("arr[0] = %d\n", *p);
	p++;
	printf("arr[1] = %d\n", *p);
	p = &arr;
	for (int i = 0; i < n; i++)
	{
		printf("%d ", *(p + i));
	}
}
void test_33()
{
	int num1 = 10;
	int num2 = 20;
	int num3 = 30;

	int* arr[3] = { &num1,&num2,&num3 };
	printf("%d\n", *arr[1]);
}

void test_34() {
	// 函数指针的声明
	int(*p)(int,int) = NULL;
	printf("%d\n", sizeof(p));
	// my_add代表的是函数的入口地址 0x00671488
	//printf("%p\n", my_add);
	// 将函数指针与函数名建立关系  0x00671488
	//p = my_add;
	//printf("%p\n", p);
	// 函数调用
	printf("%d\n", my_add(10, 20));
	printf("%d\n", p(100, 200));
	// 使用函数指针的方式来调用函数
	//printf("%d\n", ((int (*)(int,int))(0x00671488))(120, 220));
}
int my_add(int a, int b)
{
	return a + b;
}
int my_sub(int a, int b)
{
	return a - b;
}
int my_mul(int a, int b)
{
	return a * b;
}
// 定义一个函数，实现上述的功能
int my_calc(int a, int b, int (*my_fun)(int, int)) // 函数指针
{
	return my_fun(a, b); 
}
void test_35()
{
	printf("%d\n", my_calc(10, 20, my_add));
	printf("%d\n", my_calc(10, 20, my_sub));
	printf("%d\n", my_calc(10, 20, my_mul));
}
void test_36()
{
	int* addr = NULL;
	addr = (int *)malloc(sizeof(int));
	if (addr == NULL) // 如果申请失败
	{
		printf("malloc err\n");
	}
	printf("*addr = %#p\n", addr);
	// 清空堆区的值
	memset(addr, 0, sizeof(int));

	printf("*addr = %d\n", *addr);
	*addr = 1000;
	printf("*addr = %d\n", *addr);
	free(addr);
}
void test_37()
{
	int i = 0;
	int n = 0;
	int* arr = NULL;
	printf("请输入元素的个数:");
	scanf_s("%d", &n);
	arr = (int*)malloc(n * sizeof(int));
	// 判断是否申请成功
	if (NULL == arr)
	{
		perror("malloc");
		return;
	}
	printf("请输入%d个元素:\n", n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", arr+i);
	}
	// 打印输出元素
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	// 释放空间
	free(arr);
}
void test_38()
{
	int* p = (int*)calloc(1, sizeof(int));
	if (p != NULL)  // 防止多次释放
	{
		free(p);
		p = NULL;
	}
	if (p != NULL) 
	{
		free(p);
		p = NULL;
	}
}
void test_39()
{
	char buf1[] = "abcd";

	printf("%d\n", sizeof(buf1));
	printf("%d\n", strlen(buf1));
}
void test_40()
{
	char arr[] = "hello\0world";
	char tem[128] = "";
	strcpy(tem, arr);
	printf("%s\n", tem);
}
void test_41()
{
	char arr[] = "hello\0world";
	char tem[128] = "";
	strncpy(tem, arr+1,4);
	printf("%s\n", tem);
}
void test_42()
{
	char arr[] = "world";
	char tem[128] = "hello ";
	strcat(tem, arr);
	printf("%s\n", tem);
}
void test_43()
{
	char arr[] = "world";
	char * st = strchr(arr, 'o'); // 字符串查找函数
	printf("%p\n", st);
	if (st != NULL) // 判断是否比较的时候找到了位置
	{
		*st ='h';
	}
	printf("%s\n", arr);
}
int my_atoi(char* arr)
{
	int sum = 0;
	while (*arr != '\0' && (*arr >= '0' && *arr <='9'))
	{
		sum = sum * 10 + *arr - '0';
		arr++;
	}
	return sum;
}
void test_44()
{
	char arr[128] = "";
	printf("请输入字符串:");
	scanf("%s", &arr);
	printf("%d", my_atoi(arr));
}
void test_45()
{
	char buf[] = "hehe:lala:**chuachua:;keke:wuwu:chuchu";
	char* arr[32] = { buf,NULL }; // 创建一个指针数组，用于存储切割的字符
	int i = 0;
	while (arr[i++] = strtok(arr[i], ":*;"));
	i = 0;
	while (arr[i] != NULL)
	{
		printf("%s\n", arr[i]);
		i++;
	}
}
void test_46()
{
	// 用const修饰的变量无法通过变量名来修改值
	const int num = 10;
	printf("num = %d\n", num);
	//num = 100;
	printf("&num = %p\n", &num);
	*(int*)(&num) = 100; // 可以通过地址来修改变量的值（&num）取num 的地址（int *） 强制进行类型转换
	printf("num = %d\n", num);
}
void test_47()
{
	int num1 = 100;
	int num2 = 200;
	int* const p = &num1;

	printf("num1 = %d\n", *p);

	//p = &num2;
	//printf("num1 = %d\n", *p);
}
// 结构体类型的定义
struct stu
{
	int num;
	char name[32];
	int age;
};

void test_48()
{
	struct stu lucy = { 100,"谢老二",26 };
	/*lucy.num = 100;
	lucy.age = 27;
	strcpy(lucy.name, "谢老大");*/
	printf("sizeof(struct stu) = %d\n", sizeof(struct stu));
	printf("lucy.num = %d\n", lucy.num);
	printf("lucy.name = %s\n", lucy.name);
	printf("lucy.age = %d\n", lucy.age);
	memset(&lucy, 0, sizeof(lucy));
	printf("lucy.num = %d\n", lucy.num);
	printf("lucy.age = %d\n", lucy.age);
}
void test_49()
{
	struct stu lala;
	memset(&lala, 0, sizeof(lala));
	printf("请输入 num name age:");
	scanf("%d %s %d", &lala.num, lala.name, &lala.age);
	printf("lala.num = %d\n", lala.num);
	printf("lala.name = %s\n", lala.name);
	printf("lala.age = %d\n", lala.age);
}
void test_50()
{
	int n = 0;
	int i = 0;
	int j = 0;
	int* arr = NULL;// 新建一个指针数组
	printf("请输入元素的个数:");
	scanf("%d", &n);
	// 根据元素个数申请空间
	arr = (int*)calloc(n, sizeof(int));
	if (NULL == arr)
	{
		perror("calloc");
		return;
	}
	printf("请输入%d个int数据\n", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
	}
	// 冒泡排序
	for (i = 0; i < n - 1; i++)
	{
		int flag = 0;
		for (j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1]) 
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}

	for (i = 0; i < n; i++)
	{
		printf("%d ", *(arr + i));
	}
	// 释放空间
	if (arr != NULL)
	{
		free(arr);
		arr = NULL;
	}
}
void test_51()
{
	int i = 0;
	int j = 0;
	struct stu arr[5];
	int n = sizeof(arr) / sizeof(arr[0]);
	memset(arr, 0, sizeof(arr));// 整个数组清零
	// 获取键盘输入
	printf("请输入%d个数组:\n",n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %s %d", &arr[i].age, arr[i].name, &arr[i].num);
	}

	// 根据学号冒泡排序
	for (i = 0; i < n - 1; i++)
	{
		int flag = 0;
		for (j = 0; j < n - 1 - i; j++)
		{
			if (arr[j].age > arr[j + 1].age)
			{
				struct stu temp;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
	printf("--------------------\n");
	// 遍历数组
	for (i = 0; i < n; i++)
	{
		printf("%d %s %d\n", arr[i].age, arr[i].name, arr[i].num);
	}

}
void test_52()
{
	typedef int INI32;
	typedef int* T_TYPE;
	INI32 num = 10;
	T_TYPE b = &num;
	printf("num = %d\n", num);
	printf("%p", b);
}
typedef int ARR_N[5];
void test_53()
{
	ARR_N a = { 3, 5, 1, 0, 6 };
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", a[i]);
	}
}
typedef int* T_TYPE;
int main(int argc, char* argv[])
{ 
	test_53();
	return 0;
}

