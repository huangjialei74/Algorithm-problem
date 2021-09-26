#include<iostream>
using namespace std;


/*
"0" => true
"0.1" => true
"abc" => false
"1a" => false
"2e10" => true
*/


// O(n) O(n)
class Solution
{
public:
	bool isNumber(const string&s)
	{
		enumInputType
		{
			INVALID,//0
				SPACE,//1
				SIGN,//2
				DIGIT,//3
				DOT,//4
				EXPONENT,//5
				NUM_INPUTS//6
		};
		const inttransitionTable[][NUM_INPUTS]={
			-1,0,3,1,2,-1,//nextstatesforstate0
				-1,8,-1,1,4,5,//nextstatesforstate1
				-1,-1,-1,4,-1,-1,//nextstatesforstate2
				-1,-1,-1,1,2,-1,//nextstatesforstate3
				-1,8,-1,4,-1,5,//nextstatesforstate4
				-1,-1,6,7,-1,-1,//nextstatesforstate5
				-1,-1,-1,7,-1,-1,//nextstatesforstate6
				-1,8,-1,7,-1,-1,//nextstatesforstate7
				-1,8,-1,-1,-1,-1,//nextstatesforstate8
		};
		int state=0;
		for(autoch:s)
		{
			InputTypeinputType=INVALID;
			if(isspace(ch))
				inputType=SPACE;
			else if(ch=='+'||ch=='-')
				inputType=SIGN;
			else if(isdigit(ch))
				inputType=DIGIT;
			else if(ch=='.')
				inputType=DOT;
			else if(ch=='e'||ch=='E')
				inputType=EXPONENT;
			//Getnextstatefromcurrentstateandinputsymbol
			state=transitionTable[state][inputType];
			//Invalidinput
			if(state==-1)returnfalse;
		}
		//Ifthecurrentstatebelongstooneoftheaccepting(final)states,//thenthenumberisvalid
			return state==1||state==4||state==7||state==8;
	}
};



// π”√stood()  O(n)


class Solution2
{
public:
	bool isNumber(const string&s){
		return isNumber2(s.c_str());
	}
private:
	bool isNumber2(char const*s)
	{
		char*endptr;
		strtod(s,&endptr);
		if(endptr==s)
			return false;for(;*endptr;++endptr)
			if(!isspace(*endptr))
				return false;
			return true;
	}
};








int main()
{
	 

	return 0;
}

