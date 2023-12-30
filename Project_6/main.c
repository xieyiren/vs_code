#include<stdio.h>
#include"fun.h"

int main(int argc, char* argv[])
{
	while (1)
	{
		int cmd = 0;
		print_help();

		scanf_s("%d", &cmd);

		if (cmd == 1)
		{
			char src_file[31] = "";
			char dst_file[31] = "";
			char* file_data = NULL;
			unsigned long file_length = 0;
			unsigned int passwd = 0;

			//1����ȡԴ�ļ� Ŀ���ļ���(�ο�APIʵ��)
			get_file_name(dst_file, src_file);

			//2����ȡԴ�ļ��� ��Ӧ���ļ� ����
			file_data = read_src_file(&file_length, src_file);

			//3����ȡ�û����������
			printf("�������������:");
			scanf_s("%u", &passwd);

			//4�����ļ����ݼ���
			file_data = file_text_encrypt(file_data, file_length, passwd);

			//5���Լ��ܺõ� �ļ����� ���浽 Ŀ���ļ�����
			save_file(file_data, file_length, dst_file);
		}
		else if (cmd == 2)
		{
			char src_file[31] = "";
			char dst_file[31] = "";
			char* file_data = NULL;
			unsigned long file_length = 0;
			unsigned int passwd = 0;

			//1����ȡԴ�ļ� Ŀ���ļ���
			get_file_name(dst_file, src_file);
			

			//2����ȡԴ�ļ��� ��Ӧ���ļ� ����
			file_data = read_src_file(&file_length, src_file);
			

			//3����ȡ�û����������
			printf("�������������:");
			scanf_s("%u", &passwd);

			//4�����ļ����ݽ���
			file_data = file_text_decrypt(file_data, file_length, passwd);
			

			//5���Լ��ܺõ� �ļ����� ���浽 Ŀ���ļ�����
			save_file(file_data, file_length, dst_file);
			
		}
		else if (cmd == 3)
		{
			break;
		}
		else
		{
			printf("������һ����ȷ��ѡ��\n");
		}

	}

	return 0;
}