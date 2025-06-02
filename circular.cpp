#include <vector>
#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

class ModuleLoader {
public:
    bool hasCircularDependency(int n, vector<vector<int>>& edges) {
        // Build adjacency list representation of the graph
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }
        
        // Track visited nodes and nodes in current DFS path
        vector<int> color(n, 0); // 0: unvisited, 1: visiting, 2: visited
        
        // Check each component of the graph
        for (int i = 0; i < n; i++) {
            if (color[i] == 0) {
                if (hasCycleDFS(graph, i, color)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
private:
    bool hasCycleDFS(vector<vector<int>>& graph, int node, vector<int>& color) {
        // Mark current node as being visited (gray)
        color[node] = 1;
        
        // Visit all neighbors
        for (int neighbor : graph[node]) {
            if (color[neighbor] == 1) {
                // Back edge found - cycle detected
                return true;
            }
            if (color[neighbor] == 0 && hasCycleDFS(graph, neighbor, color)) {
                return true;
            }
        }
        
        // Mark node as completely visited (black)
        color[node] = 2;
        return false;
    }
};

// Alternative solution using Kahn's Algorithm (Topological Sort)
class ModuleLoaderKahn {
public:
    bool hasCircularDependency(int n, vector<vector<int>>& edges) {
        // Build adjacency list and calculate in-degrees
        vector<vector<int>> graph(n);
        vector<int> inDegree(n, 0);
        
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }
        
        // Find all nodes with no incoming edges
        queue<int> queue;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                queue.push(i);
            }
        }
        
        int processedNodes = 0;
        
        // Process nodes level by level
        while (!queue.empty()) {
            int current = queue.front();
            queue.pop();
            processedNodes++;
            
            // Reduce in-degree of neighbors
            for (int neighbor : graph[current]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    queue.push(neighbor);
                }
            }
        }
        
        // If we processed all nodes, there's no cycle
        return processedNodes != n;
    }
};

// Test function
void testCircularDependency() {
    ModuleLoader loader;
    
    // Test Case 1: No cycle
    cout << "Test Case 1: No cycle" << endl;
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {2, 3}};
    bool result1 = loader.hasCircularDependency(4, edges1);
    cout << "Input: n=4, edges={{0,1},{1,2},{2,3}}" << endl;
    cout << "Output: " << (result1 ? "true" : "false") << endl;
    cout << "Expected: false" << endl;
    cout << endl;
    
    // Test Case 2: Has cycle
    cout << "Test Case 2: Has cycle" << endl;
    vector<vector<int>> edges2 = {{0, 1}, {1, 2}, {2, 0}};
    bool result2 = loader.hasCircularDependency(4, edges2);
    cout << "Input: n=4, edges={{0,1},{1,2},{2,0}}" << endl;
    cout << "Output: " << (result2 ? "true" : "false") << endl;
    cout << "Expected: true" << endl;
    cout << endl;
    
    // Test Case 3: Self-dependency (cycle)
    cout << "Test Case 3: Self-dependency" << endl;
    vector<vector<int>> edges3 = {{0, 0}};
    bool result3 = loader.hasCircularDependency(1, edges3);
    cout << "Input: n=1, edges={{0,0}}" << endl;
    cout << "Output: " << (result3 ? "true" : "false") << endl;
    cout << "Expected: true" << endl;
    cout << endl;
    
    // Test Case 4: Multiple components, one with cycle
    cout << "Test Case 4: Multiple components with cycle" << endl;
    vector<vector<int>> edges4 = {{0, 1}, {2, 3}, {3, 2}};
    bool result4 = loader.hasCircularDependency(4, edges4);
    cout << "Input: n=4, edges={{0,1},{2,3},{3,2}}" << endl;
    cout << "Output: " << (result4 ? "true" : "false") << endl;
    cout << "Expected: true" << endl;
    cout << endl;
    
    // Test Case 5: Empty graph
    cout << "Test Case 5: Empty graph" << endl;
    vector<vector<int>> edges5 = {};
    bool result5 = loader.hasCircularDependency(3, edges5);
    cout << "Input: n=3, edges={}" << endl;
    cout << "Output: " << (result5 ? "true" : "false") << endl;
    cout << "Expected: false" << endl;
    cout << endl;
}

int main() {
    testCircularDependency();
    return 0;
}