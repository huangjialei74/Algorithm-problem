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
	cout<<sizeof(data2)<<endl;//data2指向数组的第一个数字，本质上仍是指针  
	cout<<GetSize(data1)<<endl;//数组作为函数参数传递时，自动退化为同类型的指针

}


 bool duplicate(int numbers[],int length,int* duplication)
 {
	 if(numbers==NULL || length<=0)
		 return false;
	 int i;
	 for(i = 0;i<length;i++)//题目要求：数组的值在0 <= val <= length-1
	 {
		 if(numbers[i]<0  || numbers[i]>length-1)
		 {
			 return false;
		 }
	 }
	 for(i = 0;i<length;++i)
	 {
		 while(numbers[i] != i)//两重循环 每个数字最多交换2次就能找到自己的位置
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




//在长度为n，数组值范围：1-n的数组里查找出重复的值
 
 


//剑指offer  
// ：把数组一分为二，整体数组中 ：1-n/2的数字数量如果大于n/2，那么重复的数字就在前一半，反之在后一半 ，重复一分为二

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







//剑指offer上的题目很局限   前提是有序  1-n  随即返回一个重复的  应该发展左程云的方法
//一次删掉k个不同的数，到最后看谁是删不掉的
//----------------------------------------------------现在不成功 
int * find(int a[],int n,int k)  //空间复杂度：2k    时间复杂度：小于kn
{
	int *a2 = new int[k];//存值
	int *a3 = new int[k] ;//存血量
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
					s=1; // 血量+1
				}
			}
			if(s==0)
			{
			 for(int y = 0; y<n; y++)
			 {
				 a3[y]--;// 血量-1
				 if(a3[y] == 0)
				 {
					 a2[y] = -1;
					 j--;
				 }
			 }
			}
		continue;
		}

		if(j<k) //还没把k装满
		{
			s=0;
			for(int x = 0; x<k; x++)
			{
				if(a[i]==a2[x])
				{
					a3[x]++; // 血量+1
					s=1;
				}
			}
			
			if(s==0)
			{
				for(int y = 0; y<k; y++)
				{
					if(a3[y]==0)
					{
						a3[y]=1;// 血量+1
						a2[y]=a[i]; //赋给数值	
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
	int *retu = new int[num] ;//开辟num大小的空间
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

