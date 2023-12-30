#include<stdio.h>
#include<stdlib.h>

void print_help(void)
{
	printf("*********1:机密文件*********\n");
	printf("*********2:解密文件*********\n");
	printf("*********3:退出程序*********\n");
}

void get_file_name(char* dest_file_name, char* src_file_name)
{
	printf("请输入你的源文件名称(30个字符):");
	scanf_s("%s", src_file_name,31);
	printf("请输入你的目的文件名称(30个字符):");
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

	//获取文件总长度
	//将文件流指针 定位 到文件 尾部
	fseek(fp, 0, 2);
	//获取文件长度
	*file_length = ftell(fp);
	//复位文件流指针
	rewind(fp);

	//根据 文件的长度 申请 堆区空间
	data = (char*)calloc(1, *file_length);
	if (data == NULL)
	{
		perror("calloc");
		return NULL;
	}

	//一次性 读取文件内容
	fread(data, *file_length, 1, fp);

	//将空间首地址 返回
	return data;
}
char* file_text_encrypt(char* src_file_text, unsigned long int length, unsigned int password)
{
	int i = 0;
	for (i = 0; i < length; i++)
	{
		src_file_text[i] += password;//加密的过程
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

	//将data数据保存到 文件中
	fwrite(text, length, 1, fp);

	fclose(fp);

	//释放text指向堆区空间
	if (text != NULL)
	{
		free(text);
		text = NULL;
	}

	printf("保存成功!\n");
	return;
}

char* file_text_decrypt(char* src_file_text, unsigned long int length, unsigned int password)
{
	int i = 0;
	for (i = 0; i < length; i++)
	{
		src_file_text[i] -= password;//解密的过程
	}
	return src_file_text;
}