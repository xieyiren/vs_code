#include<stdio.h>
#include<string.h>
#include"link.h"
void stu_help(void);

int main(int argc, char* argv[])
{
	STU* head = NULL;
	stu_help();

	while (1)
	{
		char cmd[32] = "";
		printf("������ָ��:\n");
		scanf_s("%s", cmd , 32);
		if (strcmp(cmd, "help") == 0)
		{
			stu_help();
		}
		else if (strcmp(cmd,"insert") == 0)
		{
			STU tmp;
			printf("��������Ҫ���������\nnum,score,name:");
			scanf_s("%d %f %s", &tmp.num, &tmp.score, tmp.name ,32);
			head = insert_link(head, tmp);
		}
		else if (strcmp(cmd, "print") == 0)
		{
			print_link(head);
		}
		else if (strcmp(cmd,"reverse") == 0)
		{
			head = reverse_link(head);
		}
		else if (strcmp(cmd, "search") == 0)
		{
			char name[64] = "";
			STU* ret;
			printf("������Ҫ��ѯ������:\n");
			scanf_s("%s", name,64);
			ret = serach_link(head, name);
			if (ret != NULL)
			{
				printf("num = %d , score = %.2f, name = %s\n", ret->num, ret->score, ret->name);
			}
			else
			{
				printf("��ѯʧ�ܣ�δ��ѯ�������Ϣ��");
			}
		}
		else if (strcmp(cmd, "delete") == 0)
		{
			char name[32] = "";
			printf("������Ҫɾ��������:");
			scanf_s("%s", name, 32);			
			head =delete_link(head,name);
		}
		else if (strcmp(cmd, "free") == 0)
		{
			head = free_link(head);
		}
		else if (strcmp(cmd, "quit") == 0)
		{
			head = free_link(head);
			break;
		}
	}
	return 0;
}
void stu_help(void)
{
	printf("###########################\n");
	printf("#help:��ӡ������Ϣ        #\n");
	printf("#insert:��������ڵ�      #\n");
	printf("#print:��������ڵ���Ϣ   #\n");
	printf("#search:��ѯ����ڵ�      #\n");
	printf("#reverse:��ת����ڵ�      #\n");
	printf("#delete:ɾ������ڵ�      #\n");
	printf("#free:�ͷ�����            #\n");
	printf("#quit:�˳�                #\n");
	printf("###########################\n");
	return;
}