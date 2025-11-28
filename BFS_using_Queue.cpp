#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <set>
using namespace std;

void bfs(unordered_map<char, vector<char>> &graph, char start) {
    set<char> visited;            
    queue<char> q;               

    visited.insert(start);
    q.push(start);

    while (!q.empty()) {
        char node = q.front();
        q.pop();

        cout << node << " ";

        for (char neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
}

int main() {
    unordered_map<char, vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'D', 'E'}},
        {'C', {'F'}},
        {'D', {}},
        {'E', {'F'}},
        {'F', {}}
    };

    cout << "BFS Traversal:\n";
    bfs(graph, 'A');

    return 0;
}
