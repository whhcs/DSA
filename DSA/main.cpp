#include <iostream>
#include "SparseGraph.hpp"
#include "DenseGraph.hpp"
#include "ReadGraph.hpp"

using namespace std;

int main()
{
    //// 7-1~7-3 随机创建稀疏图和稠密图

    //int N = 20;
    //int M = 100;

    //srand(time(NULL));

    //// Sparse Graph
    //SparseGraph g1(N, false);
    //for (int i = 0; i < M; i++)
    //{
    //    int a = rand() % N;
    //    int b = rand() % N;
    //    g1.addEdge(a, b);
    //}

    //// O(E)
    //for (int v = 0; v < N; v++)
    //{
    //    cout << v << " : ";
    //    SparseGraph::adjIterator adj(g1, v);
    //    for (int w = adj.begin(); !adj.end(); w = adj.next())
    //        cout << w << " ";
    //    puts("");
    //}

    //puts("");

    //// Dense graph
    //DenseGraph g2(N, false);
    //for (int i = 0; i < M; i++)
    //{
    //    int a = rand() % N;
    //    int b = rand() % N;
    //    g2.addEdge(a, b);
    //}

    //// O(V^2)
    //for (int v = 0; v < N; v++)
    //{
    //    cout << v << " : ";
    //    DenseGraph::adjIterator adj(g2, v);
    //    for (int w = adj.begin(); !adj.end(); w = adj.next())
    //        cout << w << " ";
    //    puts("");
    //}



    // 7-4 图的算法框架
    string filename = "testG1.txt";
    
    SparseGraph g1(13, false);
    ReadGraph<SparseGraph> readGraph1(g1, filename);
    g1.show();

    cout << endl;

    DenseGraph g2(13, false);
    ReadGraph<DenseGraph> readGraph2(g2, filename);
    g2.show();
    return 0;
}