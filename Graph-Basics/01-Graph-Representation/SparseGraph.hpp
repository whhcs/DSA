#ifndef GRAPH_REPRESENTATION_SPARSEGRAPH_H
#define GRAPH_REPRESENTATION_SPARSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 稀疏图 - 邻接表
class SparseGraph {

private:
	int n, m;	// 节点数，边数
	bool directed;		// 是否为有向图
	vector<vector<int>> g;		// 图的具体数据

public:
	// 构造函数
	SparseGraph(int n, bool directed) {

		assert(n >= 0);
		this->n = n;
		this->m = 0;	// 初始化没有任何边
		this->directed = directed;
		// g初始化为n个空的vector，每一个g[i]均为空，表示没有任何边相邻
		for (int i = 0; i < n; i++)
			g.push_back(vector<int>());
	}

	~SparseGraph() {

	}

	int V() const { return n; }	// 返回节点个数
	int E() const { return m; }	// 返回节点边数

	// 向图中添加一个边
	void addEdge(int v, int w) {

		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);

		if(hasEdge(v, w))
			return;

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

	// 验证图是否有从v到w的边
	bool hasEdge(int v, int w) {

		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);

		for (int i = 0; i < g[v].size(); i++)	// 最坏情况时间复杂度为O(n)
			if (g[v][i] == w)
				return true;
		return false;
	}
};
#endif // !GRAPH_REPRESENTATION_SPARSEGRAPH_H
