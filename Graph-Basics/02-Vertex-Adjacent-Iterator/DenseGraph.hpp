#ifndef GRAPH_REPRESENTATION_DENSEGRAPH_H
#define GRAPH_REPRESENTATION_DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// ����ͼ - �ڽӾ���
class DenseGraph {

private:
	int n, m;	// �ڵ���������
	bool directed;		// �Ƿ�Ϊ����ͼ
	vector<vector<bool>> g;		// ͼ�ľ�������

public:
	// ���캯��
	DenseGraph(int n, bool directed) {

		assert(n >= 0);
		this->n = n;
		this->m = 0;	// ��ʼ��û���κα�
		this->directed = directed;
		// g��ʼ��Ϊn*n�Ĳ�������ÿһ��g[i][j]��Ϊfalse����ʾû���κα�
		for (int i = 0; i < n; i++)
			g.push_back(vector<bool>(n, false));
	}
	
	~DenseGraph() {}

	int V() const { return n; }	// ���ؽڵ����
	int E() const { return m; }	// ���ؽڵ����

	// ��ͼ�����һ����
	void addEdge(int v, int w) {

		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);

		if (hasEdge(v, w))	// ���Էǳ�����Ĵ���ƽ�б�
			return;

		if (v != w) {	// �����Ի���
			g[v][w] = true;
			if (!directed)
				g[w][v] = true;

			m++;
		}
	}
	
	// ��֤ͼ���Ƿ��д�v��w�ı�
	bool hasEdge(int v, int w) const {

		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);
		return g[v][w];
	}

	// �ڱߵ�����������һ��ͼ��һ������
	// ���������ͼ�к�����������������ж���
	class adjIterator {
	
	private:
		DenseGraph& G;	// ͼG������
		int v;
		int index;

	public:
		// ���캯��
		adjIterator(DenseGraph& graph, int v) :G(graph) {
			this->v = v;
			this->index = -1;	// ����Ĭ�ϴ�-1��ʼ����Ϊÿ�α�������Ҫ����һ��next()
		}
		
		~adjIterator(){}
		
		// ����ͼG���ڶ���v�����ӵĵ�һ������
		int begin() {

			// ������-1��ʼ����Ϊÿ�α�������Ҫ����һ��next()
			index = -1;
			return next();
		}

		// ����ͼG���붥��v�����ӵĵ�һ������
		int next() {

			// �ӵ�ǰindex��ʼ���������ֱ���ҵ���һ��g[v][index]Ϊtrue
			for (index += 1; index < G.V(); index++)
				if (G.g[v][index])
					return index;
			// ��û�ж�����v�����ӣ�����-1
			return -1;
		}

		// �鿴�Ƿ��Ѿ���������ͼG���붥��v�����ӵ����ж���
		bool end() const {
			return index >= G.V();
		}

	};
};

#endif // !GRAPH_REPRESENTATION_DENSEGRAPH_H