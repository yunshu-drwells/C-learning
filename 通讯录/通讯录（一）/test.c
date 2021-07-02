#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"



void menu()
{
	printf("*******************************\n");
	printf("*****     0.exit              *\n");
	printf("***** 1. 添加联系人信息       *\n");
	printf("***** 2. 删除指定联系人信息   *\n");
	printf("***** 3. 查找指定联系人信息   *\n");
	printf("***** 4. 修改指定联系人信息   *\n");
	printf("***** 5. 显示所有联系人信息   *\n");
	printf("***** 6. 清空所有联系人       *\n");
	printf("***** 7. 以名字排序所有联系人 *\n");
	printf("***** 8. 保存联系人到文件     *\n");
	printf("***** 9. 加载联系人           *\n");
	printf("*******************************\n");

}




int main()
{
	Peo peo[PEO_MAX] = { {0, 0, 0, 0, 0} };
	int input = 0;
	do
	{
		int same_num = 0;
		int delete_ret = 0;
		int save_ret = 0;
		int load_ret = 0;
		char  name[MAX_NAME];
		char  pos[MAX_POSITION];
		Peo* find = NULL;
		Peo** all_same_name = NULL;
		size_t num_stu = sizeof(peo) / sizeof(Peo);
		menu();
		(void)scanf("%d", &input);
		switch (input)
		{

		case 1:
			add_stru_peo(peo);
			break;

		case 2:
			printf("请输入要删除的联系人的名称:>\n");
			(void)scanf("%s", name);

			all_same_name = all_same_name_peo(peo, name); //查找所有与所查询的联系人同名的联系人
			show_find_one_peo(peo, name, &same_num);   //查找所有与所查询的联系人同名的联系人并打印所有同名联系人

			if (same_num == 0) 
				printf("没有找到名字匹配的联系人\n");
			else if (same_num == 1) 
				delete_only_peo(peo, name);
			else
			{
				printf("匹配到%d个同名联系人，请输入要删除的联系人的地址:>\n", same_num);
				(void)scanf("%s", pos);
				delete_delicate_peo(peo, name, pos);
			}

			break;

		case 3:
			printf("请输入要查询的的联系人名称");
			(void)scanf("%s", name);

			printf("打印所有名字匹配的联系人\n");
			show_find_one_peo(peo, name, &same_num);   //查找所有与所查询的联系人同名的联系人并打印所有同名联系人
			if (same_num == 0) printf("没有找到名字匹配的联系人\n");

			//all_same_name = all_same_name_peo(peo, name); //查找所有与所查询的联系人同名的联系人
			//printf("打印所有名字匹配的联系人\n");
			//show_all_same_peo(*all_same_name);        //打印名字匹配的联系人，包括所有名字匹配的同名联系人
			break;

		case 4:
			printf("请输入要查询的的联系人名称");
			(void)scanf("%s", name);

			printf("打印所有名字匹配的联系人\n");
			show_find_one_peo(peo, name, &same_num);   //查找所有与所查询的联系人同名的联系人并打印所有同名联系人

			if (same_num == 0) 
				printf("没有找到名字匹配的联系人\n");
			else if (same_num == 1)
			{
				printf("匹配到一个联系人\n");
				rewrite_only_peo(peo, name);
			}
			else
			{
				printf("匹配到%d个同名联系人,请按提示输入所要修改的联系人的地址进行精确匹配\n", same_num);
				(void)scanf("%s", pos);
				delicate_rewrite_tru_peo(peo, name, pos);
			}
			break;

		case 5:
			show_all_peo(peo);
			break;

		case 6:
			delete_ret = delete_all_peo(peo);
			if (delete_ret)
				printf("所有联系人删除成功\n");
			else
				printf("所有联系人删除失败\n");
			break;

		case 7:
			qsort((void*)peo, num_stu, sizeof(Peo), compare_stru_name);
			break;

		case 8:
			save_ret = save_all_peo(peo);
			if (save_ret)
				printf("所有联系人已成功保存到文件\n");
			else
				printf("所有联系人保存到文件失败\n");
			break;

		case 9:
			load_ret = load_contact(peo);
			if (save_ret)
				printf("所有联系人已成功加载到文件\n");
			else
				printf("所有联系人加载到文件失败\n");
			break;
		default:
			break;
		}

	} while (input);


	return 0;
}

//2.实现一个通讯录；
//通讯录可以用来存储1000个人的信息，每个人的信息包括：
//姓名、性别、年龄、电话、住址
//
//提供方法：
//1. 添加联系人信息
//2. 删除指定联系人信息
//3. 查找指定联系人信息
//4. 修改指定联系人信息
//5. 显示所有联系人信息
//6. 清空所有联系人
//7. 以名字排序所有联系人
//8. 保存联系人到文件
//9. 加载联系人
