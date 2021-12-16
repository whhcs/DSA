#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
#include "BST.hpp"
#include "SequenceST.hpp"
#include "FileOps.hpp"

using namespace std;

// 实验二分搜索树的局限性
int main() {

	// 我们使用文本量更小的共产主义宣言进行试验：
	string filename = "communist.txt";
	vector<string> words;

	if (FileOps::readFile(filename, words)) {

		cout << "There are totally " << words.size() << " words in " << filename << endl;
		cout << endl;


		// 测试1，我们按照文本原有顺序插入进二分搜索树
		time_t startTime = clock();
		BST<string, int>* bst = new BST<string, int>();

		for (auto iter = words.begin(); iter != words.end(); iter++) {
			int* res = (*bst).search(*iter);
			if (res == nullptr)
				(*bst).insert(*iter, 1);
			else
				(*res)++;
		}

		// 我们查看unite一词的词频
		if (bst->contain("unite"))
			cout << "unite: " << *(*bst).search("unite") << endl;
		else
			cout << "No word 'unite' in " + filename << endl;
		time_t endTime = clock();

		cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
		cout << endl;

		delete bst;


		// 测试2，我们按照文本原有顺序插入进顺序查找表
		startTime = clock();
		SequenceST<string, int>* sst = new SequenceST<string, int>();

		for (auto iter = words.begin(); iter != words.end(); iter++) {
			int* res = (*sst).search(*iter);
			if (res == nullptr)
				(*sst).insert(*iter, 1);
			else
				(*res)++;
		}

		// 我们查看unite一词的词频
		if (sst->contain("unite"))
			cout << "unite: " << *(*sst).search("unite") << endl;
		else
			cout << "No word 'unite' in " + filename << endl;
		endTime = clock();

		cout << "SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
		cout << endl;

		delete sst;


		sort(words.begin(), words.end());

		// 测试3，我们将原文本排序后插入二叉搜索树，查看其效率
		startTime = clock();
		BST<string, int>* bst2 = new BST<string, int>();

		for (auto iter = words.begin(); iter != words.end(); iter++) {
			int* res = (*bst2).search(*iter);
			if (res == nullptr)
				(*bst2).insert(*iter, 1);
			else
				(*res)++;
		}

		// 我们查看unite一词的词频
		cout << "unite: " << *(*bst2).search("unite") << endl;
		endTime = clock();

		cout << "BST2 , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
		cout << endl;

		delete bst2;
	}

	return 0;
}