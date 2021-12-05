#ifndef GRAPH_SHORTESTPATH_H
#define GRAPH_SHORTESTPATH_H

#include<iostream>
#include<queue>
#include<stack>
#include<cassert>

using namespace std;

template <typename Graph>
class ShortestPath {

private:
	Graph & G;
	int s;
	bool* visited;
	int *from;
	int* ord;

	void bfs(int v) {

		queue<int> q;
		q.push(v);
		visited[v] = true;
		ord[v] = 0;
		while (!q.empty()) {

			int u = q.front();
			q.pop();

			typename Graph::adjIterator adj(G, u);
			for (int i = adj.begin(); !adj.end(); i = adj.next())
				if (!visited[i]) {
					q.push(i);
					visited[i] = true;
					from[i] = u;
					ord[i] = ord[u] + 1;
				}
		}
	}
public:
	ShortestPath(Graph& graph, int s) : G(graph) {

		// 算法初始化
		assert(s >= 0 && s < G.V());

		visited = new bool[G.V()];
		from = new int[G.V()];
		ord = new int[G.V()];
		for (int i = 0; i < G.V(); i++) {
			visited[i] = false;
			from[i] = -1;
			ord[i] = -1;
		}
		this->s = s;

		// 无向图最短路劲算法
		bfs(s);
	}
	
	~ShortestPath() {

		delete[] visited;
		delete[] from;
		delete[] ord;
	}

	bool hasPath(int w) {

		assert(w >= 0 && w < G.V());
		return visited[w];
	}

	void path(int w, vector<int>& vec) {

		stack<int> s;

		int p = w;
		while (p != -1) {
			s.push(p);
			p = from[p];
		}

		vec.clear();
		while (!s.empty()) {
			vec.push_back(s.top());
			s.pop();
		}
	}

	void showPath(int w) {

		vector<int> vec;
		path(w, vec);

		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i];
			if (i == vec.size() - 1)
				cout << endl;
			else
				cout << " -> ";
		}
	}

	int length(int w) {
		
		assert(w >= 0 && w < G.V());
		return ord[w];
	}
};
#endif // !GRAPH_SHORTESTPATH_H
