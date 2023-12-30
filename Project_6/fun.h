
#ifndef _FUN_H_
#define _FUN_H_

extern void print_help(void);
extern void get_file_name(char* dest_file_name, char* src_file_name);
extern char* read_src_file(unsigned long* file_length, char* src_file_name);
extern char* file_text_encrypt(char* src_file_text, unsigned long int length, unsigned int password);
extern void save_file(char* text, unsigned long int length, char* file_name);

#endif

