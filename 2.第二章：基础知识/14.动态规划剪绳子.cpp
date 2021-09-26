#include<iostream>
using namespace std;



/*
��һ����������Ž⣨ͨ�������ֵ����Сֵ�������Ҹ������ܹ��ֽ�����ɸ������⣬�����⻹���ص��ĸ�С�������⣬�Ϳ��Կ����ö�̬�滮������������
С��������Ž�������� ���ܹ��õ�������������Ž�
*/


/*
�����Ӽ�������������>1���ĳ��ȴ���1��С��  �������˻�
*/
int maxProductAfterCutting(int length)
{
	if(length<2)  return 0;//����������>1��
	if(length==2) return 1;
	if(length==3) return 2;

	int *products = new int[length+1];
	products[0] = 0;  products[1] = 1;  products[2] = 2;  products[3] = 3;

	int max = 0;
	for(int i = 4; i<=length; ++i)
	{
		max = 0;
		for(int j=2; j<=i/2; ++j)//����Ҫ��һ������Ϊ1������    j<=i/2������i/2����
		{ 
			int product = products[j] * products[i-j];
			if(max<product){		 
				max = product;
			}
			products[i] = max;//products[4]�� 5 ��6 ��7 ...
		}
	}
	max = products[length];//�������� products[length]��ʾ����ĳ���Ϊlengthʱ�����ֵ
	delete []products;
	return max;

}

 
#include<math.h>

/*
̰���㷨 ����>5ʱ�������ܵض������Ϊ3������
*/
int maxProductAfterCutting2(int length)
{
	if(length<2)    return 0;
	if(length==2)  	return 1;
	if(length==3)  	return 2;

	int timesOf3 = length/3;//ʣ��1�Ͳ������һ��  ʣ��2���һ������  
	if(length-timesOf3 *3 ==1)
		timesOf3 -= 1;
	int timesOf2 = (length -timesOf3 *3)/2;
	return (int)(pow(3,timesOf3))*(int)(pow(2,timesOf2));

}


















int main()
{
    cout<<maxProductAfterCutting(8)<<endl;
	  
	return 0;
}

