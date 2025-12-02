#include <bits/stdc++.h>
using namespace std;

// Amazon & Salesforce Frequently Asked Graph Questions

// 1. Number of Islands (Amazon, Salesforce - Very Frequent)
// Count number of islands in 2D grid ('1' = land, '0' = water)
// Time: O(m*n), Space: O(m*n)
int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    
    int m = grid.size(), n = grid[0].size();
    int count = 0;
    
    function<void(int, int)> dfs = [&](int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') return;
        
        grid[i][j] = '0'; // mark as visited
        dfs(i+1, j);
        dfs(i-1, j);
        dfs(i, j+1);
        dfs(i, j-1);
    };
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfs(i, j);
            }
        }
    }
    
    return count;
}

// 2. Clone Graph (Amazon - Very Frequent)
// Deep copy of undirected graph
// Time: O(V + E), Space: O(V)
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node(int _val) : val(_val) {}
};

Node* cloneGraph(Node* node) {
    if (!node) return nullptr;
    
    unordered_map<Node*, Node*> visited;
    
    function<Node*(Node*)> dfs = [&](Node* n) -> Node* {
        if (visited.count(n)) return visited[n];
        
        Node* clone = new Node(n->val);
        visited[n] = clone;
        
        for (Node* neighbor : n->neighbors) {
            clone->neighbors.push_back(dfs(neighbor));
        }
        
        return clone;
    };
    
    return dfs(node);
}

// 3. Course Schedule (Amazon - Very Frequent)
// Check if can finish all courses (detect cycle in directed graph)
// Time: O(V + E), Space: O(V + E)
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);
    
    for (auto& pre : prerequisites) {
        adj[pre[1]].push_back(pre[0]);
        indegree[pre[0]]++;
    }
    
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) q.push(i);
    }
    
    int count = 0;
    while (!q.empty()) {
        int course = q.front();
        q.pop();
        count++;
        
        for (int next : adj[course]) {
            if (--indegree[next] == 0) {
                q.push(next);
            }
        }
    }
    
    return count == numCourses;
}

// 4. Course Schedule II (Amazon - Frequent)
// Return ordering of courses (topological sort)
// Time: O(V + E), Space: O(V + E)
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);
    
    for (auto& pre : prerequisites) {
        adj[pre[1]].push_back(pre[0]);
        indegree[pre[0]]++;
    }
    
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) q.push(i);
    }
    
    vector<int> order;
    while (!q.empty()) {
        int course = q.front();
        q.pop();
        order.push_back(course);
        
        for (int next : adj[course]) {
            if (--indegree[next] == 0) {
                q.push(next);
            }
        }
    }
    
    return order.size() == numCourses ? order : vector<int>();
}

// 5. Pacific Atlantic Water Flow (Amazon - Frequent)
// Find cells where water can flow to both oceans
// Time: O(m*n), Space: O(m*n)
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    if (heights.empty()) return {};
    
    int m = heights.size(), n = heights[0].size();
    vector<vector<bool>> pacific(m, vector<bool>(n, false));
    vector<vector<bool>> atlantic(m, vector<bool>(n, false));
    
    function<void(int, int, vector<vector<bool>>&)> dfs = [&](int i, int j, vector<vector<bool>>& visited) {
        visited[i][j] = true;
        vector<int> dirs = {0, 1, 0, -1, 0};
        
        for (int d = 0; d < 4; d++) {
            int ni = i + dirs[d];
            int nj = j + dirs[d+1];
            
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && 
                !visited[ni][nj] && heights[ni][nj] >= heights[i][j]) {
                dfs(ni, nj, visited);
            }
        }
    };
    
    // Start from edges
    for (int i = 0; i < m; i++) {
        dfs(i, 0, pacific);
        dfs(i, n-1, atlantic);
    }
    for (int j = 0; j < n; j++) {
        dfs(0, j, pacific);
        dfs(m-1, j, atlantic);
    }
    
    vector<vector<int>> result;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (pacific[i][j] && atlantic[i][j]) {
                result.push_back({i, j});
            }
        }
    }
    
    return result;
}

// 6. Network Delay Time (Amazon - Frequent)
// Shortest time for signal to reach all nodes (Dijkstra)
// Time: O((V + E) log V), Space: O(V + E)
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto& t : times) {
        adj[t[0]].push_back({t[1], t[2]});
    }
    
    vector<int> dist(n + 1, INT_MAX);
    dist[k] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, k});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    int maxTime = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) return -1;
        maxTime = max(maxTime, dist[i]);
    }
    
    return maxTime;
}

