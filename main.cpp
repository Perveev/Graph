#include <iostream>
#include "vector"
#include "queue"

class Graph{
public:
    void buildGraph(int vertexCount, int edgeCount) {
        visited.resize(vertexCount, false);
        g.resize(vertexCount, std::vector<int>(0));
        int v;
        int u;
        for (int i = 0; i < edgeCount; i++) {
            std::cin >> v >> u;
            g[v].push_back(u);
        }
    }

    void clearVisit(){
        visited.assign(visited.size(),false);
    }
    void dfs(int vertex) {
        visited[vertex] = true;
        std::cout << "DFS) Now was " << vertex << " vertex\n";
        for(int i : g[vertex]) {
            if(!visited[i]){
                dfs(i);
            }
        }
    }

    void bfs(int vertex) {

        std::queue<int> q;
        q.push (vertex);
        visited[vertex] = true;

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for(int i=0; i < g[v].size(); i++) {
                if (!visited[g[v][i]]) {
                    visited[g[v][i]] = true;
                    q.push(g[v][i]);
                    std::cout << "BFS) Now was " << g[v][i] << " vertex\n";
                }
            }
        }
    }
private:
    std::vector<bool> visited;
    std::vector<std::vector<int>> g;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    Graph graph;
    graph.buildGraph(9,8);
    graph.dfs(0);
    graph.clearVisit();
    std::cout << std::endl;
    graph.bfs(0);
    return 0;
}
