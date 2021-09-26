#include<iostream>
using namespace std;





/*
 long Fibonacci(unsigned n)
{
	if(n <= 0)
		return 0;
	if(n == 1)
		return 1;
	return Fibonacci(n-1) + Fibonacci(n-2);
}
*/

 long Fibonacci(unsigned n)
{
	int result[2] = {0,1};
	if(n<2)
	{
		return result[n];
	}
	 long FibonacciOne = 0;
	 long FibonacciTwo = 1;
	  long FibN = 0;

	for(unsigned int i = 2; i<=n; i++)
	{//cout<<FibonacciOne<< FibonacciTwo<<endl;
		FibN = FibonacciOne+ FibonacciTwo;
		 FibonacciOne = FibonacciTwo;
		 FibonacciTwo = FibN;// 0¡¢1¡¢1¡¢2¡¢3¡¢5¡¢8¡¢13¡¢21¡¢34
	}
	return FibN;
}






//ÇàÍÜÌ¨½×
 long number(unsigned n)
 {
	 int result[2] = {1,2};
	 if(n<2) return result[n];

	 long a= 1, b = 2, c=0 ;

	 for(int i = 2; i<=n; i++)
	 {
		 c = a+b;
		 a = b;
		 b = c;
	 }
	 return c;
 }



int main()
{
//	 cout<< Fibonacci(8)<<endl;
	cout<<number(3)<<endl;;

	return 0;
}

