//2.�������ն�������Ĵ洢�ṹ
//Ԥ��������
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR  0
#define OVERFLOW -2
 
//���ݽṹ����
typedef  int  Status;  
typedef  char TElemType;  

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;//��BiTnodeӵ��struct BiTnode *P�еġ�struct BiTnode* ���Ĺ���


//��������
int menu_select();
Status InitBiTree(BiTree &T);//��ʼ����������
Status CreateBiTree(BiTree &T);//������������������ʱ���ȸ���㣬������������������

void PreOrderTraverse(BiTree T,Status(*Visit)(TElemType));//����������
void InOrderTraverse(BiTree T,Status(*Visit)(TElemType));//����������
void PostOrderTraverse(BiTree T,Status(*Visit)(TElemType));//����������
Status PrintElem(TElemType e);//��ӡ
void DisplayTree(BiTree T,int i);//��������ʾ
int Leaf(BiTree T);//��Ҷ����
int Depth (BiTree T);//�����
Status Preorder (BiTree T, TElemType x, BiTree &p);//��ѯ
void DestroyBiTree(BiTree &T);//����

//������
int main()
{
	BiTree T,p;//��������ָ��T��P
	Status s;
	int n0,h;
	TElemType e;//Ԫ��e
	for(;;)
	{
		switch(menu_select())
		{
		case 1:
			s=InitBiTree(T);
			if(s)
				printf("��ʼ���ɹ�\n");
			else
				printf("��ʼ��ʧ��\n");
			break;
		case 2:
			getchar();
			printf("���������������չ�������У�");			
			s=CreateBiTree(T);			
			if(s)
				printf("�����ɹ�\n");
			else
				printf("����ʧ��\n");
			break;
		case 3:
			printf("�����������Ϊ��\n");
			PreOrderTraverse(T,PrintElem);			
			break;
		case 4:
			printf("�����������Ϊ��\n");
			InOrderTraverse(T,PrintElem);
			break;
		case 5:
			printf("�����������Ϊ��\n");
			PostOrderTraverse(T,PrintElem);
			break;
		case 6:printf("������ʾ\n");
			DisplayTree(T,0);
			break;
		case 7:
			n0=Leaf(T);
			printf("Ҷ�ӽ�����Ϊ%d\n",n0);
			break;
		case 8:
			h=Depth(T);
			printf("���������Ϊ%d\n",h);
			break;
		case 9:
			printf("������Ҫ���ҵ�Ԫ�ص�ֵ��");
			getchar();
			scanf("%c",&e);
			s=Preorder (T, e, p) ;
			if(s)
				printf("���ҵ�Ԫ��%c\n",p->data);
			else
				printf("δ�ҵ�\n");			
			break;
		case 10:
			DestroyBiTree(T);
			printf("������������\n");	
			break;
		case 0:
			printf("���������ллʹ�ã�\n\n"); 
			exit(0);
		}
	}
	return 0;
}
//�˵�����
int menu_select()
{
	int sn;
	printf("\n��ʾ�˵�\n");
	printf("1.��ʼ��һ��������������\n");
	printf("2.����չ���������еķ�ʽ����������\n");
	printf("3.��������������\n");
	printf("4.��������������\n");	
	printf("5.��������������\n");
	printf("6.������ʾ������������\n");	
	printf("7.���������Ҷ���ĸ�������\n");
	printf("8.�����������Ȳ���\n");	
	printf("9.���Ҷ������е�ĳ������ֵ\n");
	printf("10.���ٶ�����\n");
	printf("0.�˳�\n");
	printf("���� 0-10:");
	for(;;)
	{
		scanf("%d",&sn);
		if(sn<0||sn>10)
			printf("\n���������ѡ0��10��");
		else
			break;
	}
	return sn;
}
//��ʼ����������
Status InitBiTree(BiTree &T)
{
	T=NULL;//ָ���ַΪ��
	return OK;
}
//����������
Status CreateBiTree(BiTree &T)
{
	TElemType ch;
	scanf("%c",&ch);
	if(ch == ' ')	   
		T=NULL;
	else 
	{
		T=(BiTNode *)malloc(sizeof(BiTNode));//����Ĳ�Ϊ�գ�ָ��Tָ�����ַ
		if(!T)
			exit(OVERFLOW);//�����Ϊ�գ�Tָ��գ���̬�ڴ�����ʧ�ܣ��������
		T->data = ch;

		CreateBiTree(T->lchild);//��һ�����������ֵ��T->data��Ȼ�󴴽������ӣ����ڶ������������ֵ�����ӣ��ٴ����ô�������		                         
		CreateBiTree(T->rchild);//�ٴ����Һ��ӽڵ㡣�����������������Ϊ�գ����Ǹ����ӽڵ��Ϊ��
	}
	return OK;
}
//�������
void PreOrderTraverse(BiTree T,Status(*Visit)(TElemType))
{
	if(T)
	{
		Visit(T->data);  
		PreOrderTraverse(T->lchild,Visit);     
		PreOrderTraverse(T->rchild,Visit); 
	} 
}
//�������
void InOrderTraverse(BiTree T,Status(*Visit)(TElemType))
{
	if(T)
	{		
		InOrderTraverse(T->lchild,Visit);
		Visit(T->data); // �м���ʸ����    
		InOrderTraverse(T->rchild,Visit); 
	} 
}
//�������
void PostOrderTraverse(BiTree T,Status(*Visit)(TElemType))
{
	if(T)
	{		
		PostOrderTraverse(T->lchild,Visit);     
		PostOrderTraverse(T->rchild,Visit); 
		Visit(T->data); // ����ʸ����
	} 
}
//��ӡһ������Ԫ�غ���
Status PrintElem(TElemType e)
{
	printf("%c\t",e);
	return OK;
}
//��������ʾ
void DisplayTree(BiTree T,int i)//���������˳��������
{
	int j;
	if (T == NULL) return;
	if(T->lchild!=NULL)
		DisplayTree(T->lchild,i+1); 	
	for(j=1;j<=i;j++) 	
		printf("\t");
	printf("       %c",T->data);
	for(j=i+1;j<=8;j++)		
		printf("--------");
	printf("\n");
	if(T->rchild!=NULL)
		DisplayTree(T->rchild,i+1);
}
//��Ҷ����
int Leaf(BiTree T)
{ 
	if(T)
	{
		if ((T->lchild==NULL)&&(T->rchild==NULL))
			return 1;
		else 
			return Leaf(T->lchild)+Leaf(T->rchild);//���ڼ�Ϊ1���ݹ�˼��
	}
	else return 0;
}
//������������
int Depth (BiTree T)
{ 
	int depthval,depthLeft,depthRight;
	if ( !T )   depthval = 0;
	else   
	{
		depthLeft = Depth( T->lchild );
		depthRight= Depth( T->rchild );
		depthval = 1 + (depthLeft > depthRight ? depthLeft : depthRight);//��ߴ�ͽ��Ϊ�󣬵ݹ�˼��
	} 
	return depthval;
}
// ���������д��ں� x ��ͬ��Ԫ�أ��� p ָ
// ��ý�㲢���� OK,���򷵻� FALSE  
Status Preorder (BiTree T, TElemType x, BiTree &p) 
{	
	if (T) 
	{
		if (T->data==x)
		{
			p = T; return OK;
		} 
		else 
		{
			if (Preorder(T->lchild, x, p)) return OK;
			else return(Preorder(T->rchild, x, p)) ;
		}//else
	}//if(T) 
    else return ERROR;
}
// ��ʼ����: ������T���ڡ��������: ���ٶ�����T
void DestroyBiTree(BiTree &T)
{ 
	if(T) // �ǿ���
	{ 
		if(T->lchild) // ������
			DestroyBiTree(T->lchild); // ������������
		if(T->rchild) // ���Һ���
			DestroyBiTree(T->rchild); // �����Һ�������
		free(T); // �ͷŸ����
		T=NULL; // ��ָ�븳0
	} 
}//���ٶ������ĵݹ��㷨
