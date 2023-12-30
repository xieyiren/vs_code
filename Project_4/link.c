#include"link.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#if 0
// ͷ������ڵ�
STU* insert_link(STU* head, STU tmp)
{
	// ��̬����һ���ռ�
	STU* pi = (STU*)malloc(sizeof(STU));
	// �ж��Ƿ�����ɹ�
	if (pi == NULL)
	{
		perror("malloc");
		return head;
	}
	// ��tmp��ֵ��pi
	*pi = tmp;
	pi->next = NULL; // pi��next��Ϊ��
	// ���headΪ��
	if (head == NULL)
	{
		head = pi;
	}
	else // �����Ϊ��
	{
		pi->next = head;
		head = pi;
	} 
	return head;

}
#endif

// β������
STU* insert_link(STU* head, STU tmp)
{
	// ����һ����ʱ�ռ�
	STU* pi = (STU*)malloc(sizeof(STU));
	// �ж��Ƿ�����ɹ�
	if (pi == NULL)
	{
		perror(malloc);
		return head;
	}
	// ��������ֵ����pi
	*pi = tmp;
	pi->next = NULL;
	// �������Ϊ��
	if (head == NULL)
	{
		head = pi;
		//��ʾ�������ɹ�
		printf("��Ϣ����ɹ���");
		return head;
	}
	else // ��Ϊ��
	{
		// Ѱ��β�ڵ�
		STU* pb = head;
		while (pb ->next !=NULL)
		{
			pb = pb->next;
		}
		// ��β�ڵ��������µĽڵ���Ϣ
		pb->next = pi;
		printf("��Ϣ����ɹ���");
		return head;
	}
}

// ��������ѯ
STU* serach_link(STU* head, char* name)
{
	// ����һ����ʱ�Ľڵ㣬�������ƶ����ȶ�����
	STU* tmp = head;

	while (head != NULL && strcmp(name, tmp->name) != 0 && tmp->next != NULL )
	{
		tmp = tmp->next;
	}
	return tmp;
	
	
}

// ������ɾ��
STU* delete_link(STU* head, char* name)
{
	if (head == NULL)
	{
		printf("link not fond!\n");
		return head;
	}
	else
	{
		// ���������ڵ���Ϣ�����ڱ��浱ǰ�ڵ��ǰһ���ڵ����Ϣ
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
			printf("%sɾ���ɹ���\n", name);
		}
		else
		{
			printf("δ�ҵ�%s�ڵ�������Ϣ��\n", name);
		}
	}
	return head;
}

// �ͷ�����
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
			// head ������һ���ڵ����Ϣ
			head = pb->next;
			// �ͷ�pb
			free(pb);
			// pb ָ�� head
			pb = head;
		}
		printf("����ɾ���ɹ���\n");
		return head;
		
	}
}
// ��ת����
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
		printf("������ת�ɹ���\n");
		return head;
	}
}

// ��ӡ�������
void print_link(STU* head)
{
	if (head == NULL)// �������Ϊ�գ����˳�����
	{
		printf("link not find!\n");
		return;
	}
	else
	{
		// �¶���һ��pl������ָ��head
		STU* pl = head;
		while (pl != NULL)
		{
			printf("num = %d,score = %.2f,name = %s\n", pl->num, pl->score, pl->name);
			pl = pl->next;
		}
	}
	return;
}