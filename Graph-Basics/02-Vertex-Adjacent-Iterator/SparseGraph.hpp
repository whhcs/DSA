#ifndef GRAPH_REPRESENTATION_SPARSEGRAPH_H
#define GRAPH_REPRESENTATION_SPARSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// ϡ��ͼ - �ڽӱ�
class SparseGraph {

private:
	int n, m;	// �ڵ���������
	bool directed;		// �Ƿ�Ϊ����ͼ
	vector<vector<int>> g;		// ͼ�ľ�������

public:
	// ���캯��
	SparseGraph(int n, bool directed) {

		assert(n >= 0);
		this->n = n;
		this->m = 0;	// ��ʼ��û���κα�
		this->directed = directed;
		// g��ʼ��Ϊn���յ�vector��ÿһ��g[i]��Ϊ�գ���ʾû���κα�����
		for (int i = 0; i < n; i++)
			g.push_back(vector<int>());
	}

	~SparseGraph() {}

	int V() const { return n; }	// ���ؽڵ����
	int E() const { return m; }	// ���ؽڵ����

	// ��ͼ�����һ����
	void addEdge(int v, int w) {

		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);

		// ����ƽ�бߣ����ÿ��addEdgeʱ���ж��Ƿ����v��w�ı�
		// ��ôʱ�临�Ӷ�ΪO(n)��ʱ��ɱ��ϸ�
		// ��ˣ�һ������£���addEdge�����������Ȳ�����ƽ�б�
		// ���Ե�����ͼ�е����б߶������֮�����ۺϴ�������ƽ�б�
		//	if (hasEdge(v, w))
		//		return;

		if (v != w)
		{ // �����Ի���
			g[v].push_back(w);
			if (!directed)
				g[w].push_back(v);

			m++;
		}
	}

	// ��֤ͼ�Ƿ��д�v��w�ı�
	bool hasEdge(int v, int w) {

		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);

		for (int i = 0; i < g[v].size(); i++)	// ����ʱ�临�Ӷ�ΪO(n)
			if (g[v][i] == w)
				return true;
		return false;
	}

	// �ڱߵ�����������һ��ͼ��һ������
	// ���������ͼ�к�����������������ж���
	class adjIterator {

	private:
		SparseGraph& G;	// ͼG������
		int v;
		int index;

	public:
		// ���캯��
		adjIterator(SparseGraph& graph, int v) : G(graph) {
			this->v = v;
			this->index = 0;
		}

		~adjIterator() {}

		// ����ͼG���붥��v�����ӵ����ж���
		int begin() {
			index = 0;
			if (G.g[v].size())
				return G.g[v][index];
			// ��û�ж�����v�����ӣ�����-1
			return -1;
		}

		// ����ͼG���붥��v�����ӵ���һ������
		int next() {
			index++;
			if (index < G.g[v].size())
				return G.g[v][index];
			// ��û�ж�����v�����ӣ�����-1
			return -1;
		}

		int end() const {
			return index >= G.g[v].size();
		}
	};
};
#endif // !GRAPH_REPRESENTATION_SPARSEGRAPH_H