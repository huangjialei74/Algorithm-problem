#include<iostream>
using namespace std;

 
class Solution
{
public:
	int Search(int array[],int length, int target) 
	{ 
		 int first = 0;
		 int last = length-1;//�˴�last��Ϊlength  ����͵øĳ�last-1
		 while(first != last)
		 {
			 int mid = (first+last)/2; //cout<<"midΪ"<<mid<<endl;
			 if(array[mid]==target)
				 return mid;
			 if(array[mid]> array[last])
			 { 
			 if(array[mid]>target && array[first] <=target) 
				 last = mid; 
			 else 
				 first = mid+1; 
			 }
			 else if(array[mid]<array[last]) 
			 {
				 if(array[mid]<target && array[last] >=target)
				 { // cout<<array[mid]<<array[last]<<3<<endl;					
					 first = mid+1;
				 }
				 else
				 { //cout<<array[mid]<<array[last]<<4<<endl;					
					 last = mid;
				 }
			 }
			 else  
			 {     //cout<<array[mid]<<array[last]<<5<<endl; 
				 last = mid;
			 }			 
		     // cout<<"�Բ�"<<first<<last<<endl;
		 }
		 return array[first] == target ?first : -1;
	}
};


 

int main()
{
	Solution s;
	int arr[] = {2,2,2,2,5,5,6,6,7,7,8,8,9,9,9,0,1,2};
	 for(int i = 0;i<18;i++) 
	if(arr[s.Search(arr,18,arr[i])] == arr[i]) cout<<"�ҵ���"<<endl;

	return 0;
}
