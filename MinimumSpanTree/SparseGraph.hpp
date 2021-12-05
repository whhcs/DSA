#ifndef MINIMUMSPANTREE_SPARSEGRAPH_H
#define MINIMUMSPANTREE_SPARSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.hpp"

using namespace std;

// ϡ��ͼ - �ڽӱ�
template<typename Weight>
class SparseGraph
{

private:
	int n, m;
	bool directed;
	vector<vector<Edge<Weight> *>> g;

public:
	SparseGraph(int n, bool directed)
	{
		this->n = n;
		this->m = 0;
		this->directed = directed;
		for (int i = 0; i < n; i++)
			g.push_back(vector<Edge<Weight>*>());
	}

	~SparseGraph() {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < g[i].size(); j++)
				delete g[i][j];
	}

	int V() { return n; }
	int E() { return m; }

	void addEdge(int v, int w, Weight weight)
	{

		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);

		// ����ƽ�бߣ����ÿ��addEdgeʱ���ж��Ƿ����v��w�ı�
		// ��ôʱ�临�Ӷ�ΪO(n)��ʱ��ɱ��ϸ�
		// ��ˣ�һ������£���addEdge�����������Ȳ�����ƽ�б�
		// ���Ե�����ͼ�е����б߶������֮�����ۺϴ�������ƽ�б�
		if (v != w)
		{ // �����Ի���
			g[v].push_back(new Edge<Weight>(v, w, weight));
			if (!directed)
				g[w].push_back(new Edge<Weight>(w, v, weight));

			m++;
		}
	}

	bool hasEdge(int v, int w)
	{

		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);

		for (int i = 0; i < g[v].size(); i++) // ����ʱ�临�Ӷ�ΪO(n)
			if (g[v][i]->other(v) == w)
				return true;
		return false;
	}

	void show() {
		for (int i = 0; i < n; i++) {
			cout << "vertex " << i << ":\t";
			for (int j = 0; j < g[i].size(); j++)
				cout << "( to: " << g[i][j]->w() << ", wt: " << g[i][j]->wt() << ")\t";
			cout << endl;
		}
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

		Edge<Weight>* begin() {
			index = 0;
			if (G.g[v].size())
				return G.g[v][index];
			return nullptr;
		}

		Edge<Weight>* next() {
			index++;
			if (index < G.g[v].size())
				return G.g[v][index];
			return nullptr;
		}

		bool end() {
			return index >= G.g[v].size();
		}
	};
};

#endif // !MINIMUMSPANTREE_SPARSEGRAPH_H
