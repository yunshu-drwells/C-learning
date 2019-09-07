#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define PEO_MAX 1000

//姓名、性别、年龄、电话、住址
#define MAX_NAME 20
#define MAX_POSITION 30
typedef struct people
{
	char  name[MAX_NAME];
	char  sex[7];
	short age;
	char  tele[12];
	char  pos[MAX_POSITION];
}Peo;

void add_stru_peo(Peo* peo);//录入姓名、性别、年龄、电话、住址

void show_one_peo(Peo* peo);

void show_all_peo(Peo* peo);

//查找并打印所匹配合适的内容
void show_find_one_peo(Peo* peo, char name[MAX_NAME], int* same_num);  //考虑到联系人可能同名的情况于是用了递归来显示所有同名的联系人

Peo** all_same_name_peo(Peo* peo, char name[MAX_NAME]); //找到所有名字匹配的联系人

void show_all_same_peo(Peo* all_same_name);  //打印所有名字匹配的联系人

void delete_only_peo(Peo* peo, char* name);

void delete_delicate_peo(Peo* peo, char* name, char* pos);

void rewrite_menu();

void rewrite_only_peo(Peo* peo, char* name);

void delicate_rewrite_tru_peo(Peo* peo, char* name, char* pos);

int delete_all_peo(Peo* peo);

int compare_stru_name(const void* elem1, const void* elem2);

int save_all_peo(Peo* peo);

int load_contact(Peo* peo);

