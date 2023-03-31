#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
	char name[20];//����
	int  age;     //����
	int  stuNum;  //ѧ��
	int  score;   //�ɼ�
}Student;

typedef struct Node
{
	Student stu;        //ѧ��
	struct Node* next;//ָ����һ���ڵ��ָ��
}Node;

Node* L = NULL;

void Welcome();//��ӭ
void InputStudent();//¼��ѧ����Ϣ
void PrintStudent();//��ӡѧ����Ϣ
void SaveStudent();//����ѧ����Ϣ
void ReadStudent();//��ȡѧ����Ϣ
int CountStudent();//ͳ������ѧ������
Node* FindStudent();//����ѧ����Ϣ
void ModifyStudent();//�޸�ѧ����Ϣ
void DeleteStudent();//ɾ��ѧ����Ϣ

int main()
{
	while (1)
	{
		Welcome();
		char ch = getch();
		switch (ch)
		{
		case'1'://¼��ѧ����Ϣ
			InputStudent();
			break;
		case'2'://��ӡѧ����Ϣ
			PrintStudent();
			break;
		case'3'://����ѧ����Ϣ
			SaveStudent();
			break;
		case'4'://��ȡѧ����Ϣ
			ReadStudent();
			break;
		case'5'://ͳ������ѧ������
			printf("ѧ��������Ϊ:%d\n", CountStudent());
			system("pause");//��ͣ
			system("cls");//����
			break;
		case'6'://����ѧ����Ϣ
		{
			Node* p = FindStudent();
			if (p != NULL)
			{
				printf("ѧ�ţ�%d\t������%s\t���䣺%d\t�ɼ���%d\n",
					p->stu.stuNum,
					p->stu.name,
					p->stu.age,
					p->stu.score);
			}
			else
				printf("û���ҵ���ѧ��.\n");
			system("pause");//��ͣ
			system("cls");//����
			break;
		}
		case'7'://�޸�ѧ����Ϣ
			ModifyStudent();
			break;
		case'8'://ɾ��ѧ����Ϣ
			DeleteStudent();
			break;
		case'0'://�˳�ϵͳ
			return 0;
		default:
			printf("������������,����������.\n");
			system("pause");//��ͣ
			system("cls");//����
		}
	}
	return 0;
}

//ϵͳ����
void Welcome()
{
	printf("*************************************************\n");
	printf("*\t��ӭʹ�ø�Уѧ���ɼ�����ϵͳV1.0\t*\n");
	printf("*************************************************\n");
	printf("*\t\t��ѡ�����б�\t\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t1.¼��ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t2.��ӡѧ����Ϣ\t\t\t*\n");
	printf("*\t\t3.����ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t4.��ȡѧ����Ϣ\t\t\t*\n");
	printf("*\t\t5.ͳ������ѧ������\t\t*\n");
	printf("*\t\t6.����ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t7.�޸�ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t8.ɾ��ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t0.�˳�ϵͳ\t\t\t*\n");
	printf("*************************************************\n");
}

//¼��ѧ����Ϣ
void InputStudent()
{
	//����һ���½ڵ�
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->next = NULL;

	//ͷ�巨
	if (L == NULL)
	{
		L = pNewNode;
	}
	else
	{
		pNewNode->next = L;
		L = pNewNode;
	}
	printf("������ѧ��������\n");
	scanf("%s", pNewNode->stu.name);
	printf("������ѧ�����䣺\n");
	scanf("%d", &pNewNode->stu.age);
	printf("������ѧ��ѧ�ţ�\n");
	scanf("%d", &pNewNode->stu.stuNum);
	printf("������ѧ���ɼ���\n");
	scanf("%d", &pNewNode->stu.score);

	printf("ѧ����Ϣ¼��ɹ�.\n");
	system("pause");//��ͣ
	system("cls");//����
}

