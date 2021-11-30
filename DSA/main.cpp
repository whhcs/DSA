#include <iostream>
#include "SparseGraph.hpp"
#include "DenseGraph.hpp"
#include <vector>

using namespace std;

int main()
{
    // 随机创建稀疏图和稠密图

    int N = 20;
    int M = 100;

    srand(time(NULL));

    // Sparse Graph
    SparseGraph g1(N, false);
    for (int i = 0; i < M; i++)
    {
        int a = rand() % N;
        int b = rand() % N;
        g1.addEdge(a, b);
    }

    // O(E)
    for (int v = 0; v < N; v++)
    {
        cout << v << " : ";
        SparseGraph::adjIterator adj(g1, v);
        for (int w = adj.begin(); !adj.end(); w = adj.next())
            cout << w << " ";
        puts("");
    }

    puts("");

    // Dense graph
    DenseGraph g2(N, false);
    for (int i = 0; i < M; i++)
    {
        int a = rand() % N;
        int b = rand() % N;
        g2.addEdge(a, b);
    }

    // O(V^2)
    for (int v = 0; v < N; v++)
    {
        cout << v << " : ";
        DenseGraph::adjIterator adj(g2, v);
        for (int w = adj.begin(); !adj.end(); w = adj.next())
            cout << w << " ";
        puts("");
    }
    return 0;
}