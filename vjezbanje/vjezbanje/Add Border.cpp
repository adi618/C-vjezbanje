#include "pch.h"



std::vector<std::string> addBorder(std::vector<std::string>& picture)
{
	std::string asterisk;

	for (int i = 0; i < picture[0].size(); i++)
	{
		asterisk += "*";
	}

	picture.insert(picture.begin(), asterisk);
	picture.insert(picture.end(), asterisk);

	for (int i = 0; i < picture.size(); i++)
	{
		picture[i] = "*" + picture[i] + "*";
	}

	return picture;
}

void addBorder()
{
	std::vector <std::string> picture = { "abc","ded" };

	addBorder(picture);
}