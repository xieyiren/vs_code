#include<stdio.h>
#include<stdlib.h>

void test_01()
{
	char buf[128] = "";
	int i = 0;
	FILE* fp = NULL;
	// 打开一个文件
	fp = fopen("a.txt","r");
	if (fp == NULL)
	{
		perror(fopen);
		return;
	}
	// 对文件进行操作
	while (1)
	{
		buf[i] = fgetc(fp);
		if (buf[i] == EOF)
		{
			break;
		}
		i++;
	}
	printf("buf = %s\n", buf);
	//关闭文件
	fclose(fp);
}

void test_02()
{
	int i = 0;
	char buf[128] = "";
	// 获取一个文件打开流
	FILE* f = fopen("b.txt", "w");
	if (f == NULL)
	{
		perror("fopen");
		return;
	}
	printf("请输入要插入的数据:");
	fgets(buf, sizeof(buf), stdin);
	while (buf[i] != '\0')
	{
		fputc(buf[i], f);
		i++;
	}
	fclose(f);
}
void test_03()
{
	// 获取文件流
	FILE* f1 = fopen("a.txt", "r");
	FILE* f2 = fopen("b.txt", "w");
	while (1)
	{
		char ch;
		// 获取一个字符，然后插入到新的文件流里面
		ch = fgetc(f1);
		if (ch == EOF)
		{
			break;
		}
		fputc(ch, f2);
	}
	fclose(f1); 
	fclose(f2);
}
void test_04()
{
	// 定义一个指针数据，用来存储字符串
	char* buf[] = { "窗墙明月光\n","疑是地上霜\n","举头望明月\n","低头思故乡" };
	int n = sizeof(buf) / sizeof(buf[0]);
	FILE* f = fopen("c.txt", "w");
	if(f == NULL)
	{
		perror("fopen");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		fputs(buf[i], f);
	}
	fclose(f);
}
typedef struct
{
	char name[16];
	int deff;
	int atk;
}HERO;
void test_05()
{
	// 获取文件流
	FILE* f = fopen("hero.txt", "w");
	if (f == NULL)
	{
		perror("fopen");
		return;
	}
	HERO hero[] = // 总共24*3=72个字节
	{
		{"老谢",24,80},
		{"小谢",21,90},
		{"小刘",25,99}
	};
	int n = sizeof(hero) / sizeof(hero[0]);
	fwrite(hero, sizeof(HERO), n, f);
	// 关闭文件流
	fclose(f);

}
void test_06()
{
	// 获取一个文件流指针
	FILE* f = fopen("hero.txt", "r");
	if (f == NULL)
	{
		perror("fopen");
		return;
	}

	HERO hero[3];
	fread(hero, sizeof(HERO), 3, f);

	for (int i = 0; i < 3; i++)
	{
		printf("英雄姓名:《%s》，防御《%d》，伤害:《%d》\n", hero[i].name, hero[i].deff, hero[i].atk);
	}

	// 关闭字符流
	fclose(f);
}
void test_07()
{
	HERO hero[] = // 总共24*3=72个字节
	{
		{"老谢",24,80},
		{"小谢",21,90},
		{"小刘",25,99}
	};
	int n = sizeof(hero) / sizeof(hero[0]);
	FILE* f = fopen("hero.txt", "w");
	if (f == NULL)
	{
		perror("fopen");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		fprintf(f, "英雄:%s,防御:%d,攻击:%d\n", hero[i].name, hero[i].deff, hero[i].atk);
	}

	//关闭字节流
	fclose(f);
}
void test_08()
{
	HERO hero[3];
	FILE* f = fopen("hero.txt", "r");
	if (f == NULL)
	{
		perror("fopen");
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		fscanf_s(f, "英雄:%s,防御:%d,攻击:%d\n", hero[i].name,16, &hero[i].deff, &hero[i].atk);
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%s,%d,%d\n", hero[i].name, hero[i].deff, hero[i].atk);
	}

	fclose(f);
}
void test_09()
{
	char buf[128] = "";
	FILE* f = NULL;
	f = fopen("a.txt", "w+");
	if (f == NULL)
	{
		perror("fopen");
		return;
	}
	fputs("hello file test", f);

	//rewind(f);  // 文件指针复位，让指针流回到文件的开头位置
	
	int length = ftell(f);
	fgets(buf, sizeof(buf), f);
	
	printf("buf = %s\n", buf);
	printf("%d\n", length);
	
	fclose(f);
}
void test_10()
{
	char* buff_data = NULL;
	FILE* f = NULL;
	f = fopen("a.txt", "r");
	if (f == NULL)
	{
		perror("fopen");
		return;
	}
	// 将文件流指针定位到文件的末尾
	fseek(f, 0, 2);

	// 计算总的文件自己数
	long length = ftell(f);

	// 将文件指针重新回到文件开头
	rewind(f);

	// 申请文件长度大小的堆区空间
	buff_data = (char *)calloc(1,length+1);

	// 将文件读入到刚刚申请的空间内
	fread(buff_data, length, 1, f);

	printf("length = %d\n", length);
	printf("%s\n", buff_data);

	// 释放堆区空间
	if (buff_data != NULL)
	{
		free(buff_data);
		buff_data = NULL;
	}
	//关闭字符流
	fclose(f);
}
int main(int argc, char* argv[])
{
	test_10();
	return 0;
}