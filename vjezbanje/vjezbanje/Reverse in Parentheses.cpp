#include "pch.h"



std::string reverseInParentheses(std::string& inputString)
{
	std::stack <int> s;

	for (int i = 0; i < inputString.size(); i++)
	{
		if (inputString[i] == '(')
		{
			s.push(i);
		}
		else if (inputString[i] == ')')
		{
			reverse(inputString.begin() + s.top() + 1, inputString.begin() + (i));
			s.pop();
		}
	}

	for (int i = 0; i < inputString.size(); i++)
	{
		if (inputString[i] == '(' || inputString[i] == ')')
		{
			inputString.erase(inputString.begin() + i);
			i--;
		}
	}

	return inputString;
}

void reverseInParentheses()
{
	std::string s = "foo(bar(baz))blim";

	std::cout << reverseInParentheses(s);
}