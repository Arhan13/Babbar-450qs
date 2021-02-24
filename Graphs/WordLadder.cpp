class Solution {
public:
    
    //Add the words with one char diff into the adj list of the node and then apply bfs on the node and get the SSP 
    //to the required node(endWord)
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //List
        unordered_set<string> us(wordList.begin(), wordList.end());
        //Queue
        queue<string> todoList;
        todoList.push(beginWord);
        int ladder = 1;
        while (!todoList.empty()) {
            int n = todoList.size();
            for (int i = 0; i < n; i++) {
                string word = todoList.front();
                todoList.pop();
                if (word == endWord) {
                    return ladder;
                }
                us.erase(word);
                for (int j = 0; j < word.size(); j++) {
                    char c = word[j];
                    for (int m = 0; m < 26; m++) {
                        word[j] = 'a' + m;
                        if (us.find(word) != us.end()) {
                            todoList.push(word);
                        }
                    }
                    word[j] = c;
                }
            }
            ladder++;
        }
        return 0;
    }

};