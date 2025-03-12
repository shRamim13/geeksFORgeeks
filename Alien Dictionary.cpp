class Solution
{
public:
    vector<int> topoSort(int V, vector<int> adj[], vector<bool> &present)
    {
        int indegree[26] = {0};
        queue<int> q;
        vector<int> topo;

        // Calculate in-degree
        for (int i = 0; i < 26; i++)
        {
            for (int v : adj[i])
                indegree[v]++;
        }

        // Push nodes with zero in-degree
        for (int i = 0; i < 26; i++)
        {
            if (present[i] && indegree[i] == 0)
                q.push(i);
        }

        // Kahn’s Algorithm for Topological Sorting
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (int v : adj[node])
            {
                if (--indegree[v] == 0)
                    q.push(v);
            }
        }

        // If all present characters are not sorted, cycle exists
        return (topo.size() == count(present.begin(), present.end(), true)) ? topo : vector<int>();
    }

    string findOrder(vector<string> &words)
    {
        vector<int> adj[26];
        vector<bool> present(26, false);
        int N = words.size();

        // Mark present characters
        for (auto &word : words)
        {
            for (char c : word)
                present[c - 'a'] = true;
        }

        // Build adjacency list
        for (int i = 0; i < N - 1; i++)
        {
            string &s1 = words[i], &s2 = words[i + 1];
            int len = min(s1.size(), s2.size());
            bool found = false;

            for (int j = 0; j < len; j++)
            {
                if (s1[j] != s2[j])
                {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    found = true;
                    break;
                }
            }

            // Invalid case: s2 is a prefix of s1 (e.g., "abcd" and "ab")
            if (!found && s1.size() > s2.size())
                return "";
        }

        vector<int> topo = topoSort(26, adj, present);
        if (topo.empty())
            return ""; // Return empty string for invalid cases

        string ans = "";
        for (int x : topo)
            ans += (x + 'a');
        return ans;
    }
};
