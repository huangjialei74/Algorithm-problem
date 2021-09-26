#include<iostream>
using namespace std;
#include<string> 
#include<vector>  
/*
For example,
path="/home/" =>"/home"
path="/a/./b/../../c/"  =>"/c"

path="/../"  return"/".
such as"/home//foo/". you should ignore redundant slashes and return"/home/foo"
*/

// O(n) O(n)
class Solution
{
public:
	string simplifyPath(const string  path)
	{
		vector<string>dirs;
		// for(auto i=path.begin(); i!=path.end(); )
		for(int i=0; i<path.length(); i++)
		 {
			 ++i;
		//	 int j=find(i, path.end(), '/');			   
			 int j;
			 for(j=i+1; j<path.size(); j++)
				 if(path[j]=='/') break;
			 string dir=path.substr(i,j-i+1); 
			 if(!dir.empty() && dir!=".")
			 {
				  if(dir=="..")
				  {
					  if(!dirs.empty())
						  dirs.pop_back();
				  }
				  else
					  dirs.push_back(dir);
			 }
			 i=j;
		 }
		 string  out;
		 if(dirs.empty())
		 {
			 out = "/";
		 }
		 else
		 {
		//	 for(auto dir:dirs)
			 for(int dir=0; dir<dirs.size(); dir++)
			 {
				 out +='/';
				 out +=dirs[dir];
			 }
		 }
		 return out;
	}
};







int main()
{
	 Solution s;
	 cout<<s.simplifyPath("/a/./b/../../c/")<<endl;

	return 0;
}

