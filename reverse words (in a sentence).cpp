class Solution
{
public:
    string reverseWords(string &s)
    {

        stringstream ss(s);
        string str, ans = "";
        while (ss >> str)
        {
            ans = str + " " + ans;
        }
        ans = ans.substr(0, ans.size() - 1);
        return ans;
    }
};

////

class Solution
{
public:
    // Function to reverse words in a given string.
    string reverseWords(string &s)
    {
        string ans = "";
        string tmp = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                tmp += s[i];
            }
            else if (s[i] == ' ')
            {
                if (tmp != "")
                {
                    if (ans == "")
                    {
                        ans = tmp;
                    }
                    else
                    {
                        ans = tmp + " " + ans;
                    }
                    tmp = "";
                }
            }
        }
        if (tmp != "")
        {
            if (ans == "")
            {
                ans = tmp;
            }
            else
            {
                ans = tmp + " " + ans;
            }
        }

        return ans;
    }
};

/*
class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string &s) {

        stringstream ss(s);
        string str, ans="";
        while(ss>>str){
            if(ans==""){
                ans=str;
            }else{
            ans=str+" "+ans;
            }
        }
        //ans=ans.substr(0,ans.size()-1);
        return ans;
    }
};
*/