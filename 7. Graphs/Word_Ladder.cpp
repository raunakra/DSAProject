#include <bits/stdc++.h>
using namespace std;

// Word Ladder (Shortest Transformation Sequence Length)
// Given beginWord, endWord, and a wordList, find the length of the shortest
// transformation sequence such that only one letter changes per step and each
// intermediate word is in the list.
// Complexity (pattern-based BFS approach):
//   Let N = number of words, L = word length.
//   Building pattern map: O(N * L).
//   BFS traversal: Each word expanded once; generating neighbors via patterns: O(L + k)
//   Overall Time: O(N * L + (edges)) ~ O(N * L) average (since total pattern matches bounded by N * L).
//   Space: O(N * L) for pattern dictionary + O(N) for visited and queue.
// Notes: We precompute generic patterns like h*t for hot to reduce neighbor generation cost.

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (!dict.count(endWord)) return 0;
    // Precompute pattern => list of words
    unordered_map<string, vector<string>> bucket;
    int L = beginWord.size();
    for (const string &w : dict) {
        for (int i = 0; i < L; ++i) {
            string pat = w;
            pat[i] = '*';
            bucket[pat].push_back(w);
        }
    }

    queue<pair<string,int>> q; // word, distance
    q.push({beginWord, 1});
    unordered_set<string> visited;
    visited.insert(beginWord);

    while (!q.empty()) {
        auto [word, dist] = q.front(); q.pop();
        if (word == endWord) return dist;
        for (int i = 0; i < L; ++i) {
            string pat = word;
            pat[i] = '*';
            auto it = bucket.find(pat);
            if (it == bucket.end()) continue;
            for (const string &next : it->second) {
                if (!visited.count(next)) {
                    visited.insert(next);
                    q.push({next, dist + 1});
                }
            }
        }
    }
    return 0; // no sequence
}

// Alternative simpler BFS without pattern precomputation
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    queue<string> q;
    q.push(beginWord);
    int ladder = 1;

    while(!q.empty())
    {
        int n = q.size();

        for(int i = 0; i< n;i++)
        {
            auto word = q.front(); q.pop();

            if(word == endWord) return ladder;

            dict.erase(word);

            for(int j = 0; j < word.size(); j++)
            {
                char c  = word[j];
                for(int k = 0 ; k <26 ; k++)
                {
                    word[j] = 'a' + k;
                    if(dict.find(word) != dict.end())
                    {
                        q.push(word);
                    }
                }
                word[j] = c;
            }
        }
        ladder++;
    }

    return 0;
}


int main() {
    vector<string> words1 = {"hot","dot","dog","lot","log","cog"};
    cout << "Example 1 length: " << ladderLength("hit","cog", words1) << '\n'; // expected 5 (hit->hot->dot->dog->cog)

    vector<string> words2 = {"a","b","c"};
    cout << "Example 2 length: " << ladderLength("a","c", words2) << '\n'; // expected 2

    vector<string> words3 = {"hot","dot","dog","lot","log"}; // no cog
    cout << "Example 3 length: " << ladderLength("hit","cog", words3) << '\n'; // expected 0

    return 0;
}
