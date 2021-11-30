#ifndef GRAPH_SPARSEGRAPH_H
#define GRAPH_SPARSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// ϡ��ͼ - �ڽӱ�
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

		// ����ƽ�бߣ����ÿ��addEdgeʱ���ж��Ƿ����v��w�ı�
		// ��ôʱ�临�Ӷ�ΪO(n)��ʱ��ɱ��ϸ�
		// ��ˣ�һ������£���addEdge�����������Ȳ�����ƽ�б�
		// ���Ե�����ͼ�е����б߶������֮�����ۺϴ�������ƽ�б�
		if (v != w)
		{ // �����Ի���
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

		for (int i = 0; i < g[v].size(); i++) // ����ʱ�临�Ӷ�ΪO(n)
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
