class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {
        vector<char> sv;
        vector<char> tv;
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == '#' && (sv.size() != 0))
            {
                sv.pop_back();
            }
            else if (S[i] != '#')
            {
                sv.push_back(S[i]);
            }
        }
        for (int i = 0; i < T.size(); i++)
        {
            if (T[i] == '#' && (tv.size() != 0))
            {
                tv.pop_back();
            }
            else if (T[i] != '#')
            {
                tv.push_back(T[i]);
            }
        }
        if (sv == tv)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};