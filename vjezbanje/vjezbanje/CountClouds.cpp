#include "pch.h"

//https://app.codesignal.com/challenge/u6ob2kqxxQpCRsHaP


int countClouds(std::vector<std::vector<char>> skyMap)
{
    if (skyMap.size() == 0)
        return 0;

    std::vector <std::vector <bool>> visited(skyMap.size(), std::vector <bool>(skyMap[0].size(), false));
    std::queue <std::pair <int, int>> queue;
    int result = 0;


    for (int i = 0; i < skyMap.size(); i++)
    {
        for (int j = 0; j < skyMap[0].size(); j++)
        {
            if (skyMap[i][j] == '1' and visited[i][j] == false)
            {
                queue.push(std::make_pair(i, j));
                visited[i][j] = true;
                result++;
                std::pair <int, int> curr;

                while (queue.empty() == false)
                {
                    curr = queue.front();
                    queue.pop();


                    if (curr.first > 0 and
                        skyMap[curr.first - 1][curr.second] == '1' and
                        visited[curr.first - 1][curr.second] == false)
                    {
                        queue.push(std::make_pair(curr.first - 1, curr.second));
                        visited[curr.first - 1][curr.second] = true;
                    }

                    if (curr.first < skyMap.size() - 1 and
                        skyMap[curr.first + 1][curr.second] == '1' and
                        visited[curr.first + 1][curr.second] == false)
                    {
                        queue.push(std::make_pair(curr.first + 1, curr.second));
                        visited[curr.first + 1][curr.second] = true;
                    }

                    if (curr.second < skyMap[0].size() - 1 and
                        skyMap[curr.first][curr.second + 1] == '1' and
                        visited[curr.first][curr.second + 1] == false)
                    {
                        queue.push(std::make_pair(curr.first, curr.second + 1));
                        visited[curr.first][curr.second + 1] = true;
                    }

                    if (curr.second > 0 and
                        skyMap[curr.first][curr.second - 1] == '1' and
                        visited[curr.first][curr.second - 1] == false)
                    {
                        queue.push(std::make_pair(curr.first, curr.second - 1));
                        visited[curr.first][curr.second - 1] = true;
                    }
                }
            }
        }
    }

    return result;
}


//int main()
//{
//    std::vector <std::vector <char>> skyMap = { {'0', '1', '1', '0', '1'},
//        {'0', '1', '1', '1', '1' },
//        {'0', '0', '0', '0', '1' },
//        {'1', '0', '0', '1', '1'} };
//
//    std::cout << countClouds(skyMap);
//}