//��ӡѧ����Ϣ
void PrintStudent()
{
	system("cls");//����
	printf("*************************************************\n");
	printf("*\t��ӭʹ�ø�Уѧ���ɼ�����ϵͳV1.0\t*\n");
	printf("*************************************************\n");
    printf("*\tѧ��\t*\t����\t*\t����\t*\t�ɼ�\t*\n");
	printf("*************************************************\n");

	//��������
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
	system("pause");//��ͣ
	system("cls");//����
}

//����ѧ����Ϣ
void SaveStudent()
{
	//���ļ�
	FILE* fp = fopen("D:\\Document\\Book\\Student achievement management system\\StudentManagerSystem\\stuinfo.data", "w");

	if (fp == NULL)
	{
		printf("���ļ�ʧ��.\n");
	}

	//��������
	Node* p = L;
	while (p != NULL)
	{
		fwrite(&p->stu, 1, sizeof(Student), fp);
		p = p->next;
	}

	//�ر��ļ�
	fclose(fp);
	printf("���ݱ���ɹ�\n");
	system("pause");//��ͣ
	system("cls");//����
}

//��ȡѧ����Ϣ
void ReadStudent()
{
	//���ļ�
	FILE* fp = fopen("D:\\Document\\Book\\Student achievement management system\\StudentManagerSystem\\stuinfo.data", "r");
	
	if (fp == NULL)
	{
		printf("���ļ�ʧ��.\n");
		return;
	}

	//���ļ�
	Student stu;
	while (fread(&stu, 1, sizeof(Student), fp))
	{
		//����һ���½ڵ�
		Node* pNewNode = (Node*)malloc(sizeof(Node));
		pNewNode->next = NULL;

		memcpy(pNewNode, &stu, sizeof(Student));

		//ͷ�巨
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

	//�ر��ļ�
	fclose(fp);
	printf("�������ݳɹ�.\n");
	system("pause");//��ͣ
	system("cls");//����
}

//ͳ������ѧ������
int CountStudent()
{
	int nCount = 0;//ѧ������
	//����
	Node* p = L;
	while (p!=NULL)
	{
		nCount++;
		p = p->next;
	}
	return nCount;
}
//����ѧ����Ϣ
Node* FindStudent()
{
	int StuNum;
	char SName[20];
	printf("������Ҫ��ѯ��ѧ����ѧ�ţ�\n");
	scanf("%d", &StuNum);

	printf("������Ҫ��ѯ��ѧ����������\n");
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

//�޸�ѧ����Ϣ
void ModifyStudent()
{
	int nStuNum;
	printf("��������Ҫ�޸ĵ�ѧ����Ϣ��ѧ�ţ�\n");
	scanf("%d", &nStuNum);

	Node* p = L;
	while (p!=NULL)
	{
		//strcmp�ַ����ȽϺ���
		if (p->stu.stuNum == nStuNum)
		{
			printf("������Ҫ�޸ĵ�ѧ������ ���� �ɼ���\n");
			scanf("%s %d %d",
				p->stu.name,
				&p->stu.age,
				&p->stu.score);
			printf("�޸ĳɹ���\n");
			break;
		}
		p = p->next;
	}

	if (p == NULL)
	{
		printf("δ�ҵ���ѧ����Ϣ.\n");
	}
	system("pause");//��ͣ
	system("cls");//����
}

//ɾ��ѧ����Ϣ
void DeleteStudent()
{
	int nStuNum;
	printf("������Ҫɾ����ѧ����ѧ�ţ�\n");
    scanf("%d", &nStuNum);

	Node* p = L, * q = NULL;
	
	while (p != NULL)
	{
		if (p->next->stu.stuNum == nStuNum)
		{
			q = p->next;
			p->next = q->next;
			free(q);
			printf("ɾ���ɹ�\n");
			system("pause");//��ͣ
			system("cls");//����
			return;
		}
		p = p->next;
	}
	
	if (p == NULL)
	{
		printf("ɾ��ʧ��,δ�ҵ���ѧ����Ϣ.\n");
	}
	system("pause");//��ͣ
	system("cls");//����
}