#include<iostream>
using namespace std;



/*
求一个问题的最优解（通常是最大值或最小值），而且该问题能够分解成若干个子问题，子问题还有重叠的更小的子问题，就可以考虑用动态规划来解决这个问题
小问题的最优解组合起来 就能够得到整个问题的最优解
*/


/*
将绳子剪成任意数量（>1）的长度大于1的小段  返回最大乘积
*/
int maxProductAfterCutting(int length)
{
	if(length<2)  return 0;//任意数量（>1）
	if(length==2) return 1;
	if(length==3) return 2;

	int *products = new int[length+1];
	products[0] = 0;  products[1] = 1;  products[2] = 2;  products[3] = 3;

	int max = 0;
	for(int i = 4; i<=length; ++i)
	{
		max = 0;
		for(int j=2; j<=i/2; ++j)//不必要剪一个长度为1的下来    j<=i/2最多剪到i/2那里
		{ 
			int product = products[j] * products[i-j];
			if(max<product){		 
				max = product;
			}
			products[i] = max;//products[4]， 5 ，6 ，7 ...
		}
	}
	max = products[length];//从下往上 products[length]表示传入的长度为length时的最大值
	delete []products;
	return max;

}

 
#include<math.h>

/*
贪婪算法 长度>5时，尽可能地多剪长度为3的绳子
*/
int maxProductAfterCutting2(int length)
{
	if(length<2)    return 0;
	if(length==2)  	return 1;
	if(length==3)  	return 2;

	int timesOf3 = length/3;//剩余1就不剪最后一个  剩余2最后一个剪掉  
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

