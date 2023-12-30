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

			//1、获取源文件 目的文件名(参考API实现)
			get_file_name(dst_file, src_file);

			//2、获取源文件名 对应的文件 内容
			file_data = read_src_file(&file_length, src_file);

			//3、获取用户输入的密码
			printf("请输入你的密码:");
			scanf_s("%u", &passwd);

			//4、对文件内容加密
			file_data = file_text_encrypt(file_data, file_length, passwd);

			//5、对加密好的 文件内容 保存到 目的文件名中
			save_file(file_data, file_length, dst_file);
		}
		else if (cmd == 2)
		{
			char src_file[31] = "";
			char dst_file[31] = "";
			char* file_data = NULL;
			unsigned long file_length = 0;
			unsigned int passwd = 0;

			//1、获取源文件 目的文件名
			get_file_name(dst_file, src_file);
			

			//2、获取源文件名 对应的文件 内容
			file_data = read_src_file(&file_length, src_file);
			

			//3、获取用户输入的密码
			printf("请输入你的密码:");
			scanf_s("%u", &passwd);

			//4、对文件内容解密
			file_data = file_text_decrypt(file_data, file_length, passwd);
			

			//5、对加密好的 文件内容 保存到 目的文件名中
			save_file(file_data, file_length, dst_file);
			
		}
		else if (cmd == 3)
		{
			break;
		}
		else
		{
			printf("请输入一个正确的选项\n");
		}

	}

	return 0;
}