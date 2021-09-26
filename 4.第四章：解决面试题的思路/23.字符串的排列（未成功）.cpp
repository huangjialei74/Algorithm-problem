#include<iostream>
using namespace std;
#include<vector>
#include<string>



void Permutation(char *pStr, char *pBegin )
{
	if(*pBegin=='\0'){
		//result.push_back(pStr);
	 	 cout<<pStr<<endl;//cout<<123<<endl;		 
	}
	else
	{
		for(char* pCh=pBegin; *pCh!='\0'; ++pCh)
		{ 
			char temp =*pCh;
			*pCh=*pBegin;
			*pBegin=temp;

			Permutation(pStr, pBegin+1 );

			temp=*pCh;
			*pCh=*pBegin;
			*pBegin=temp;
		}
	}
}

vector<char*> Permutation(char *pStr)
{ 
	vector<char*>result;
//	if(pStr==NULL) return result;
	Permutation(pStr, pStr ); 
	return result;
}





 
int main()
{ 
	char *p="123"; 

	vector<char*>result=Permutation(p);
	for(vector<char*>::iterator it=result.begin(); it!=result.end(); it++)
		cout<<(*it)<<endl;
	 

	return 0;
}

