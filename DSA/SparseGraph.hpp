#ifndef GRAPH_SPARSEGRAPH_H
#define GRAPH_SPARSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 稀疏图 - 邻接表
class SparseGraph
{

private:
	int n, m;
	bool directed;
	vector<vector<int>> g;

public:
	SparseGraph(int n, bool directed)
	{
		this->n = n;
		this->m = 0;
		this->directed = directed;
		for (int i = 0; i < n; i++)
			g.push_back(vector<int>());
	}

	~SparseGraph() {}

	int V() { return n; }
	int E() { return m; }

	void addEdge(int v, int w)
	{

		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);

		// 处理平行边：如果每次addEdge时都判断是否存在v到w的边
		// 那么时间复杂度为O(n)，时间成本较高
		// 因此，一般情况下，在addEdge函数中我们先不处理平行边
		// 可以等整张图中的所有边都添加完之后，再综合处理所有平行边
		if (v != w)
		{ // 处理自环边
			g[v].push_back(w);
			if (!directed)
				g[w].push_back(v);

			m++;
		}
	}

	bool hasEdge(int v, int w)
	{

		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);

		for (int i = 0; i < g[v].size(); i++) // 最坏情况时间复杂度为O(n)
			if (g[v][i] == w)
				return true;
		return false;
	}

	class adjIterator
	{
	private:
		SparseGraph& G;
		int v;
		int index;

	public:
		adjIterator(SparseGraph& graph, int v) : G(graph)
		{
			this->v = v;
			this->index = 0;
		}

		int begin() {
			index = 0;
			if (G.g[v].size())
				return G.g[v][index];
			return -1;
		}

		int next() {
			index++;
			if (index < G.g[v].size())
				return G.g[v][index];
			return -1;
		}

		bool end() {
			return index >= G.g[v].size();
		}
	};
};
#endif // !GRAPH_SPARSEGRAPH_H
