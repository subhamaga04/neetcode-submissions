class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q; 
        unordered_map<string, int> mp; 

        for(auto &word : wordList){
            mp[word]++; 
        }

        if(mp.find(endWord) == mp.end()){
            return 0; 
        }

        q.push({beginWord, 1}); 

        while(!q.empty()){
            string curr_word = q.front().first; 
            int curr_level = q.front().second; 
            q.pop(); 
            for(int i = 0; i < curr_word.size(); i++){
                char original = curr_word[i]; 

                for(char c = 'a'; c <= 'z' ; c++){
                    curr_word[i] = c; 

                    if(mp.find(curr_word) != mp.end()){
                        if(curr_word == endWord) return curr_level+1; 

                        q.push({curr_word, curr_level+1}); 
                        mp.erase(curr_word); 
                    }
                }
                curr_word[i] = original; 
            }
            
        }

        return 0; 
    }
};
