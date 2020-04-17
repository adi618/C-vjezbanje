#include "pch.h"


std::string longestWord(std::string text)
{
    std::string temp = "";
    std::vector<std::string> res;

    for (int i = 0; i < text.size(); i++)
    {
        if ((text[i] > 64 && text[i] < 91) || (text[i] > 96 && text[i] < 123))
            temp += text[i];
        else
        {
            if (temp != "")
            {
                res.push_back(temp);
                temp = "";
            }
        }
    }
    if (temp != "")
    {
        res.push_back(temp);
        temp = "";
    }
    int max = 0;
    for (int i = 0; i < res.size(); i++)
    {
        if (res[i].size() > temp.size())
        {
            temp = res[i];
            max = i;
        }
    }

    return res[max];
}


void longestWord()
{
    std::string s = "Ready, steady, go!";
    std::cout << longestWord(s);
}