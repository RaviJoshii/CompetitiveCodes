// https://leetcode.com/problems/trapping-rain-water-ii/
// Trapping Rain Water II
#include <bits/stdc++.h>
using namespace std;
class items
{
public:
    int val;
    int row;
    int col;
    items(int val, int row, int col)
    {
        this->val = val;
        this->row = row;
        this->col = col;
    }
    items()
    {
    }
    bool operator>(const items &i1) const
    {
        return this->val > i1.val;
    }
};

class Solution
{
public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {

        priority_queue<items, vector<items>, greater<items>> pq;
        int n = heightMap.size();
        int m = heightMap[0].size();
        
        vector<vector<bool>> matrix(n, vector<bool>(m, false));
        int row1 = 0;
        int rown = n - 1;
        int col1 = 0;
        int coln = m - 1;
        
        for (int i = 0; i < n; i++)
        {
            pq.push(items(heightMap[i][col1], i, col1));
            pq.push(items(heightMap[i][coln], i, coln));
            matrix[i][col1] = true;
            matrix[i][coln] = true;
        }
        for (int i = 1; i < m - 1; i++)
        {
            pq.push(items(heightMap[row1][i], row1, i));
            pq.push(items(heightMap[rown][i], rown, i));
            matrix[row1][i] = true;
            matrix[rown][i] = true;
        }

        int res = 0;

        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!pq.empty())
        {
            // cout << pq.size() << endl;
            int Crow = pq.top().row;
            int Ccol = pq.top().col;
            int ht=pq.top().val;
            pq.pop();
            for (vector<int> temp: dir)
            {
                int Nrow = Crow + temp[0];
                int Ncol = Ccol + temp[1];

                if (Nrow >= 0 && Nrow < n && Ncol >= 0 && Ncol < m && (!matrix[Nrow][Ncol]))
                {

                    matrix[Nrow][Ncol] = true;
                    res +=max(0, ht - heightMap[Nrow][Ncol]);
                    pq.push(items(max(heightMap[Nrow][Ncol], ht), Nrow, Ncol));
                
                }
            }
        }

        return res;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> heightMap = {
        {1, 4, 3, 1, 3, 2},
        {3, 2, 1, 3, 2, 4},
        {2, 3, 3, 2, 3, 1}};
    cout << s.trapRainWater(heightMap) << endl;
    return 0;
}