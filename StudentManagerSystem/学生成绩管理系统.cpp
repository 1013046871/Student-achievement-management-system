#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
	char name[20];//姓名
	int  age;     //年龄
	int  stuNum;  //学号
	int  score;   //成绩
}Student;

typedef struct Node
{
	Student stu;        //学生
	struct Node* next;//指向下一个节点的指针
}Node;

Node* L = NULL;

void Welcome();//欢迎
void InputStudent();//录入学生信息
void PrintStudent();//打印学生信息
void SaveStudent();//保存学生信息
void ReadStudent();//读取学生信息
int CountStudent();//统计所有学生人数
Node* FindStudent();//查找学生信息
void ModifyStudent();//修改学生信息
void DeleteStudent();//删除学生信息

int main()
{
	while (1)
	{
		Welcome();
		char ch = getch();
		switch (ch)
		{
		case'1'://录入学生信息
			InputStudent();
			break;
		case'2'://打印学生信息
			PrintStudent();
			break;
		case'3'://保存学生信息
			SaveStudent();
			break;
		case'4'://读取学生信息
			ReadStudent();
			break;
		case'5'://统计所有学生人数
			printf("学生总人数为:%d\n", CountStudent());
			system("pause");//暂停
			system("cls");//清屏
			break;
		case'6'://查找学生信息
		{
			Node* p = FindStudent();
			if (p != NULL)
			{
				printf("学号：%d\t姓名：%s\t年龄：%d\t成绩：%d\n",
					p->stu.stuNum,
					p->stu.name,
					p->stu.age,
					p->stu.score);
			}
			else
				printf("没有找到该学生.\n");
			system("pause");//暂停
			system("cls");//清屏
			break;
		}
		case'7'://修改学生信息
			ModifyStudent();
			break;
		case'8'://删除学生信息
			DeleteStudent();
			break;
		case'0'://退出系统
			return 0;
		default:
			printf("您的输入有误,请重新输入.\n");
			system("pause");//暂停
			system("cls");//清屏
		}
	}
	return 0;
}

//系统界面
void Welcome()
{
	printf("*************************************************\n");
	printf("*\t欢迎使用高校学生成绩管理系统V1.0\t*\n");
	printf("*************************************************\n");
	printf("*\t\t请选择功能列表\t\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t1.录入学生信息\t\t\t*\n");
	printf("*\t\t2.打印学生信息\t\t\t*\n");
	printf("*\t\t3.保存学生信息\t\t\t*\n");
	printf("*\t\t4.读取学生信息\t\t\t*\n");
	printf("*\t\t5.统计所有学生人数\t\t*\n");
	printf("*\t\t6.查找学生信息\t\t\t*\n");
	printf("*\t\t7.修改学生信息\t\t\t*\n");
	printf("*\t\t8.删除学生信息\t\t\t*\n");
	printf("*\t\t0.退出系统\t\t\t*\n");
	printf("*************************************************\n");
}

//录入学生信息
void InputStudent()
{
	//创建一个新节点
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->next = NULL;

	//头插法
	if (L == NULL)
	{
		L = pNewNode;
	}
	else
	{
		pNewNode->next = L;
		L = pNewNode;
	}
	printf("请输入学生姓名：\n");
	scanf("%s", pNewNode->stu.name);
	printf("请输入学生年龄：\n");
	scanf("%d", &pNewNode->stu.age);
	printf("请输入学生学号：\n");
	scanf("%d", &pNewNode->stu.stuNum);
	printf("请输入学生成绩：\n");
	scanf("%d", &pNewNode->stu.score);

	printf("学生信息录入成功.\n");
	system("pause");//暂停
	system("cls");//清屏
}

