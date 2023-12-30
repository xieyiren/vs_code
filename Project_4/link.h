#pragma once
typedef struct stu
{
	//  ˝æ›”Ú
	int num;
	float score;
	char name[32];
	// ÷∏’Î”Ú
	struct stu* next;
}STU;

extern STU* insert_link(STU* head, STU tmp);
extern void print_link(STU* head);
extern STU* serach_link(STU* head, char* name);
extern STU* delete_link(STU* head, char* name);
extern STU* free_link(STU* head);
extern STU* reverse_link(STU* head);