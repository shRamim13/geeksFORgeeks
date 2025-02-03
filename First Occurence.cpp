class Solution
{
public:
    int firstOccurence(string &txt, string &pat)
    {
        for (int i = 0; i < txt.size(); i++)
        {
            int j = 0;
            for (; j < pat.size(); j++)
            {
                if (txt[j + i] != pat[j])
                {
                    break;
                }
            }
            if (j == pat.size())
            {
                return i;
            }
        }
        return -1;
    }
};

/*
class Solution {
  public:
    int firstOccurence(string &txt, string &pat) {
        size_t pos=txt.find(pat);
        return (pos!=string::npos)?pos:-1;
    }
};
*/