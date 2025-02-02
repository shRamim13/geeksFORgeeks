class Solution
{
public:
    bool isRotated(string &s1, string &s2)
    {
        if (s1.size() != s2.size())
        {
            return false;
        }
        string s11 = s1;
        reverse(s11.begin(), s11.end());
        reverse(s11.begin(), s11.begin() + 2);
        reverse(s11.begin() + 2, s11.end());

        string s22 = s1;
        reverse(s22.begin(), s22.begin() + 2);
        reverse(s22.begin() + 2, s22.end());
        reverse(s22.begin(), s22.end());

        if (s11 == s2 || s22 == s2)
        {
            return true;
        }
        return false;
    }
};

/*
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        int n = str1.length();
        bool clockwise = true, anticlockwise = true;
        for (int i = 0; i < n; i++)
        {
            if (str1[i] != str2[(i + 2) % n])
            {
                clockwise = false; // not rotated clockwise
                break;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (str1[(i + 2) % n] != str2[i])
            {
                anticlockwise = false; // not rotated anticlockwise
                break;
            }
        }

        return clockwise or anticlockwise; // if any of both is true, return true
    }

};
*/