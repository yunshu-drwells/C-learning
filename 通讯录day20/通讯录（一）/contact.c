#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"


void add_stru_peo(Peo* peo) //录入姓名、性别、年龄、电话、住址
{
	if (peo->age)
		while (peo->age)  peo++;

	printf("请输入 姓名:>");
	(void)scanf("%s", (peo->name));
	printf("请输入 性别:>");
	(void)scanf("%s", (peo->sex));
	printf("请输入 年龄:>");
	(void)scanf("%hu", &(peo->age));
	printf("请输入 电话:>");
	(void)scanf("%s", (peo->tele));
	printf("请输入 住址:>");
	(void)scanf("%s", (peo->pos));

	if (peo->age)
		printf("新联系人添加成功\n");
	else
		printf("新联系人添加失败\n");
}



void show_one_peo(Peo* peo)
{
	printf("%s\t", peo->name);
	printf("%s\t", peo->sex);
	printf("%hu\t", peo->age);
	printf("%s\t", peo->tele);
	printf("%s\n", peo->pos);
}

void show_all_peo(Peo* peo)
{
	if (peo->age)
	{
		printf("姓名\t性别\t年龄\t电话\t住址\n\n");
		while (peo->age)
		{
			show_one_peo(peo);
			peo++;
		}
	}
	else
		printf("没有任何联系人信息\n");
}

//查找并打印所匹配合适的内容
void show_find_one_peo(Peo* peo, char name[MAX_NAME], int* same_num)  //考虑到联系人可能同名的情况于是用了递归来显示所有同名的联系人
{
	Peo* first = peo - 1;
	while (*(peo->name) && strcmp(peo->name, name)) peo++;
	if (*(peo->name) && peo > first && (peo - first) < PEO_MAX - 1)
	{
		if (*same_num == 0)
			printf("姓名\t性别\t年龄\t电话\t住址\n\n");
		show_one_peo(peo);	(*same_num)++;      //same_num用于储存同名联系人个数
		show_find_one_peo(peo + 1, name, same_num);
	}
}

Peo** all_same_name_peo(Peo* peo, char name[MAX_NAME])   //找到所有名字匹配的联系人
{
	Peo* first = peo - 1;
	static Peo* find_same_name[10] = { 0, 0, 0, 0, 0 };  //放在堆上，用于存放找到的所有同名联系人的地址

	int i = 0;
	while ((peo - first) && (peo - first) < PEO_MAX - 1)
	{
		first = peo;
		while (*(peo->name) && strcmp(peo->name, name))
			peo++;
		if (!(peo - first))
		{
			find_same_name[i] = peo;
			i++;
		}
	}
	return find_same_name;
}


void show_all_same_peo(Peo* all_same_name)  //打印所有名字匹配的联系人
{
	if (all_same_name->age)
	{
		printf("姓名\t性别\t年龄\t电话\t住址\n\n");
		while (all_same_name->age)
		{
			show_one_peo(all_same_name);
			all_same_name++;
		}
	}
	else
		printf("没有找到名字匹配的联系人\n");
}

void delete_only_peo(Peo* peo, char* name)
{
	Peo tmp = { 0, 0, 0, 0, 0 };
	int flag = 0;
	while (*((peo + 1)->name) && strcmp(peo->name, name))  //找到名字匹配的联系人并且不是最后一个，循环刚好跳出
		peo++;
	while (*((peo + 1)->name))    //当不是最后一个联系人的时候就往前覆盖
	{
		peo->age = (peo + 1)->age;
		strcpy(peo->name, (peo + 1)->name);
		strcpy(peo->pos, (peo + 1)->pos);
		strcpy(peo->sex, (peo + 1)->sex);
		strcpy(peo->tele, (peo + 1)->tele);
		flag++;
		peo++;
	}

	if (strcmp(peo->name, name) == 0 || flag)  //是最后一个联系人的时候直接删除
	{
		peo->age = tmp.age;
		strcpy(peo->name, tmp.name);
		strcpy(peo->pos, tmp.pos);
		strcpy(peo->sex, tmp.sex);
		strcpy(peo->tele, tmp.tele);
		flag++;
		printf("删除成功，已成功删除联系人\n");
	}
	if (!flag)
		printf("删除失败，没找到匹配的联系人\n");


}

void delete_delicate_peo(Peo* peo, char* name, char* pos)
{
	Peo tmp = { 0, 0, 0, 0, 0 };
	int flag = 0;
	while (*((peo + 1)->name) && !(strcmp(peo->name, name) == 0 && strcmp(peo->pos, pos) == 0))  //找到名字和地址都匹配的联系人并且不是最后一个，循环刚好跳出
		peo++;
	while (*((peo + 1)->name))    //当不是最后一个联系人的时候就往前覆盖
	{
		peo->age = (peo + 1)->age;
		strcpy(peo->name, (peo + 1)->name);
		strcpy(peo->pos, (peo + 1)->pos);
		strcpy(peo->sex, (peo + 1)->sex);
		strcpy(peo->tele, (peo + 1)->tele);
		flag++;
		peo++;
	}

	if (strcmp(peo->name, name) == 0 && strcmp(peo->pos, pos) == 0 || flag)  //是最后一个联系人的时候直接删除
	{
		peo->age = tmp.age;
		strcpy(peo->name, tmp.name);
		strcpy(peo->pos, tmp.pos);
		strcpy(peo->sex, tmp.sex);
		strcpy(peo->tele, tmp.tele);
		flag++;
		printf("删除成功，已成功删除联系人\n");
	}
	if (!flag)
		printf("删除失败，没找到匹配的联系人\n");
}








