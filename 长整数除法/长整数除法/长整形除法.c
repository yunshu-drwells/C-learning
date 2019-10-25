#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#define DataType short

//定义栈结构，用被除数和除数大小比较和商结果的打印
typedef struct Stack
{
	short* st;
	int top;
}Stack;

void StackInital(Stack* Pst)
{
	Pst->top = 0;
	Pst->st  = NULL;
}

void StackPush(Stack* Pst, short x)
{
	short* s = (short*)realloc(Pst->st, sizeof(short)*(Pst->top+1));
	assert(s != NULL);
	Pst->st = s;
	Pst->st[Pst->top++] = x;
}

//利用链表线性结构来装除数和被除数和商
typedef struct SListNode  
{
	DataType data;
	struct SListNode* next;
}SListNode;

typedef struct Div
{
	int digit;
	struct SListNode* P;
}Div;



void DivInital(Div* Pdiv)
{
	Pdiv->digit = 0;
	Pdiv->P = NULL;
}

void SListPush(Div* Pdiv, char* x)
{
	SListNode* s = (SListNode*)malloc(sizeof(SListNode));
	assert(s != NULL);
	if (!Pdiv->digit)
		s->next = NULL;
	s->data = *x - 48;

	if (Pdiv->P == NULL)
		Pdiv->P = s;
	else
	{
		s->next = Pdiv->P;
		Pdiv->P = s;
	}
	Pdiv->digit++;
}

void _PlusUnit(SListNode* p)
{
	if (p == NULL)
	{
		SListNode* s = (SListNode*)malloc(sizeof(SListNode));
		assert(s != NULL);
		s->next = NULL;
		p = s;
		s->data = 1;
	}
	if (p->data < 9)
		p->data++;
	else
	{
		if (p->next == NULL && p->data == 9)
		{
			SListNode* s = (SListNode*)malloc(sizeof(SListNode));
			assert(s != NULL);
			s->data = 0;
			s->next = NULL;
			p->next = s;
		}
		p->data = 0;
		_PlusUnit(p->next);
	}

}

void PlusUnit(Div* quitent, int x)
{
	if (x == 0) return;
	SListNode* p = NULL;
	if (quitent->P == NULL)
	{
		SListNode* s = (SListNode*)malloc(sizeof(SListNode));
		assert(s != NULL);
		s->next = NULL;
		quitent->P = s;
		s->data = 0;
	}
	while (x--)
	{
		p = quitent->P;
		if (p == NULL)
		{
			SListNode* s = (SListNode*)malloc(sizeof(SListNode));
			assert(s != NULL);
			s->next = NULL;
			p = s;
			s->data = 0;
		}
		_PlusUnit(p);
	}

}

bool same_digit_greater(SListNode* first, SListNode* last)
{
	int same_sz = 0;
	Stack st1;  //栈1记录被除数
	Stack st2;  //栈2记录除数
	StackInital(&st1);
	StackInital(&st2);
	while (first != NULL && last != NULL)  //将记录被除数和除数的链表压栈
	{
		StackPush(&st1, first->data);
		StackPush(&st2, last->data);
		first = first->next;
		last = last->next;
	}
	//比较被除数和除数的大小
	same_sz = st1.top - 1;
	if (st1.st[same_sz] > st2.st[same_sz]) return true;
	if (st1.st[same_sz] < st2.st[same_sz]) return false;
	while (same_sz-- >= 0)  //将记录被除数和除数的链表出栈并比较被除数和除数大小
	{
		if (st1.st[same_sz] == st2.st[same_sz])
			same_sz--;
		if (st1.st[same_sz] < st2.st[same_sz])
			return false;
		if (st1.st[same_sz] > st2.st[same_sz])
			return true;
	}
}

void _Divide(Div* Pdiv1, SListNode* div1, SListNode* div1_prve)  //相减的核心算法
{
	int flag = 1;
	SListNode* div1_temp = div1;
	SListNode* div1_prve_temp = div1;
	while (div1_prve_temp->next != NULL)
	{
		//删除最高位的0
		if (div1_temp->next == NULL && div1_temp->data == 0)  
		{
			free(div1_prve_temp->next);
			div1_prve_temp->next = NULL;
			Pdiv1->digit--;
			return;
		}
		//当前位先减，一但不够在比它高的位有数字的前提下借1
		if (div1_prve_temp->next != NULL && div1_temp->next != NULL && div1_temp->data < 0) 
		{
			div1_temp->data += 10;
			div1_temp->next->data--;
		}
		//指向被除数位的前后指针向后走，看哪一位不够就得想更高位借1
		if (flag)
		{
			div1_temp = div1_temp->next;
			flag--;
		}
		else
		{
			div1_temp = div1_temp->next;
			div1_prve_temp = div1_prve_temp->next;
		}
	}
}