//打印学生信息
void PrintStudent()
{
	system("cls");//清屏
	printf("*************************************************\n");
	printf("*\t欢迎使用高校学生成绩管理系统V1.0\t*\n");
	printf("*************************************************\n");
    printf("*\t学号\t*\t姓名\t*\t年龄\t*\t成绩\t*\n");
	printf("*************************************************\n");

	//遍历链表
	Node* p = L;
	while (p != NULL)
	{
		printf("*\t%d\t*\t%s\t*\t%d\t*\t%d\t*\n",
			p->stu.stuNum,
			p->stu.name,
			p->stu.age,
			p->stu.score);
		printf("*************************************************\n");
		p = p->next;
	}
	system("pause");//暂停
	system("cls");//清屏
}

//保存学生信息
void SaveStudent()
{
	//打开文件
	FILE* fp = fopen("D:\\Document\\Book\\Student achievement management system\\StudentManagerSystem\\stuinfo.data", "w");

	if (fp == NULL)
	{
		printf("打开文件失败.\n");
	}

	//遍历链表
	Node* p = L;
	while (p != NULL)
	{
		fwrite(&p->stu, 1, sizeof(Student), fp);
		p = p->next;
	}

	//关闭文件
	fclose(fp);
	printf("数据保存成功\n");
	system("pause");//暂停
	system("cls");//清屏
}

//读取学生信息
void ReadStudent()
{
	//打开文件
	FILE* fp = fopen("D:\\Document\\Book\\Student achievement management system\\StudentManagerSystem\\stuinfo.data", "r");
	
	if (fp == NULL)
	{
		printf("打开文件失败.\n");
		return;
	}

	//读文件
	Student stu;
	while (fread(&stu, 1, sizeof(Student), fp))
	{
		//创建一个新节点
		Node* pNewNode = (Node*)malloc(sizeof(Node));
		pNewNode->next = NULL;

		memcpy(pNewNode, &stu, sizeof(Student));

		//头插法
		if (L == NULL)
		{
			L = pNewNode;
		}
		else
		{
			pNewNode->next = L;
			L = pNewNode;
		}
	}

	//关闭文件
	fclose(fp);
	printf("加载数据成功.\n");
	system("pause");//暂停
	system("cls");//清屏
}

//统计所有学生人数
int CountStudent()
{
	int nCount = 0;//学生人数
	//遍历
	Node* p = L;
	while (p!=NULL)
	{
		nCount++;
		p = p->next;
	}
	return nCount;
}
//查找学生信息
Node* FindStudent()
{
	int StuNum;
	char SName[20];
	printf("请输入要查询的学生的学号：\n");
	scanf("%d", &StuNum);

	printf("请输入要查询的学生的姓名：\n");
	scanf("%s", SName);

	Node* p = L;
	while (p!=NULL)
	{
		if (p->stu.stuNum == StuNum || strcmp(p->stu.name, SName) == 0)
		{
			return p;
		}
		p = p->next;
	}

	return NULL;
}

//修改学生信息
void ModifyStudent()
{
	int nStuNum;
	printf("请输入需要修改的学生信息的学号：\n");
	scanf("%d", &nStuNum);

	Node* p = L;
	while (p!=NULL)
	{
		//strcmp字符串比较函数
		if (p->stu.stuNum == nStuNum)
		{
			printf("请输入要修改的学生姓名 年龄 成绩：\n");
			scanf("%s %d %d",
				p->stu.name,
				&p->stu.age,
				&p->stu.score);
			printf("修改成功。\n");
			break;
		}
		p = p->next;
	}

	if (p == NULL)
	{
		printf("未找到该学生信息.\n");
	}
	system("pause");//暂停
	system("cls");//清屏
}

//删除学生信息
void DeleteStudent()
{
	int nStuNum;
	printf("请输入要删除的学生的学号：\n");
    scanf("%d", &nStuNum);

	Node* p = L, * q = NULL;
	
	while (p != NULL)
	{
		if (p->next->stu.stuNum == nStuNum)
		{
			q = p->next;
			p->next = q->next;
			free(q);
			printf("删除成功\n");
			system("pause");//暂停
			system("cls");//清屏
			return;
		}
		p = p->next;
	}
	
	if (p == NULL)
	{
		printf("删除失败,未找到该学生信息.\n");
	}
	system("pause");//暂停
	system("cls");//清屏
}