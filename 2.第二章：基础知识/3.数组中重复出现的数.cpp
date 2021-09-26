#include<iostream>
using namespace std;


int GetSize(int data[])
{
	return sizeof(data);
}
void test01()
{
	int data1[] = {1,2,3,4,5};
	int *data2 = data1;
	cout<<sizeof(data1)<<endl;
	cout<<sizeof(data2)<<endl;//data2ָ������ĵ�һ�����֣�����������ָ��  
	cout<<GetSize(data1)<<endl;//������Ϊ������������ʱ���Զ��˻�Ϊͬ���͵�ָ��

}


 bool duplicate(int numbers[],int length,int* duplication)
 {
	 if(numbers==NULL || length<=0)
		 return false;
	 int i;
	 for(i = 0;i<length;i++)//��ĿҪ�������ֵ��0 <= val <= length-1
	 {
		 if(numbers[i]<0  || numbers[i]>length-1)
		 {
			 return false;
		 }
	 }
	 for(i = 0;i<length;++i)
	 {
		 while(numbers[i] != i)//����ѭ�� ÿ��������ཻ��2�ξ����ҵ��Լ���λ��
		 {
			 if(numbers[i] == numbers[numbers[i]])
			 {
				 *duplication = numbers[i];
				 return true;
			 }cout<<numbers[i]<<" "<<numbers[numbers[i]]<<endl;
			 swap(numbers[i],numbers[numbers[i]]);
		 }
	 }
	 return false;
 }

void test02()
{
	int numbers[] = {1,2,4,3,4};
	int *duplication = new int;
	if(duplicate(numbers,5,duplication))
		cout<<*duplication<<endl;
}




//�ڳ���Ϊn������ֵ��Χ��1-n����������ҳ��ظ���ֵ
 
 


//��ָoffer  
// ��������һ��Ϊ�������������� ��1-n/2�����������������n/2����ô�ظ������־���ǰһ�룬��֮�ں�һ�� ���ظ�һ��Ϊ��

int countRange(const int *numbers, int length, int start, int end)
{
	if(numbers == NULL)
		return 0;
	int count = 0;
	for(int i = 0; i<length; i++)
	{
		if(numbers[i] >= start && numbers[i] <= end)
		{
			++count;
		}
	}
	return count;
} 
int getDuplication(const int *numbers,int length)
{
	if(numbers == NULL ||length <=0)
		return -1;
	int start = 1;
	int end = length-1;
	while(end >= start)
	{
		int middle = ((end - start)>>1)+start;
		int count = countRange(numbers, length, start, middle);
		if(end == start)
		{
			if(count > 1)
				return start;
			else
				break;
		}
		if(count > (middle - start + 1))
			end = middle;
		else
			start = middle+1;
	}
	return -1;

}
 


void test05()
{
	int numbers[] = {1,3,2,4,5,6,7,8,3};
	cout<<getDuplication(numbers,9)<<endl;
}







//��ָoffer�ϵ���Ŀ�ܾ���   ǰ��������  1-n  �漴����һ���ظ���  Ӧ�÷�չ����Ƶķ���
//һ��ɾ��k����ͬ�����������˭��ɾ������
//----------------------------------------------------���ڲ��ɹ� 
int * find(int a[],int n,int k)  //�ռ临�Ӷȣ�2k    ʱ�临�Ӷȣ�С��kn
{
	int *a2 = new int[k];//��ֵ
	int *a3 = new int[k] ;//��Ѫ��
	int i, j, s;
    for(i = 0;i<k;i++)   a3[i] = 0;

	for(i = 0,j = 0;i < n ;i++) //{1,1,1,2,2,2,3,3,3,10};
	{ 
		if(j>=k)
		{
            s=0;
			for(int x = 0;x<j;x++)
			{
				if(a[i]==a2[x])
				{
					a3[x]++;
					s=1; // Ѫ��+1
				}
			}
			if(s==0)
			{
			 for(int y = 0; y<n; y++)
			 {
				 a3[y]--;// Ѫ��-1
				 if(a3[y] == 0)
				 {
					 a2[y] = -1;
					 j--;
				 }
			 }
			}
		continue;
		}

		if(j<k) //��û��kװ��
		{
			s=0;
			for(int x = 0; x<k; x++)
			{
				if(a[i]==a2[x])
				{
					a3[x]++; // Ѫ��+1
					s=1;
				}
			}
			
			if(s==0)
			{
				for(int y = 0; y<k; y++)
				{
					if(a3[y]==0)
					{
						a3[y]=1;// Ѫ��+1
						a2[y]=a[i]; //������ֵ	
						j++;
						break;
					}
				} 
			}
		}

		//	if(i == n-1)
		{
			cout<<a[i]<<"    "<<a2[0]<<a2[1]<<a2[2]<<a2[3]<<a2[4]<<a3[0]<<a3[1]<<a3[2]<<a3[3]<<a3[4]<<endl;  
		}
	} 
	int num=0;
	for(i =0;i<k;i++)
	{
		if(a3[i] > 0)
			num++;
	} cout<<num<<endl;
	int *retu = new int[num] ;//����num��С�Ŀռ�
	if(k<2) return retu;

	for(i = 0, j = 0 ;i <k; i++)
	{
		if(a3[i]  > 0)
			retu[j++] = a2[i];
	}

	delete[] a2;
	delete[] a3;
	return retu;
}


void test03()
{
	int a[] = {1,3,2,4,5,7,8,1,5};
 	int *retu = find(a,9,5);
 	for(int i = 0;   i<2;   i++)//sizeof(retu)/sizeof(retu[0])
 	 	cout<<retu[i]<<" ";
}









int main()
{
	test03();
	 

	return 0;
}

