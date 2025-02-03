class Solution
{
public:
    int myAtoi(char *s)
    {
        int i = 0;
        int n = strlen(s);
        while (s[i] == ' ')
        {
            i++;
        }
        int sign = 1;
        if (s[i] == '-' || s[i] == '+')
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        long long number = 0;
        while (s[i] >= '0' && '9' >= s[i])
        {
            number = number * 10 + (s[i] - '0');
            if (number * sign >= INT_MAX)
                return INT_MAX;
            if (number * sign <= INT_MIN)
                return INT_MIN;
            i++;
        }
        number *= sign;
        return number;
    }
};