void rewrite_menu()
{
	printf("********************\n");
	printf("***0.修改完毕  *****\n");
	printf("***1姓名、2性别*****\n");
	printf("***3年龄、4电话*****\n");
	printf("***    5住址  ******\n");
	printf("********************\n");
}

void rewrite_only_peo(Peo* peo, char* name)
{
	Peo tmp = { 0, 0, 0, 0, 0 };
	int flag = 0;
	int input = 0;
	while (*(peo->name) && strcmp(peo->name, name))  //找到名字匹配的联系人循环刚好跳出，或者找不到跳出
		peo++;

	if (strcmp(peo->name, name) == 0)
	{
		printf("精确匹配成功\n");
		do
		{
			rewrite_menu();
			printf("请选择您要执行的操作\n");
			(void)scanf("%d", &input);
			switch (input)
			{
			case 1:
				printf("请输入姓名:> ");
				(void)scanf("%s", tmp.name);
				strcpy(peo->name, tmp.name);
				flag++;
				break;
			case 2:
				printf("请输入性别:> ");
				(void)scanf("%s", tmp.sex);
				strcpy(peo->sex, tmp.sex);
				flag++;
				break;
			case 3:
				printf("请输入年龄:> ");
				(void)scanf("%hu", &tmp.age);
				peo->age = tmp.age;
				flag++;
				break;
			case 4:
				printf("请输入电话:> ");
				(void)scanf("%s", tmp.tele);
				strcpy(peo->tele, tmp.tele);
				flag++;
				break;
			case 5:
				printf("请输入地址:> ");
				(void)scanf("%s", tmp.pos);
				strcpy(peo->pos, tmp.pos);
				flag++;
				break;
			default:
				printf("输入错误,请重新输入\n");
				break;
			}
		} while (input);
	}


	if (flag)
		printf("修改成功，已成功修改联系人\n");
	if (!flag)
		printf("修改失败，没找到匹配的联系人\n");
}

void delicate_rewrite_tru_peo(Peo* peo, char* name, char* pos)
{
	Peo tmp = { 0, 0, 0, 0, 0 };
	int flag = 0;
	int input = 0;
	while (*(peo->name) && !(strcmp(peo->name, name) == 0 && strcmp(peo->pos, pos) == 0))  //找到名字匹配的联系人循环刚好跳出，或者找不到跳出
		peo++;

	if (strcmp(peo->name, name) == 0)
	{
		printf("精确匹配成功\n");
		do
		{
			rewrite_menu();
			printf("请选择您要执行的操作\n");
			(void)scanf("%d", &input);
			switch (input)
			{
			case 1:
				printf("请输入姓名:> ");
				(void)scanf("%s", tmp.name);
				strcpy(peo->name, tmp.name);
				flag++;
				break;
			case 2:
				printf("请输入性别:> ");
				(void)scanf("%s", tmp.sex);
				strcpy(peo->sex, tmp.sex);
				flag++;
				break;
			case 3:
				printf("请输入年龄:> ");
				(void)scanf("%hu", &tmp.age);
				peo->age = tmp.age;
				flag++;
				break;
			case 4:
				printf("请输入电话:> ");
				(void)scanf("%s", tmp.tele);
				strcpy(peo->tele, tmp.tele);
				flag++;
				break;
			case 5:
				printf("请输入地址:> ");
				(void)scanf("%s", tmp.pos);
				strcpy(peo->pos, tmp.pos);
				flag++;
				break;
			default:
				printf("输入错误,请重新输入\n");
				break;
			}
		} while (input);
	}


	if (flag)
		printf("修改成功，已成功修改联系人\n");
	if (!flag)
		printf("修改失败，没找到匹配的联系人\n");
}

int delete_all_peo(Peo* peo)
{
	Peo* first = peo;
	Peo tmp = { 0, 0, 0, 0, 0 };
	while (*(peo->name))
	{
		peo->age = tmp.age;
		strcpy(peo->name, tmp.name);
		strcpy(peo->pos, tmp.pos);
		strcpy(peo->sex, tmp.sex);
		strcpy(peo->tele, tmp.tele);
		peo++;
	}
	if (!*(first->name))
		return 1;
	else
		return 0;
}


int compare_stru_name(const void* elem1, const void* elem2)
{
	return strcmp(((Peo*)elem1)->name, ((Peo*)elem2)->name);

}



int save_all_peo(Peo* peo)
{
	int i = 0;
	FILE* pf = fopen("contact.txt", "w");
	if (pf == NULL)
	{
		printf("保存文件失败\n");
		return -1;
	}
	while (peo->age)
	{
		fwrite(peo + i, sizeof(struct people), 1, pf);
		peo++;
		i++;
	}
	return 1;
	fclose(pf);
	pf = NULL;
}



int load_contact(Peo* peo)
{
	int i = 0;
	FILE* pf = fopen("contact.txt", "r");
	if (pf == NULL)
	{
		printf("加载文件失败\n");
		return -1;
	}
	else
	{
	while (fread(peo + i, sizeof(struct people), 1, pf))
		return 1;
	}
	fclose(pf);
	pf = NULL;

}
