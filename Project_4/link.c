#include"link.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#if 0
// 头部插入节点
STU* insert_link(STU* head, STU tmp)
{
	// 动态申请一个空间
	STU* pi = (STU*)malloc(sizeof(STU));
	// 判断是否申请成功
	if (pi == NULL)
	{
		perror("malloc");
		return head;
	}
	// 将tmp赋值给pi
	*pi = tmp;
	pi->next = NULL; // pi的next置为空
	// 如果head为空
	if (head == NULL)
	{
		head = pi;
	}
	else // 如果不为空
	{
		pi->next = head;
		head = pi;
	} 
	return head;

}
#endif

// 尾部插入
STU* insert_link(STU* head, STU tmp)
{
	// 申请一个临时空间
	STU* pi = (STU*)malloc(sizeof(STU));
	// 判断是否申请成功
	if (pi == NULL)
	{
		perror(malloc);
		return head;
	}
	// 将传来的值赋给pi
	*pi = tmp;
	pi->next = NULL;
	// 如果链表为空
	if (head == NULL)
	{
		head = pi;
		//提示链表插入成功
		printf("信息插入成功！");
		return head;
	}
	else // 不为空
	{
		// 寻找尾节点
		STU* pb = head;
		while (pb ->next !=NULL)
		{
			pb = pb->next;
		}
		// 在尾节点后面插入新的节点信息
		pb->next = pi;
		printf("信息插入成功！");
		return head;
	}
}

// 按姓名查询
STU* serach_link(STU* head, char* name)
{
	// 定义一个临时的节点，来往后移动，比对姓名
	STU* tmp = head;

	while (head != NULL && strcmp(name, tmp->name) != 0 && tmp->next != NULL )
	{
		tmp = tmp->next;
	}
	return tmp;
	
	
}

// 按名字删除
STU* delete_link(STU* head, char* name)
{
	if (head == NULL)
	{
		printf("link not fond!\n");
		return head;
	}
	else
	{
		// 定义两个节点信息，用于保存当前节点和前一个节点的信息
		STU* pf = head, * pb = head;
		while (strcmp(pb->name, name) != 0 && pb->next != NULL)
		{
			pf = pb;
			pb = pb->next;
		}
		if (strcmp(pb->name, name) == 0)
		{
			if (pb = head)
			{
				head = pb->next;
				free(pb);
			}
			else
			{
				pf->next = pb->next;
				free(pb);
			}
			printf("%s删除成功！\n", name);
		}
		else
		{
			printf("未找到%s节点的相关信息！\n", name);
		}
	}
	return head;
}

// 释放链表
STU* free_link(STU* head)
{
	if (head == NULL)
	{
		printf("link not fond!\n");
		return head;
	}
	else
	{
		STU* pb = head;
		while (pb != NULL)
		{
			// head 保存下一个节点的信息
			head = pb->next;
			// 释放pb
			free(pb);
			// pb 指向 head
			pb = head;
		}
		printf("链表删除成功！\n");
		return head;
		
	}
}
// 逆转链表
STU* reverse_link(STU* head)
{
	if (head == NULL)
	{
		printf("link not fond!\n");
		return head;
	}
	else
	{
		STU* pb = head, * pr = head;
		pb = head->next;
		head->next = NULL;
		while (pb != NULL)
		{
			pr = pb->next;
			pb->next = head;
			head = pb;
			pb = pr;
		}
		printf("链表逆转成功！\n");
		return head;
	}
}

// 打印输出链表
void print_link(STU* head)
{
	if (head == NULL)// 如果链表为空，则退出遍历
	{
		printf("link not find!\n");
		return;
	}
	else
	{
		// 新定义一个pl，用来指向head
		STU* pl = head;
		while (pl != NULL)
		{
			printf("num = %d,score = %.2f,name = %s\n", pl->num, pl->score, pl->name);
			pl = pl->next;
		}
	}
	return;
}