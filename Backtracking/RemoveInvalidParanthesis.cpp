class Solution
{
public:
    vector<string> ans;
    unordered_set<string> uset;
    int invalid_count(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                st.push('(');
            }
            else if (s[i] == ')')
            {
                if (st.size() == 0)
                {
                    st.push(')');
                }
                else if (st.top() == ')')
                {
                    st.push(')');
                }
                else if (st.top() == '(')
                {
                    st.pop();
                }
            }
        }
        return st.size();
    }

    void helper_bktr(int invalid, string s)
    {
        if (invalid < 0)
        {
            return;
        }
        if (invalid == 0)
        {
            //This is going to be one of the answers
            if (invalid_count(s) == 0)
            {
                ans.push_back(s);
            }
            return;
        }
        //Else just set the situation
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '(' && s[i] != ')')
            {
                continue;
            }
            string left_substr = s.substr(0, i);
            string right_substr = s.substr(i + 1);
            string result = left_substr + right_substr;
            if (uset.find(result) == uset.end())
            {
                uset.insert(result);
                //We only need to check this type of string once
                helper_bktr(invalid - 1, result);
            }
        }
    }
    vector<string> removeInvalidParentheses(string s)
    {
        int invalid_brackets = invalid_count(s);
        helper_bktr(invalid_brackets, s);
        return ans;
    }
};