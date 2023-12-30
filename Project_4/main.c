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
		printf("请输入指令:\n");
		scanf_s("%s", cmd , 32);
		if (strcmp(cmd, "help") == 0)
		{
			stu_help();
		}
		else if (strcmp(cmd,"insert") == 0)
		{
			STU tmp;
			printf("请输入需要插入的数据\nnum,score,name:");
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
			printf("请输入要查询的姓名:\n");
			scanf_s("%s", name,64);
			ret = serach_link(head, name);
			if (ret != NULL)
			{
				printf("num = %d , score = %.2f, name = %s\n", ret->num, ret->score, ret->name);
			}
			else
			{
				printf("查询失败，未查询到相关信息！");
			}
		}
		else if (strcmp(cmd, "delete") == 0)
		{
			char name[32] = "";
			printf("请输入要删除的姓名:");
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
	printf("#help:打印帮助信息        #\n");
	printf("#insert:插入链表节点      #\n");
	printf("#print:遍历链表节点信息   #\n");
	printf("#search:查询链表节点      #\n");
	printf("#reverse:逆转链表节点      #\n");
	printf("#delete:删除链表节点      #\n");
	printf("#free:释放链表            #\n");
	printf("#quit:退出                #\n");
	printf("###########################\n");
	return;
}