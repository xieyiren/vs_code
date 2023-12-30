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
    //register int num = 10;  // �Ĵ�������������ȡ��ַ
    //printf("%p", &num);
}
void test_01() // ����һ�������Բ�ͬ�Ľ������
{
	int num = 100;
	// ʮ���� %d
	printf("ʮ����:num = %d\n", num);
	// �˽��� %o
	printf("�˽���:num = %#o\n", num);
	// ʮ������ %x
	printf("ʮ������:num = %#x\n", num);
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
	// ����f��β��Ϊdouble���� ռ�˸��ֽ�
	printf("sizeof(3.14) = %d\n", sizeof(3.14));
	// ��f��β��Ϊfloat���� ռ�ĸ��ֽ�
	printf("sizeof(3.14f) = %d\n", sizeof(3.14f));
}
void test_04()
{
	// ����һ��char�ͱ���
	char ch = 'a';
	//%c������Ǳ�������
	printf("a = %c\n", ch);
	//%d������Ǳ�����ASCIIֵ
	printf("a = %d\n", ch);
}
void test_05()
{
	char ch = 'a';
	// ռ�ĸ��ֽڣ�'a'������ASCII��ֵ 97��ռ�ĸ��ֽ�
	printf("ch = %d\n", sizeof('a')); 
	// ռһ���ֽ�
	printf("ch = %d\n", sizeof(char));
}
void test_06()
{
	char ch;
	printf("������һ���ַ�:\n");
	//scanf("%c", &ch);
	ch = getchar();
	// ���ch��������ַ�
	printf("ch = %c\n", ch);
	// ���ch�������ASCLL��ֵ
	printf("ch = %d\n", ch);
}
void test_07()
{
	char ch1, ch2;
	printf("������abc:");
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
	// %s ����ַ���������\0�������
	printf("%s\n", "hello");
	// ���hello�Ĵ�С��char���ַ�ռһ���ֽڣ�ĩβ����һ��/0������
	printf("%d\n", sizeof("hello"));
}
void test_10()
{
	// %5dռ���λ�� Ĭ���Ҷ��� %-5d ������� %05d �����λ��0
	printf("###########\n");
	printf("###%5d###\n", 123);
	printf("###%-5d###\n", 123);
	printf("###%05d###\n", 123);
}
void test_11()
{
	int data1 = -20;
	unsigned int data2 = 10;
	if (data1 + data2 > 0) // ����֮ǰ�Ƚ�data1ת��Ϊ�޷�����������֮��ʹ���ܴ��һ����
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
	printf("������һ������:");
	scanf("%d", &num);
	if (num % 3 == 0) // �ж�һ�����ܷ�3����
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
	printf("������һ����λ��:");
	scanf("%d", &num);
	printf("ǧλ:%d,��λ:%d,ʮλ:%d,��λ:%d", 
		num / 1000, (num / 100) % 10, (num / 10) % 10, num % 10);
}
void test_14()
{
	char num = 0x85;
	num = num >> 4;
	printf("%#x\n", num); // %#x ����ʽ��� %x��ʮ���������
}
void test_15()
{
	int num = 0;
	printf("������һ����:");
	scanf("%d", &num); // ��ȡ�Ӽ��������ֵ
	if (num % 3 == 0)
	{
		printf("����Ϊ�㡣\n");
	}
	else if(num % 3 == 1)
	{
		printf("����Ϊһ��\n"); 
	}
	else if (num % 3 == 2)
	{
		printf("����Ϊ����\n");
	}
}
void test_16()
{
	char ch = 0;
	printf("��������ķ���:wasd\n");
	ch = getchar();
	switch (ch)
	{
	case 'w':
	case 'W':
		printf("��ǰ�ƶ���\n");
		break;
	case 'a':
	case 'A':
		printf("�����ƶ���\n");
		break;
	case 's':
	case 'S':
		printf("����ƶ���\n");
		break;
	case 'd':
	case 'D':
		printf("�����ƶ���\n");
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
	printf("������һ���ַ���:\n");
	//scanf("%s", buf);
	//gets(buf);
	fgets(buf, sizeof(buf), stdin);
	printf("buf = %s\n", buf);
}
// ��ȡ��������������
void arr_input(int arr[5], int n)
{
	printf("�����������:\n");
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &arr[i]);
	}
}
// ͨ������������ֵ
int arr_max(int arr[5], int n)
{
	int tem_max = arr[0];
	for (int i = 0; i < n; i++)
	{
		tem_max = tem_max > arr[i] ? tem_max : arr[i];
	}
	return tem_max;
}
// ͨ�����������Сֵ
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
	// ���������
	arr_input(arr, n);
	// ������ֵ
	int max = arr_max(arr, n);
	printf("���ֵ��:%d\n", max);
	// �����Сֵ
	int min = arr_min(arr, n);
	printf("��Сֵ��:%d\n", min);
}

