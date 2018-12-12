//https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include<iostream>
#include<string>

using namespace std;

int lengthOfLongestSubstring(string s)
{
	string temp1;
	string temp2;
	char symbol;

	int length = 0;
	int count = 0;

	temp1 = s[0];
	temp2 = temp1;

	if (s.length()>0)
	{		
		for (int i = 0; i+count < s.length()-1; ++i)
		{
			symbol = s[i+count + 1];

			if (temp1.find(symbol) == string::npos)
			{
				temp1 += symbol;				
			}
			else
			{
				count++;

				if (temp1.length() > temp2.length())
				{
					temp2 = temp1;
				}

				temp1.clear();
				temp1 = s[count];
				i = -1;
			}
		}
		if (temp1.length() > temp2.length())
		{
			length = temp1.length();
		}
		else
		{
			length = temp2.length();
		}
	}	
	return length;
}