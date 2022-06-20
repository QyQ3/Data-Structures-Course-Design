#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MaxLen 100
typedef struct {
	char num[10];
	char name[10];
	char sex[10];
	char phone[20];
	char address[50];
}xx;
typedef struct
{
	xx grxx[MaxLen];
	int length;
}xxb;

void InitList(xxb* L);
void Menu();
void Quit();
void Create(xxb* L);
void Add(xxb* L);
void Find(xxb L);
void Alter(xxb* L);
void Delete(xxb* L);
void List(xxb L);

void nv(xxb L);
void ti(xxb L);

int main()
{
	xxb L;
	int i;
	InitList(&L);
	while (1) {
		Menu();
		printf("请输入您想要的功能:(1-9)\t");
	loop:scanf_s(" %d", &i);
		if (i <= 0 || i >= 10)
		{
			system("cls");
			Menu();
			printf("未设定功能，请重新输入:");

			goto loop;
		}
		switch (i)
		{
		case 1:
			Create(&L);
			break;
		case 2:
			Add(&L);
			break;
		case 3:
			Find(L);
			break;
		case 4:
			Alter(&L);
			break;
		case 5:
			Delete(&L);
			break;
		case 6:
			List(L);
			break;
		case 7:
			nv(L);
			break;
		case 8:
			ti(L);
			break;
		case 9:
			Quit();
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}


void InitList(xxb* L)
{
	L->length = 0;
	return;
}

void Menu()
{
	printf("\t\t\t《通讯录管理系统菜单》\n");
	printf(">————————————————————————————————\n");
	printf("*\t1.新建联系人\n");
	printf("*\t2.添加联系人信息\n");
	printf("*\t3.查找指定联系人信息\n");
	printf("*\t4.修改指定联系人\n");
	printf("*\t5.删除指定联系人\n");
	printf("*\t6.显示全部联系人信息\n");
	printf("*\t7.显示本通讯录男女比例\n");
	printf("*\t8.显示出同一公司中的人的信息\n");
	printf("*\t9.退出菜单\n");
	printf(">————————————————————————————————\n");
}

void Quit()
{
	exit(0);
}

void Create(xxb* L)
{
	xx x;
	char ch;
	int n = 0, i;
	do
	{
		printf(">————————————————————————————————\n");
		if (L->length == MaxLen)
		{
			printf("通讯录已满！\n");
			system("pause");
			system("cls");
			return;
		}
		printf("请输入通讯者的编号：");
		fflush(stdin);
	num:gets(x.num);
		for (i = 0; i < L->length; i++)
		{
			if (strcmp(L->grxx[i].num, x.num) == 0)
			{
				printf(">————————————————————————————————\n");
				printf("已有此编号，请重新输入：");
				goto num;
			}
		}
		printf("请输入通讯者的姓名：");
		gets(x.name);
		printf("请输入通讯者的性别：");
		gets(x.sex);
		printf("请输入通讯者的电话：");
		gets(x.phone);
		printf("请输入通讯者的公司名称：");
		gets(x.address);
		L->grxx[L->length++] = x;
		n++;
		printf(">————————————————————————————————\n");
		printf("是否继续添加通讯者信息？（Y/N）：");
		scanf_s(" %c", &ch);
	} while (ch == 'y' || ch == 'Y');
	printf(">————————————————————————————————\n");
	printf("本次共添加%d位信息\n", n);
	system("pause");
	system("cls");
	return;
}

void Add(xxb* L)
{
	xx x;
	char ch;
	printf(">————————————————————————————————\n");
	if (L->length == MaxLen)
	{
		printf("通讯录已满！\n");
		return;
	}
	printf("请输入通讯者的编号：");
	fflush(stdin);
num:gets(x.num);
	for (int i = 0; i < L->length; i++)
	{
		if (strcmp(L->grxx[i].num, x.num) == 0)
		{
			printf(">————————————————————————————————\n");
			printf("已有此编号，请重新输入：");
			goto num;
		}
	}
	printf("请输入通讯者的姓名：");
	gets(x.name);
	printf("请输入通讯者的性别：");
	gets(x.sex);
	printf("请输入通讯者的电话：");
	gets(x.phone);
	printf("请输入通讯者的公司名称：");
	gets(x.address);
	L->grxx[L->length++] = x;
	printf(">————————————————————————————————\n");
	printf("添加成功！\n");
	system("pause");
	system("cls");
	return;
}

void Find(xxb L)
{
	int i;
	xx r;
	char e[20];
	printf(">————————————————————————————————\n");
	printf("1.按姓名查找\n");
	printf("2.按手机号码查找\n");
	printf("3.按编号查找\n");
	printf("0.返回菜单\n");
	printf(">————————————————————————————————\n");
	printf("请选择查找方式：");
loop1:scanf_s (" %d", &i);
	if (i < 0 || i > 3) {
		printf(">————————————————————————————————\n");
		printf("未设定功能，请重新输入:");
		goto loop1;
	}
	switch (i)
	{
	case 1:
		printf(">————————————————————————————————\n");
		printf("请输入姓名：");
		scanf_s ("%s", e);
		for (i = 0; i < L.length; i++)
		{
			r = L.grxx[i];
			if (strcmp(r.name, e) == 0)
			{
				printf(">————————————————————————————————\n");
				printf("姓名为（%s）的通讯者的其他信息为:\n编号：%s\t性别：%s\t电话：%s\t公司名称：%s\n", e, r.num, r.sex, r.phone, r.address);
				printf(">————————————————————————————————\n");
				system("pause");
				system("cls");
				return;
			}
		}
		printf(">————————————————————————————————\n");
		printf("未找到姓名为（%s）的通讯者\n", e);
		system("pause");
		system("cls");
		break;
	case 2:
		printf(">————————————————————————————————\n");
		printf("请输入电话：");
		scanf_s ("%s", e);
		for (i = 0; i < L.length; i++)
		{
			r = L.grxx[i];
			if (strcmp(r.phone, e) == 0)
			{
				printf(">————————————————————————————————\n");
				printf("电话为（%s）的通讯者的其他信息为:\n编号：%s\t性别：%s\t电话：%s\t公司名称：%s\n", e, r.num, r.name, r.sex, r.address);
				printf(">————————————————————————————————\n");
				system("pause");
				system("cls");
				return;
			}
		}
		printf(">————————————————————————————————\n");
		printf("未找到姓名为（%s）的通讯者\n", e);
		system("pause");
		system("cls");
		break;
	case 3:
		printf(">————————————————————————————————\n");
		printf("请输入编号：");
		scanf_s ("%s", e);
		for (i = 0; i < L.length; i++)
		{
			r = L.grxx[i];
			if (strcmp(r.num, e) == 0)
			{
				printf(">————————————————————————————————\n");
				printf("编号为（%s）的通讯者的其他信息为:\n编号：%s\t性别：%s\t电话：%s\t公司名称：%s\n", e, r.name, r.sex, r.phone, r.address);
				printf(">————————————————————————————————\n");
				system("pause");
				system("cls");
				return;
			}
		}
		printf(">————————————————————————————————\n");
		printf("未找到姓名为（%s）的通讯者\n", e);
		system("pause");
		system("cls");
		break;
	case 0:
		system("cls");
		break;
	}
	return;
}

void Alter(xxb* L)
{
	int i, k = 0;
	xx r;
	char e[20];
	printf(">————————————————————————————————\n");
	printf("1.按姓名修改\n");
	printf("2.按手机号码修改\n");
	printf("3.按编号修改\n");
	printf("0.返回菜单\n");
	printf(">————————————————————————————————\n");
	printf("请选择修改方式：");
loop2:scanf_s (" %d", &i);
	if (i < 0 || i > 3) {
		printf(">————————————————————————————————\n");
		printf("未设定功能，请重新输入:");
		goto loop2;
	}
	switch (i)
	{
	case 1:
		printf(">————————————————————————————————\n");
		printf("请输入要修改人的姓名：");
		scanf_s ("%s", e);
		for (i = 0; i < L->length; i++)
		{
			r = L->grxx[i];
			if (strcmp(r.name, e) == 0)
			{
				k = 1;
				break;
			}
		}
		if (k == 0)
		{
			printf(">————————————————————————————————\n");
			printf("未找到姓名为（%s）的通讯者\n", e);
			system("pause");
			system("cls");
			break;
		}
		else
		{
			printf(">————————————————————————————————\n");
			printf("姓名为（%s）的通讯者的原信息为:\n编号：%s\t性别：%s\t手机号码：%s\t公司名称：%s\n", e, r.num, r.sex, r.phone, r.address);
			printf(">————————————————————————————————\n");
			printf("请选择要修改的数据\n");
			printf("\t1.姓名；\n");
			printf("\t2.性别；\n");
			printf("\t3.电话；\n");
			printf("\t4.公司名称；\n");
			printf("\t0.退出\n");
			printf(">————————————————————————————————\n");
			printf("您要修改姓名为（%s）通讯者的哪项数据？\n", e);
			scanf_s ("%d", &k);
			switch (k)
			{
			case 1:
				printf("请输入新姓名：");
				scanf_s ("%s", r.name);
				break;
			case 2:
				printf("请输入新性别：");
				scanf_s ("%s", r.sex);
				break;
			case 3:
				printf("请输入新手机号码：");
				scanf_s ("%s", r.phone);
				break;
			case 4:
				printf("请输入新公司名称：");
				scanf_s ("%s", r.address);
				break;
			}
			L->grxx[i] = r;
			printf(">————————————————————————————————\n");
			printf("修改成功！\n");
		}
		system("pause");
		system("cls");
		break;
	case 2:
		printf(">————————————————————————————————\n");
		printf("请输入要修改人的手机号码：");
		scanf_s ("%s", e);
		for (i = 0; i < L->length; i++)
		{
			r = L->grxx[i];
			if (strcmp(r.phone, e) == 0)
			{
				k = 1;
				break;
			}
		}
		if (k == 0)
		{
			printf(">————————————————————————————————\n");
			printf("未找到手机号码为（%s）的通讯者\n", e);
			system("pause");
			system("cls");
			break;
		}
		else
		{
			printf(">————————————————————————————————\n");
			printf("手机号码为（%s）的通讯者的原信息为:\n编号：%s\t性别：%s\t手机号码：%s\t公司名称：%s\n", e, r.num, r.name, r.sex, r.address);
			printf(">————————————————————————————————\n");
			printf("请选择要修改的数据\n");
			printf("\t1.姓名；\n");
			printf("\t2.性别；\n");
			printf("\t3.电话；\n");
			printf("\t4.公司名称；\n");
			printf("\t0.退出\n");
			printf(">————————————————————————————————\n");
			printf("您要修改手机号码为（%s）通讯者的哪项数据？\n", e);
			scanf_s ("%d", &k);
			switch (k)
			{
			case 1:
				printf("请输入新姓名：");
				scanf_s ("%s", r.name);
				break;
			case 2:
				printf("请输入新性别：");
				scanf_s ("%s", r.sex);
				break;
			case 3:
				printf("请输入新手机号码：");
				scanf_s ("%s", r.phone);
				break;
			case 4:
				printf("请输入新公司名称：");
				scanf_s ("%s", r.address);
				break;
			}
			L->grxx[i] = r;
			printf(">————————————————————————————————\n");
			printf("修改成功！\n");
		}
		system("pause");
		system("cls");
		break;
	case 3:
		printf(">————————————————————————————————\n");
		printf("请输入要修改人的编号：");
		scanf_s ("%s", e);
		for (i = 0; i < L->length; i++)
		{
			r = L->grxx[i];
			if (strcmp(r.num, e) == 0)
			{
				k = 1;
				break;
			}
		}
		if (k == 0)
		{
			printf(">————————————————————————————————\n");
			printf("未找到姓名为（%s）的通讯者\n", e);
			system("pause");
			system("cls");
			break;
		}
		else
		{
			printf(">————————————————————————————————\n");
			printf("编号为（%s）的通讯者的其他信息为:\n编号：%s\t性别：%s\t电话：%s\t公司名称：%s\n", e, r.name, r.sex, r.phone, r.address);
			printf(">————————————————————————————————\n");
			printf("请选择要修改的数据\n");
			printf("\t1.姓名；\n");
			printf("\t2.性别；\n");
			printf("\t3.电话；\n");
			printf("\t4.公司名称；\n");
			printf("\t0.退出\n");
			printf(">————————————————————————————————\n");
			printf("您要修改手机号码为（%s）通讯者的哪项数据？\n", e);
			scanf_s ("%d", &k);
			switch (k)
			{
			case 1:
				printf("请输入新姓名：");
				scanf_s ("%s", r.name);
				break;
			case 2:
				printf("请输入新性别：");
				scanf_s ("%s", r.sex);
				break;
			case 3:
				printf("请输入新手机号码：");
				scanf_s ("%s", r.phone);
				break;
			case 4:
				printf("请输入新公司名称：");
				scanf_s ("%s", r.address);
				break;
			}
			L->grxx[i] = r;
			printf(">————————————————————————————————\n");
			printf("修改成功！\n");
		}
		system("pause");
		system("cls");
		break;
	case 0:
		system("cls");
		break;
	}
	return;
}

void Delete(xxb* L)
{
	int i, j, k = 0;
	xx r;
	char e[20], y;
	printf(">————————————————————————————————\n");
	printf("1.按姓名删除\n");
	printf("2.按手机号码删除\n");
	printf("3.按编号删除\n");
	printf("0.返回菜单\n");
	printf(">————————————————————————————————\n");
	printf("请选择修改方式：");
loop3:scanf_s (" %d", &i);
	if (i < 0 || i > 3) {
		printf(">————————————————————————————————\n");
		printf("未设定功能，请重新输入:");
		goto loop3;
	}
	switch (i)
	{
	case 1:
		printf(">————————————————————————————————\n");
		printf("请输入要删除的通讯者的姓名：");
		scanf_s ("%s", e);
		for (i = 0; i < L->length; i++)
		{
			r = L->grxx[i];
			if (strcmp(r.name, e) == 0)
			{
				k = 1;
				break;
			}
		}
		if (k == 0)
		{
			printf(">————————————————————————————————\n");
			printf("未找到姓名为（%s）的通讯者\n", e);
			system("pause");
			system("cls");
			break;
		}
		else
		{
			printf(">————————————————————————————————\n");
			printf("姓名为（%s）的通讯者的原信息为:\n编号：%s\t性别：%s\t手机号码：%s\t公司名称：%s\n", e, r.num, r.sex, r.phone, r.address);
			printf(">————————————————————————————————\n");
			printf("您确定要删除吗？（Y/N）\n");
			scanf_s (" %c", &y);
			if (y == 'y' || y == 'Y')
			{
				for (j = i; j < L->length; j++)
					L->grxx[j] = L->grxx[j + 1];
				L->length--;
				printf(">————————————————————————————————\n");
				printf("删除成功！\n");
				system("pause");
				system("cls");
				return;
			}
			else
			{
				printf(">————————————————————————————————\n");
				printf("您已取消删除！\n");
				system("pause");
				system("cls");
				return;
			}
		}
		system("pause");
		system("cls");
		break;
	case 2:
		printf(">————————————————————————————————\n");
		printf("请输入要删除的通讯者的手机号码：");
		scanf_s ("%s", e);
		for (i = 0; i < L->length; i++)
		{
			r = L->grxx[i];
			if (strcmp(r.phone, e) == 0)
			{
				k = 1;
				break;
			}
		}
		if (k == 0)
		{
			printf(">————————————————————————————————\n");
			printf("未找到手机号码为（%s）的通讯者\n", e);
			system("pause");
			system("cls");
			break;
		}
		else
		{
			printf(">————————————————————————————————\n");
			printf("手机号码为（%s）的通讯者的原信息为:\n编号：%s\t性别：%s\t手机号码：%s\t公司名称：%s\n", e, r.num, r.name, r.sex, r.address);
			printf(">————————————————————————————————\n");
			printf("您确定要删除吗？（Y/N）\n");
			scanf_s (" %c", &y);
			if (y == 'y' || y == 'Y')
			{
				for (j = i; j < L->length; j++)
					L->grxx[j] = L->grxx[j + 1];
				L->length--;
				printf(">————————————————————————————————\n");
				printf("删除成功！\n");
				system("pause");
				system("cls");
				return;
			}
			else
			{
				printf(">————————————————————————————————\n");
				printf("您已取消删除！\n");
				system("pause");
				system("cls");
				return;
			}
		}
		system("pause");
		system("cls");
		break;
	case 3:
		printf(">————————————————————————————————\n");
		printf("请输入要删除的通讯者的编号：");
		scanf_s ("%s", e);
		for (i = 0; i < L->length; i++)
		{
			r = L->grxx[i];
			if (strcmp(r.phone, e) == 0)
			{
				k = 1;
				break;
			}
		}
		if (k == 0)
		{
			printf(">————————————————————————————————\n");
			printf("未找到编号为（%s）的通讯者\n", e);
			system("pause");
			system("cls");
			break;
		}
		else
		{
			printf(">————————————————————————————————\n");
			printf("编号为（%s）的通讯者的其他信息为:\n编号：%s\t性别：%s\t电话：%s\t公司名称：%s\n", e, r.name, r.sex, r.phone, r.address);
			printf(">————————————————————————————————\n");
			printf("您确定要删除吗？（Y/N）\n");
			scanf_s (" %c", &y);
			if (y == 'y' || y == 'Y')
			{
				for (j = i; j < L->length; j++)
					L->grxx[j] = L->grxx[j + 1];
				L->length--;
				printf(">————————————————————————————————\n");
				printf("删除成功！\n");
				system("pause");
				system("cls");
				return;
			}
			else
			{
				printf(">————————————————————————————————\n");
				printf("您已取消删除！\n");
				system("pause");
				system("cls");
				return;
			}
		}
		system("pause");
		system("cls");
		break;
	case 0:
		system("cls");
		break;
	}
	return;
}

void List(xxb L)
{
	xx r;
	int i;
	printf("通讯者信息：\n");
	for (i = 0; i < L.length; i++)
	{
		r = L.grxx[i];
		printf("(%d)编号：%s\t姓名：%s\t性别：%s\t电话：%s\t公司名称：%s\n", i + 1, r.num, r.name, r.sex, r.phone, r.address);
	}
	system("pause");
	system("cls");
	return;
}

void nv(xxb L)
{
	int i, n = 0, v = 0;
	for (i = 0; i < L.length; i++)
	{
		if (strcmp(L.grxx[i].sex, "��") == 0)
			n++;
		else
			v++;
	}
	printf(">————————————————————————————————\n");
	printf("通讯录中男女比例为%d：%d", n, v);
	system("pause");
	system("cls");
	return;
}
void ti(xxb L)
{
	xx r;
	int i, k = 0;
	char e[20];
	printf(">————————————————————————————————\n");
	printf("请输入您要查找人员信息的公司名称：");
	scanf_s (" %s", e);
	for (i = 0; i < L.length; i++)
	{
		if (strcmp(L.grxx[i].address, e) == 0)
		{
			k = 1;
			break;
		}
	}
	if (k == 0)
	{
		printf(">————————————————————————————————\n");
		printf("本通讯录没有公司为（%s）的人员信息！", e);
		system("pause");
		system("cls");
		return;
	}
	else
	{
		printf(">————————————————————————————————\n");
		printf("本通讯录里公司为（%s）的所有人员信息为：\n", e);
		for (i = 0; i < L.length; i++)
		{
			r = L.grxx[i];
			if (strcmp(L.grxx[i].address, e) == 0)
				printf("(%d)编号：%s\t姓名：%s\t性别：%s\t电话：%s\t公司名称：%s\n", k++, r.num, r.name, r.sex, r.phone, r.address);
		}
		printf(">————————————————————————————————\n");
		system("pause");
		system("cls");
		return;
	}
	return;
}

