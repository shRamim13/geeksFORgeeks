class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals,
                               vector<int> &newInterval)
    {
        vector<vector<int>> v;
        int i = 0;
        int n = intervals.size();
        while (i < n && intervals[i][1] < newInterval[0])
        {
            v.push_back(intervals[i]);
            i++;
        }
        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        v.push_back({newInterval[0], newInterval[1]});
        while (i < n)
        {
            v.push_back(intervals[i]);
            i++;
        }
        return v;
    }
};