void Divide(Div* Pdiv1, Div* Pdiv2, Div* quitent)
{
	SListNode* div1 = Pdiv1->P;
	SListNode* div2 = Pdiv2->P;
	SListNode* p1 = NULL;
	SListNode* p2 = NULL;
	while (Pdiv1->digit > Pdiv2->digit || (Pdiv1->digit == Pdiv2->digit && same_digit_greater(Pdiv1->P, Pdiv2->P) ))
	{
		p1 = div1;
		p2 = div2;
		while (p2 != NULL)
		{
			p1->data -= p2->data;
			_Divide(Pdiv1, p1, p1);
			p1 = p1->next;
			p2 = p2->next;
		}
		PlusUnit(quitent, 1);
	}
}

void printQuitent(SListNode* p)  //非递归方式打印商结果
{
	SListNode* pt = p;
	Stack QuitentStack;
	StackInital(&QuitentStack);
	if (NULL == p)
		return;
	else
	{
		while (pt != NULL)  //商入栈
		{
			StackPush(&QuitentStack,  pt->data);
			pt = pt->next;
		}
		QuitentStack.top--;
		while (QuitentStack.top)  //商出栈
		{
			printf("%d", QuitentStack.st[QuitentStack.top--]);
		}
		printf("%d\n", QuitentStack.st[QuitentStack.top]);
	}
	free(QuitentStack.st);
	QuitentStack.st = NULL;
}

void PrintRemainder(SListNode* p)  //打印余数
{
	SListNode* pt = p;
	Stack Div1RemainderStack;
	StackInital(&Div1RemainderStack);
	if (NULL == p)
		return;
	else
	{
		while (pt != NULL)  //余数入栈
		{
			StackPush(&Div1RemainderStack, pt->data);
			pt = pt->next;
		}
		Div1RemainderStack.top--;
		while (Div1RemainderStack.top)  //余数出栈
		{
			printf("%d", Div1RemainderStack.st[Div1RemainderStack.top--]);
		}
		printf("%d\n", Div1RemainderStack.st[Div1RemainderStack.top]);
	}
	free(Div1RemainderStack.st);
	Div1RemainderStack.st = NULL;
}


int main()
{
	Div div1;
	Div div2;
	Div quitent;
	DivInital(&div1);
	DivInital(&div2);
	DivInital(&quitent);
	char divident;
	char divisor;

	printf("请输入被除数，字符'e'作为结束标志\n");
	while (scanf("%c", &divident)&& divident != 'e')
	{
		SListPush(&div1, &divident);
	}
	(void)scanf("%c", &divident);  //取消\n的影响
	printf("请输入除数，字符'e'作为结束标志\n");
	while (scanf("%c", &divisor) && divisor != 'e')
	{
		SListPush(&div2, &divisor);
	}
	Divide(&div1, &div2, &quitent);
	printf("商是：");
	printQuitent(quitent.P);
	printf("余数是：");
	PrintRemainder(div1.P);
	return 0;
}



//void _Divide(Div* Pdiv1, SListNode* div1, SListNode* div1_prve)  //相减的核心算法（递归，考虑到效率问题改成下面的非递归方式）
//{
//	static flag = 1;
//	if (div1->next == NULL && div1->data == 0)
//	{
//		free(div1_prve->next);
//		div1_prve->next = NULL;
//		Pdiv1->digit--;
//	}
//	if (div1_prve->next != NULL && div1->next != NULL && div1->data < 0)
//	{
//		div1->data += 10;
//		div1->next->data--;
//		if (flag)
//			{
//				_Divide(Pdiv1, div1->next, div1_prve);
//				flag--;
//			}
//			
//		else
//			_Divide(Pdiv1, div1->next, div1_prve->next);
//	}
//}


//void printQuitent(SListNode* p)  //递归打印商结果（递归，考虑到效率问题改成下面的非递归方式）
//{
//	if (NULL == p)
//		return;
//	else
//	{
//		printQuitent(p->next);
//		printf("%d", p->data);
//	}
//}



