#include<iostream>
using namespace std;

#include<string>
//anagrams回文构词： 打乱顺序后能形成新的单词

//特点：将几个单词按字母顺序排序后 若他们相等 则属于同一组anagrams



class Solution
{
public:
	vector<string>anagrams(vector<string>&strs)
	{
		unordered_map< string, vector<string> >group;
		for(const auto&s:strs)//把字符串数组strs里面的字符串  存入哈希表中， key是排序后的字符串  键值是其不同顺序对应的单词（多个）
		{
			string key=s;
			sort(key.begin(), key.end());//给每个单词排序  ，单词s不变 
			group[key].push_back(s);
		}
		vector<string>result;
		for(auto it=group.cbegin(); it!=group.cend(); it++)
		{
			if(it->second.size()>1)//一个排序后的字符串 其不同顺序能表示的单词数量大于1的
				result.insert(result.end(), it->second.begin(), it->second.end());
		}
		return result;
	}
};




int main()
{
	 

	return 0;
}

