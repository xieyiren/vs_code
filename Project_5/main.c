#include<stdio.h>
#include<stdlib.h>

void test_01()
{
	char buf[128] = "";
	int i = 0;
	FILE* fp = NULL;
	// ��һ���ļ�
	fp = fopen("a.txt","r");
	if (fp == NULL)
	{
		perror(fopen);
		return;
	}
	// ���ļ����в���
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
	//�ر��ļ�
	fclose(fp);
}

void test_02()
{
	int i = 0;
	char buf[128] = "";
	// ��ȡһ���ļ�����
	FILE* f = fopen("b.txt", "w");
	if (f == NULL)
	{
		perror("fopen");
		return;
	}
	printf("������Ҫ���������:");
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
	// ��ȡ�ļ���
	FILE* f1 = fopen("a.txt", "r");
	FILE* f2 = fopen("b.txt", "w");
	while (1)
	{
		char ch;
		// ��ȡһ���ַ���Ȼ����뵽�µ��ļ�������
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
	// ����һ��ָ�����ݣ������洢�ַ���
	char* buf[] = { "��ǽ���¹�\n","���ǵ���˪\n","��ͷ������\n","��ͷ˼����" };
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
	// ��ȡ�ļ���
	FILE* f = fopen("hero.txt", "w");
	if (f == NULL)
	{
		perror("fopen");
		return;
	}
	HERO hero[] = // �ܹ�24*3=72���ֽ�
	{
		{"��л",24,80},
		{"Сл",21,90},
		{"С��",25,99}
	};
	int n = sizeof(hero) / sizeof(hero[0]);
	fwrite(hero, sizeof(HERO), n, f);
	// �ر��ļ���
	fclose(f);

}
void test_06()
{
	// ��ȡһ���ļ���ָ��
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
		printf("Ӣ������:��%s����������%d�����˺�:��%d��\n", hero[i].name, hero[i].deff, hero[i].atk);
	}

	// �ر��ַ���
	fclose(f);
}
void test_07()
{
	HERO hero[] = // �ܹ�24*3=72���ֽ�
	{
		{"��л",24,80},
		{"Сл",21,90},
		{"С��",25,99}
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
		fprintf(f, "Ӣ��:%s,����:%d,����:%d\n", hero[i].name, hero[i].deff, hero[i].atk);
	}

	//�ر��ֽ���
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
		fscanf_s(f, "Ӣ��:%s,����:%d,����:%d\n", hero[i].name,16, &hero[i].deff, &hero[i].atk);
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

	//rewind(f);  // �ļ�ָ�븴λ����ָ�����ص��ļ��Ŀ�ͷλ��
	
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
	// ���ļ���ָ�붨λ���ļ���ĩβ
	fseek(f, 0, 2);

	// �����ܵ��ļ��Լ���
	long length = ftell(f);

	// ���ļ�ָ�����»ص��ļ���ͷ
	rewind(f);

	// �����ļ����ȴ�С�Ķ����ռ�
	buff_data = (char *)calloc(1,length+1);

	// ���ļ����뵽�ո�����Ŀռ���
	fread(buff_data, length, 1, f);

	printf("length = %d\n", length);
	printf("%s\n", buff_data);

	// �ͷŶ����ռ�
	if (buff_data != NULL)
	{
		free(buff_data);
		buff_data = NULL;
	}
	//�ر��ַ���
	fclose(f);
}
int main(int argc, char* argv[])
{
	test_10();
	return 0;
}