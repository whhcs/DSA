#include <iostream>
#include <string>
#include <iomanip>
#include "Edge.hpp"
#include "DenseGraph.hpp"
#include "ReadGraph.hpp"
#include "SparseGraph.hpp"

using namespace std;

int main() {
	
	string filename = "testG1.txt";
	int V = 8;
	cout << fixed << setprecision(2);

	// Test Weighted Dense Graph
	DenseGraph<double> g1(V, false);
	ReadGraph<DenseGraph<double>, double> readGraph1(g1, filename);
	g1.show();
	cout << endl;

	// Test Weighted Sparse Graph
	SparseGraph<double> g2(V, false);
	ReadGraph<SparseGraph<double>, double> readGraph2(g2, filename);
	g2.show();
	cout << endl;
	return 0;
}