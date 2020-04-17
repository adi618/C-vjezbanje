#include "pch.h"




//https://www.codewars.com/kata/5277c8a221e209d3f6000b56

bool isOpen(char brace)
{
	if (brace == '(' || brace == '{' || brace == '[')
		return true;
	
	return false;
}

bool doesClosedBracketMatch(char currentBrace, char poppedBrace, std::vector<char>& character)
{
	if (poppedBrace == '(' && currentBrace == ')')
	{
		character.pop_back();
		return true;
	}

	if (poppedBrace == '{' && currentBrace == '}')
	{
		character.pop_back();
		return true;
	}

	if (poppedBrace == '[' && currentBrace == ']')
	{
		character.pop_back();
		return true;
	}

	return false;
}

bool validBraces(std::string braces)
{
	std::vector <char> character = { 'a' };
	char top;

	for (int i = 0; i < braces.size(); i++)
	{
		top = character[character.size() - 1];

		if (isOpen(braces[i]))
		{
			character.push_back(braces[i]);
		}
		else if (!doesClosedBracketMatch(braces[i], top, character))
		{
			return false;
		}
	}

	return true;
}


void validBraces()
{
	std::string a;
	std::cin >> a;

	std::cout << validBraces(a);
}