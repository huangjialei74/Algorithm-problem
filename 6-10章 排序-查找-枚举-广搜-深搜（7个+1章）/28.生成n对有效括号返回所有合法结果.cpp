#include<iostream>
using namespace std;
#include<vector>
#include<string>


//O(TODO)  O(n)
/**/
class Solution
{
	 public:
		 vector<string>generateParenthesis(int n)
		 {
			 vector<string>result;
			 string path;
			 if(n>0)
				 generate(n, path, result, 0, 0);
			 return result;
		 }
		  void generate(int n, string &path, vector<string>&result, int l, int r)
		  {
			  if(l==n)//'('�Ѿ��ﵽ������
			  {
				  string s(path);
				  result.push_back( s.append(n-r, ')') );//���n-r��')' ���� 
				  return;
			  } 	 
			  
			  path +='(';// path.append('(');  ���'('		  
			  generate(n, path, result, l+1, r);//�ݹ��ȥ		   //cout<<"������"<<path[path.size()-1]<<endl; 
			  path = path.substr(0, path.length()-1);// path.pop_back(); ����һ��'('  

			  if(l>r)//��ȱ')'
			  {			   
				  path +=')';//path.append(')');  ���')'
				  generate(n, path, result, l, r+1);
		    	  path = path.substr(0, path.length()-1);//path.pop_back();  ����
			  }
		  }

};

 
 class Solution2
 {
 public:
	 vector<string> generateParenthesis(int n)
	 {
		 if(n==0)
			 return vector<string>(1," ");
		 if(n==1)
			 return vector<string>(1,"()");
		 vector<string>result;

		 for(int i=0; i<n; ++i)
		//	 for(auto inner: generateParenthesis(i))
			 for(vector<string>::iterator inner=generateParenthesis(i).begin();  inner!=generateParenthesis(i).end();  inner++)
			//	 for(auto outer: generateParenthesis(n-1-i))
				 for(vector<string>::iterator outer=generateParenthesis(i).begin();  outer!=generateParenthesis(i).end();  outer++)
					 result.push_back( "(" + (*inner) + ")" + (*outer) );
				 return result;
	 }
 };
 

int main()
{
	 Solution s; 
     vector<string> V = s.generateParenthesis(3);
 
	 
	 	for(vector<string>::iterator it = V.begin();  it !=V.end();   it++)	 
				cout<<(*it)<<endl; 				 	 
		 
 
 

	return 0;
}

