#include "pch.h"


int sumUpNumbers(std::string inputString)
{
    std::string temp = "";
    int sum = 0;

    for (int i = 0; i < inputString.size(); i++)
    {
        if (inputString[i] > 47 && inputString[i] < 59)
        {
            temp += inputString[i];
        }
        else if (temp != "")
        {
            sum += stoi(temp);
            temp = "";
        }
    }
    if (temp != "")
    {
        sum += stoi(temp);
    }
    return sum;
}
