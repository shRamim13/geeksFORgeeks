class MyDataStructure
{
public:
    // Initialize your data structure.
    vector<int> v;
    unordered_map<int, int> mp;
    MyDataStructure()
    {
        // Write your code here.
    }

    // Insert element 'X'. Returns true if the element was not present, and false otherwise.
    bool insert(int x)
    {
        if (mp.find(x) != mp.end())
        {
            return false;
        }
        v.push_back(x);
        mp[x] = v.size() - 1;
        return true;
    }

    // Removes element 'X', if present. Returns true if the element was present and false otherwise.
    bool remove(int x)
    {
        if (mp.find(x) == mp.end())
        {
            return false;
        }
        int val = v.back();
        int indx = mp[x];
        mp[val] = indx;
        v[indx] = val;
        mp.erase(x);
        v.pop_back();
        return true;
    }

    // Search element 'X'. Returns true if the element was present, and false otherwise.
    bool search(int x)
    {
        if (mp.find(x) != mp.end())
        {
            return true;
        }
        return false;
    }

    // Returns a random element present in the data structure.
    int getRandom()
    {
        return v[rand() % v.size()];
    }
};