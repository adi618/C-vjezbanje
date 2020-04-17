#include "pch.h"


std::string reverseVowelsOfString(std::string s)
{
    int j = s.size() - 1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a' || s[i] == 'u' || s[i] == 'o' || s[i] == 'i' || s[i] == 'e' ||
            s[i] == 'A' || s[i] == 'U' || s[i] == 'O' || s[i] == 'I' || s[i] == 'E')
        {
            char temp = s[i];
            for (j; j > i; j--)
            {
                if (s[j] == 'a' || s[j] == 'u' || s[j] == 'o' || s[j] == 'i' || s[j] == 'e' ||
                    s[j] == 'A' || s[j] == 'U' || s[j] == 'O' || s[j] == 'I' || s[j] == 'E')
                {
                    s[i] = s[j];
                    s[j] = temp;
                    j--;
                    break;
                }
            }
        }
    }

    return s;
}

void reverseVowelsOfString()
{
    std::string s = "codesignal";

    std::cout << reverseVowelsOfString(s);

}