#ifndef GRAPH_REPRESENTATION_DENSEGRAPH_H
#define GRAPH_REPRESENTATION_DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 稠密图 - 邻接矩阵
class DenseGraph {

private:
	int n, m;	// 节点数，边数
	bool directed;		// 是否为有向图
	vector<vector<bool>> g;		// 图的具体数据

public:
	// 构造函数
	DenseGraph(int n, bool directed) {

		assert(n >= 0);
		this->n = n;
		this->m = 0;	// 初始化没有任何边
		this->directed = directed;
		// g初始化为n*n的布尔矩阵，每一个g[i][j]均为false，表示没有任何边
		for (int i = 0; i < n; i++)
			g.push_back(vector<bool>(n, false));
	}
	
	~DenseGraph() {

	}

	int V() const { return n; }	// 返回节点个数
	int E() const { return m; }	// 返回节点边数

	// 向图中添加一个边
	void addEdge(int v, int w) {

		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);

		if (hasEdge(v, w))	// 可以非常方便的处理平行边
			return;

		if (v != w) {	// 处理自环边
			g[v][w] = true;
			if (!directed)
				g[w][v] = true;

			m++;
		}
	}
	
	bool hasEdge(int v, int w) const {

		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);
		return g[v][w];
	}
};

#endif // !GRAPH_REPRESENTATION_DENSEGRAPH_H