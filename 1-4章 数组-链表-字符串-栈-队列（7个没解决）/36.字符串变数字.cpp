#include<iostream>
using namespace std;
#include<string>
 #include <limits>  

 int myAtoi(const string& str)
	   {
		   int num=0;
		   int sign=1;
		   const int n=str.length();
		   int i=0;
		   while(str[i]==' '&& i< n)//跳过空格？
			   i++; 
		   if(str[i]=='+')//跳过正负号
		   {
			   i++;
		   }
		   else if(str[i]=='-')
		   {
			   sign =-1;
			   i++;
		   }
		   for(; i<n; i++)
		   {
			   if(str[i]<'0'||str[i]>'9')
				   break;
			   if(num > INT_MAX/10 || (num == INT_MAX/10 && (str[i]-'0')>INT_MAX%10))//马上要溢出
			   {
				   return sign==-1 ? INT_MIN: INT_MAX;
			   }
			   num = num*10+str[i]-'0';
		   }
		   return num*sign;
	   }
 
double myAtoi2(const string& str)
{
	int sign=1;
	int i=0;
	while(i<str.length())
	{
		if(str[i]==' ')
			i++;
		else
			break;
	}
	if(str[i]=='+') i++;
	if(str[i]=='-')
	{
		sign=-1;
		i++;
	}
	double num=0.0; 
	int INT_RANGE=INT_MAX, carry =10;//carry是获取小数部分应该除以的数， 
	for(i;i<str.length();i++)
	{
		 //if(num>INT_MAX/10 || (num==DBL_MAX)/10 && str[i]-'0'>DBL_MAX%10))
		// 	 return sign==-1 ? DBL_MIN: DBL_MAX;  不知道为什么在这里编译不行
		if(str[i]-'9'>0 || str[i]-'0'<0) 
		{
			if(str[i]=='.')
			{
		 		INT_RANGE=i;
				continue;
			}
	     	else
			    break;
		}
		if(i>INT_RANGE) {
	 		num=num+(str[i]-'0')*1.0/carry;
			carry *= 10;
		}
	 	else
		    num=num*10+ (str[i]-'0');
	}
	return sign*num;
}
 


int main()
{ 
	cout<<myAtoi2("-214.748")<<endl;;
	 

	return 0;
}

