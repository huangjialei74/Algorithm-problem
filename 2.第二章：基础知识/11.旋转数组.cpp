#include<iostream>
using namespace std;



int MIN(int *numbers,int length)
{
	if(numbers == NULL || length <=0)
		throw new exception("Invalid paramenters");
	int index1 = 0;
	int index2 = length-1;
	int indexMid = index1;
	while(numbers[index1] >= numbers[index2])
	{
		if(index2 - index1 == 1)
		{
			indexMid = index2;
			break;
		}
		indexMid = (index1 + index2)/2;
		if(numbers[indexMid] >= numbers[index1])
		{
			index1 = indexMid;
		}
		else if(numbers[indexMid] <= numbers[index2])
			{
				index2 = indexMid;
			}
	}
	return numbers[indexMid];
}

 


int MinInOrder(int *numbers, int index1, int index2)
{
	int result = numbers[index1];
	for(int i = index1+1; i<=index2; i++)
	{
		if(result>numbers[i])
		{
			result = numbers[i];
		}
		retunrn result;
	}
}
 
int MIN2(int *numbers,int length)
{
	if(numbers == NULL || length <=0)
		throw new exception("Invalid paramenters");
	int index1 = 0;
	int index2 = length-1;
	int indexMid = index1;

	while(numbers[index1] >= numbers[index2])
	{
		if(index2 - index1 == 1)
		{
			indexMid = index2;
			break;
		}
		indexMid = (index1 + index2)/2;
		//如果三者相等  只能顺序查找
		if(numbers[indexMid] == numbers[index1] && numbers[indexMid] == numbers[index2])
		{
			return MinInOrder(numbers, index1, index2);

		}


		if(numbers[indexMid] >= numbers[index1])
		{
			index1 = indexMid;
		}
		else if(numbers[indexMid] <= numbers[index2])
			{
				index2 = indexMid;
			}
	}
	return numbers[indexMid];
}

 



int main()
{
	 

	return 0;
}

