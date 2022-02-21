class Solution
{
private:
    vector<int> low;
    vector<int> disc;
    int time = 1;

public:
    void findBridge(vector<vector<int>> &graph, int idx, int parent, vector<vector<int>> &bridges)
    {
        if (disc[idx] != 0)
            return;

        disc[idx] = low[idx] = time++;
        // cout<<idx<<" inside"<<endl;

        for (auto const &next : graph[idx])
        {
            if (disc[next] == 0)
            {
                findBridge(graph, next, idx, bridges);
                low[idx] = min(low[idx], low[next]);
            }
            else if (parent != next)
                low[idx] = min(low[idx], disc[next]);

            if (low[next] > disc[idx])
            {
                // cout<<next<<" "<<idx<<" "<<low[next]<<" "<<low[idx]<<" "<<disc[next]<<" "<<disc[idx]<<endl;
                bridges.push_back({idx, next});
            }
        }

        // cout<<idx<<" exiting"<<endl;
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        low.resize(n, 0), disc.resize(n, 0);
        time = 1;

        vector<vector<int>> graph(n, vector<int>());

        for (auto const &edge : connections)
        {
            int to = edge[1], at = edge[0];

            graph[at].push_back(to), graph[to].push_back(at);
        }

        vector<vector<int>> bridges;

        findBridge(graph, 0, -1, bridges);

        return bridges;
    }
};