// ��չ���ı��ʾ����滻
#define MY_MUL(a,b) a*b


void test_23()
{
	int i = 0;
	printf("�������ַ���:\n");
	char buf[128] = "";
	fgets(buf, sizeof(buf), stdin); // ������������һ�����飬�ڶ�������������Ĵ�С�������������Ǳ�׼������
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
	
	printf("p = %d\n", *p); // *p��ʾ��p��Ӧ�ĵ�ַ���н�������ȡ��ַ�ռ��ŵ�����
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
	// ����ָ�������
	int(*p)(int,int) = NULL;
	printf("%d\n", sizeof(p));
	// my_add������Ǻ�������ڵ�ַ 0x00671488
	//printf("%p\n", my_add);
	// ������ָ���뺯����������ϵ  0x00671488
	//p = my_add;
	//printf("%p\n", p);
	// ��������
	printf("%d\n", my_add(10, 20));
	printf("%d\n", p(100, 200));
	// ʹ�ú���ָ��ķ�ʽ�����ú���
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
// ����һ��������ʵ�������Ĺ���
int my_calc(int a, int b, int (*my_fun)(int, int)) // ����ָ��
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
	if (addr == NULL) // �������ʧ��
	{
		printf("malloc err\n");
	}
	printf("*addr = %#p\n", addr);
	// ��ն�����ֵ
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
	printf("������Ԫ�صĸ���:");
	scanf_s("%d", &n);
	arr = (int*)malloc(n * sizeof(int));
	// �ж��Ƿ�����ɹ�
	if (NULL == arr)
	{
		perror("malloc");
		return;
	}
	printf("������%d��Ԫ��:\n", n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", arr+i);
	}
	// ��ӡ���Ԫ��
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	// �ͷſռ�
	free(arr);
}
void test_38()
{
	int* p = (int*)calloc(1, sizeof(int));
	if (p != NULL)  // ��ֹ����ͷ�
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
	char * st = strchr(arr, 'o'); // �ַ������Һ���
	printf("%p\n", st);
	if (st != NULL) // �ж��Ƿ�Ƚϵ�ʱ���ҵ���λ��
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
	printf("�������ַ���:");
	scanf("%s", &arr);
	printf("%d", my_atoi(arr));
}
void test_45()
{
	char buf[] = "hehe:lala:**chuachua:;keke:wuwu:chuchu";
	char* arr[32] = { buf,NULL }; // ����һ��ָ�����飬���ڴ洢�и���ַ�
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
	// ��const���εı����޷�ͨ�����������޸�ֵ
	const int num = 10;
	printf("num = %d\n", num);
	//num = 100;
	printf("&num = %p\n", &num);
	*(int*)(&num) = 100; // ����ͨ����ַ���޸ı�����ֵ��&num��ȡnum �ĵ�ַ��int *�� ǿ�ƽ�������ת��
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
// �ṹ�����͵Ķ���
struct stu
{
	int num;
	char name[32];
	int age;
};

void test_48()
{
	struct stu lucy = { 100,"л�϶�",26 };
	/*lucy.num = 100;
	lucy.age = 27;
	strcpy(lucy.name, "л�ϴ�");*/
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
	printf("������ num name age:");
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
	int* arr = NULL;// �½�һ��ָ������
	printf("������Ԫ�صĸ���:");
	scanf("%d", &n);
	// ����Ԫ�ظ�������ռ�
	arr = (int*)calloc(n, sizeof(int));
	if (NULL == arr)
	{
		perror("calloc");
		return;
	}
	printf("������%d��int����\n", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
	}
	// ð������
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
	// �ͷſռ�
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
	memset(arr, 0, sizeof(arr));// ������������
	// ��ȡ��������
	printf("������%d������:\n",n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %s %d", &arr[i].age, arr[i].name, &arr[i].num);
	}

	// ����ѧ��ð������
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
	// ��������
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

