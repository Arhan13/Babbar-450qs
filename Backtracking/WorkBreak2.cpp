#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool inDictionary(string word, vector<string> &dict)
    {
        if (find(dict.begin(), dict.end(), word) == dict.end())
        {
            return false;
        }
        //cout << "i am here at dict ver" << endl;
        return true;
    }
    void wordBreakUtil(int n, vector<string> dict, string s, string result, vector<string> &ans)
    {
        //cout << "i am inside wordBreakUtil" << endl;
        int i = 1;
        while (i <= n)
        {
            ///cout<<"Inside loop"<<endl;
            // Extract substring from 0 to i in prefix
            string prefix = s.substr(0, i);
            cout << prefix << endl;
            //cout<<s.substr(0,i)<<endl;
            //cout<<"I am here"<<endl;
            // If dictionary conatins this prefix, then
            // we check for remaining string. Otherwise
            // we ignore this prefix (there is no else for
            // this if) and try next
            if (inDictionary(prefix, dict))
            {
                // If no more elements are there, print it
                if (i == n)
                {
                    // Add this element to previous prefix
                    result += prefix;
                    cout << result << endl;
                    //cout << result << endl;
                    ans.push_back(result);
                    return;
                }
                wordBreakUtil(n - i, dict, s.substr(i, n - i),
                              result + prefix + " ", ans);
            }
            i++;
        }
        //cout<<"Something??"<<endl;
    }
    vector<string> wordBreak(int n, vector<string> &dict, string s)
    {
        // code here
        vector<string> ans;
        //cout<<n<<endl;
        //Blank string is the current string
        //cout << "i am here at workbreak" << endl;
        wordBreakUtil(s.size(), dict, s, "", ans);
        return ans;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        //cout<<n<<endl;
        vector<string> dict;
        string s;
        //cin >> s;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            dict.push_back(s);
        }
        cin >> s;
        //cout<<s<<endl;
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if (ans.size() == 0)
        {
            cout << "Empty\n";
        }
        else
        {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "(" << ans[i] << ")";
            }
            cout << endl;
        }
    }
    return 0;
}