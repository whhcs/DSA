#ifndef MINIMUMSPANTREE_DENSEGRAPH_H
#define MINIMUMSPANTREE_DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.hpp"

using namespace std;

// 稠密图 - 邻接矩阵
template<typename Weight>
class DenseGraph {
private:
	int n, m;
	bool directed;
	vector<vector<Edge<Weight> *>> g;

public:
	DenseGraph(int n, bool directed) {
		this->n = n;
		this->m = 0;
		this->directed = directed;
		for (int i = 0; i < n; i++)
			g.push_back(vector<Edge<Weight> *>(n, nullptr));
	}

	~DenseGraph() {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (g[i][j] != nullptr)
					delete g[i][j];
	}

	int V() { return n; }
	int E() { return m; }

	void addEdge(int v, int w, Weight weight ) {

		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);

		if (hasEdge(v, w)) {// 可以非常方便的处理平行边
			delete g[v][w];
			if (!directed)
				delete g[w][v];
			m--;
		}
			

		g[v][w] = new Edge<Weight>(v, w, weight);
		if (!directed)
			g[w][v] = new Edge<Weight>(w, v, weight);

		m++;
	}

	bool hasEdge(int v, int w) {
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);
		return g[v][w] != nullptr;
	}

	void show() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				if (g[i][j])
					cout << g[i][j]->wt() << "\t";
				else
					cout << "NULL\t";
			cout << endl;
		}
	}

	class adjIterator {
	private:
		DenseGraph& G;
		int v;
		int index;
	public:
		adjIterator(DenseGraph& graph, int v) :G(graph) {
			this->v = v;
			this->index = -1;
		}

		Edge<Weight>* begin() {
			index = -1;
			return next();
		}

		Edge<Weight>* next() {
			for (index += 1; index < G.V(); index++)
				if (G.g[v][index])
					return G.g[v][index];
			return nullptr;
		}

		bool end() {
			return index >= G.V();
		}
	};

};
#endif // !MINIMUMSPANTREE_DENSEGRAPH_H
