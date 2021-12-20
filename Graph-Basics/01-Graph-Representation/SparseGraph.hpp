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

	~SparseGraph() {

	}

	int V() const { return n; }	// ���ؽڵ����
	int E() const { return m; }	// ���ؽڵ����

	// ��ͼ�����һ����
	void addEdge(int v, int w) {

		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);

		if(hasEdge(v, w))
			return;

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

	// ��֤ͼ�Ƿ��д�v��w�ı�
	bool hasEdge(int v, int w) {

		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);

		for (int i = 0; i < g[v].size(); i++)	// ����ʱ�临�Ӷ�ΪO(n)
			if (g[v][i] == w)
				return true;
		return false;
	}
};
#endif // !GRAPH_REPRESENTATION_SPARSEGRAPH_H
