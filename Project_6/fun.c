#include<stdio.h>
#include<stdlib.h>

void print_help(void)
{
	printf("*********1:�����ļ�*********\n");
	printf("*********2:�����ļ�*********\n");
	printf("*********3:�˳�����*********\n");
}

void get_file_name(char* dest_file_name, char* src_file_name)
{
	printf("���������Դ�ļ�����(30���ַ�):");
	scanf_s("%s", src_file_name,31);
	printf("���������Ŀ���ļ�����(30���ַ�):");
	scanf_s("%s", dest_file_name,31);
	return;
}

char* read_src_file(unsigned long* file_length, char* src_file_name)
{
	char* data = NULL;
	FILE* fp = fopen(src_file_name, "r");
	if (fp == NULL)
	{
		perror("fopen");
		return NULL;
	}

	//��ȡ�ļ��ܳ���
	//���ļ���ָ�� ��λ ���ļ� β��
	fseek(fp, 0, 2);
	//��ȡ�ļ�����
	*file_length = ftell(fp);
	//��λ�ļ���ָ��
	rewind(fp);

	//���� �ļ��ĳ��� ���� �����ռ�
	data = (char*)calloc(1, *file_length);
	if (data == NULL)
	{
		perror("calloc");
		return NULL;
	}

	//һ���� ��ȡ�ļ�����
	fread(data, *file_length, 1, fp);

	//���ռ��׵�ַ ����
	return data;
}
char* file_text_encrypt(char* src_file_text, unsigned long int length, unsigned int password)
{
	int i = 0;
	for (i = 0; i < length; i++)
	{
		src_file_text[i] += password;//���ܵĹ���
	}

	return src_file_text;
}

void save_file(char* text, unsigned long int length, char* file_name)
{
	FILE* fp = fopen(file_name, "w");
	if (fp == NULL)
	{
		perror("fopen");
		return;
	}

	//��data���ݱ��浽 �ļ���
	fwrite(text, length, 1, fp);

	fclose(fp);

	//�ͷ�textָ������ռ�
	if (text != NULL)
	{
		free(text);
		text = NULL;
	}

	printf("����ɹ�!\n");
	return;
}

char* file_text_decrypt(char* src_file_text, unsigned long int length, unsigned int password)
{
	int i = 0;
	for (i = 0; i < length; i++)
	{
		src_file_text[i] -= password;//���ܵĹ���
	}
	return src_file_text;
}