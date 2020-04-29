#include "pch.h"


bool areFollowingPatterns(std::vector<std::string> strings, std::vector<std::string> patterns) {

    std::map <std::string, std::string> patternsKey;
    std::map <std::string, std::string> stringsKey;

    for (int i = 0; i < patterns.size(); i++)
    {
        if (patternsKey[patterns[i]] == "")
            patternsKey[patterns[i]] = strings[i];
        else
            if (patternsKey[patterns[i]] != strings[i])
                return false;
    }
    for (int i = 0; i < patterns.size(); i++)
    {
        if (stringsKey[strings[i]] == "")
            stringsKey[strings[i]] = patterns[i];
        else
            if (stringsKey[strings[i]] != patterns[i])
                return false;
    }

    return true;
}


void followingPatterns()
{
    std::vector<std::string> strings = { "cat",
 "dog",
 "dog" };
    std::vector<std::string> patterns = { "a",
 "b",
 "c" };
    std::cout << areFollowingPatterns(strings, patterns);
}