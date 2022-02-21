class Solution
{
private:
    vector<int> low, disc;
    int time;
    int dir[5] = {-1, 0, 1, 0, -1};
    int apCount;
    int R, C;

public:
    void countAp(vector<vector<int>> &grid, int curr_r, int curr_c, int prev_r = -1, int prev_c = -1)
    {
        int cellNo = R * curr_r + curr_c;
        if (disc[cellNo] != 0)
            return;

        disc[cellNo] = low[cellNo] = time++;
        int childCount = 0;

        for (int i = 0; i < 4; i++)
        {
            int next_r = curr_r + dir[i];
            int next_c = curr_c + dir[i + 1];

            if (next_r < 0 || next_r >= R || next_c < 0 || next_c >= C || grid[next_r][next_c] == 0)
                continue;
            int nextNo = next_r * R + next_c;

            if (disc[nextNo] == 0)
            {
                countAp(grid, next_r, next_c, curr_r, curr_c);
                childCount++;
                low[cellNo] = min(low[cellNo], low[nextNo]);
            }
            else if (next_r != prev_r && next_c != prev_c)
                low[cellNo] = min(low[cellNo], disc[cellNo]);

            if (low[nextNo] > disc[cellNo] || (prev_r == -1 && prev_c == -1 && childCount > 1))
            {
                apCount++;
                cout << nextNo << " " << cellNo << " " << childCount << endl;
            }
        }
    }

    int minDays(vector<vector<int>> &grid)
    {
        int isLands = 0;
        R = grid.size();
        C = grid[0].size();
        apCount = 0;
        time = 1;

        disc.resize(R * C + 1, 0), low.resize(R * C + 1, 0);

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (grid[i][j] == 0)
                    continue;

                if (disc[R * i + j])
                    continue;

                isLands++;
                countAp(grid, i, j);
            }
        }

        if (isLands > 1 || isLands == 0)
            return 0;

        if (apCount > 0)
            return 1;

        return 2;
    }
};