// 7. Word Ladder (Amazon - Very Frequent)
// Shortest transformation sequence length
// Time: O(N * L^2), Space: O(N * L)
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (!dict.count(endWord)) return 0;
    
    queue<string> q;
    q.push(beginWord);
    int steps = 1;
    
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            string word = q.front();
            q.pop();
            
            if (word == endWord) return steps;
            
            for (int j = 0; j < word.length(); j++) {
                char original = word[j];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[j] = c;
                    if (dict.count(word)) {
                        q.push(word);
                        dict.erase(word);
                    }
                }
                word[j] = original;
            }
        }
        steps++;
    }
    
    return 0;
}

// 8. Alien Dictionary (Amazon - Frequent)
// Find order of characters in alien language (topological sort)
// Time: O(C) where C is total length of all words, Space: O(1) for 26 letters
string alienOrder(vector<string>& words) {
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, int> indegree;
    
    // Initialize
    for (string& word : words) {
        for (char c : word) {
            indegree[c] = 0;
        }
    }
    
    // Build graph
    for (int i = 0; i < words.size() - 1; i++) {
        string& w1 = words[i];
        string& w2 = words[i+1];
        
        int minLen = min(w1.length(), w2.length());
        if (w1.length() > w2.length() && w1.substr(0, minLen) == w2.substr(0, minLen)) {
            return ""; // invalid
        }
        
        for (int j = 0; j < minLen; j++) {
            if (w1[j] != w2[j]) {
                if (!adj[w1[j]].count(w2[j])) {
                    adj[w1[j]].insert(w2[j]);
                    indegree[w2[j]]++;
                }
                break;
            }
        }
    }
    
    // Topological sort
    queue<char> q;
    for (auto& [c, deg] : indegree) {
        if (deg == 0) q.push(c);
    }
    
    string result;
    while (!q.empty()) {
        char c = q.front();
        q.pop();
        result += c;
        
        for (char next : adj[c]) {
            if (--indegree[next] == 0) {
                q.push(next);
            }
        }
    }
    
    return result.length() == indegree.size() ? result : "";
}

// 9. Minimum Knight Moves (Amazon - Frequent)
// Find minimum moves for knight to reach target
// Time: O(|x| * |y|), Space: O(|x| * |y|)
int minKnightMoves(int x, int y) {
    x = abs(x);
    y = abs(y);
    
    vector<pair<int, int>> dirs = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
    queue<pair<int, int>> q;
    set<pair<int, int>> visited;
    
    q.push({0, 0});
    visited.insert({0, 0});
    int moves = 0;
    
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto [cx, cy] = q.front();
            q.pop();
            
            if (cx == x && cy == y) return moves;
            
            for (auto [dx, dy] : dirs) {
                int nx = cx + dx;
                int ny = cy + dy;
                
                if (!visited.count({nx, ny}) && nx >= -1 && ny >= -1) {
                    visited.insert({nx, ny});
                    q.push({nx, ny});
                }
            }
        }
        moves++;
    }
    
    return -1;
}

int main() {
    // Number of Islands
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    cout << "Number of Islands: " << numIslands(grid) << "\n"; // 3
    
    // Course Schedule
    vector<vector<int>> prereq1 = {{1,0}};
    cout << "Can Finish Courses: " << (canFinish(2, prereq1) ? "true" : "false") << "\n";
    
    // Course Schedule II
    vector<vector<int>> prereq2 = {{1,0},{2,0},{3,1},{3,2}};
    auto order = findOrder(4, prereq2);
    cout << "Course Order: ";
    for (int c : order) cout << c << " ";
    cout << "\n";
    
    // Network Delay Time
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    cout << "Network Delay Time: " << networkDelayTime(times, 4, 2) << "\n";
    
    // Word Ladder
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout << "Word Ladder Length: " << ladderLength("hit", "cog", wordList) << "\n";
    
    // Alien Dictionary
    vector<string> words = {"wrt","wrf","er","ett","rftt"};
    cout << "Alien Order: " << alienOrder(words) << "\n";
    
    // Minimum Knight Moves
    cout << "Min Knight Moves to (5, 5): " << minKnightMoves(5, 5) << "\n";
    
    return 0;
}
