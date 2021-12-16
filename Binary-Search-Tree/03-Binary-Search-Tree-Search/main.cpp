#include <iostream>
#include <vector>
#include <string>
#include "SequenceST.hpp"
#include "FileOps.hpp"

using namespace std;

// 二分搜索树
template<typename Key, typename Value>
class BST {

private:
	// 二分搜索树中的节点为私有结构体，外界不需要了解二分搜索树节点的具体实现
	struct Node {
		Key key;
		Value value;
		Node* left;
		Node* right;

		Node(Key key, Value value) {
			this->key = key;
			this->value = value;
			this->left = this->right = nullptr;
		}
	};

	Node* root;		// 根节点
	int count;		// 节点个数

public:
	// 构造函数，默认构造一棵空二分搜索树
	BST() {
		root = nullptr;
		count = 0;
	}

	// 析构函数，释放二分搜索树的所有空间
	~BST() {
		// TODO:
	}

	// 返回二分搜索树的节点个数
	int size() const {
		return count;
	}

	// 返回二分搜索树是否为空
	bool isEmpty() const {
		return count == 0;
	}

	// 向二分搜索树中插入一个新的(key, value)数据对
	void insert(Key key, Value value) {
		root = insert(root, key, value);
	}

	// 查看二分搜索树中是否存在键值key
	bool contain(Key key) {
		return contain(root, key);
	}

	// 在二分搜索树中搜索key所对应的值，如果这个值不存在，则返回nullptr
	Value* search(Key key) {
		return search(root, key);
	}

private:
	// 向以node为根的二叉搜索树中，插入节点(key, value)，使用递归算法
	// 返回插入新节点后的二叉搜索树的根
	Node* insert(Node* node, Key key, Value value) {

		if (node == nullptr) {
			count++;
			return new Node(key, value);
		}
		if (key == node->key)
			node->value = value;
		else if (key < node->key)
			node->left = insert(node->left, key, value);
		else // key > node->key
			node->right = insert(node->right, key, value);
		return node;
	}

	// 查看以node为根节点的二叉搜索树中是否包含键值为key的节点，使用递归算法
	bool contain(Node* node, Key key) {

		if (node == nullptr)
			return false;
		if (key == node->key)
			return true;
		else if (key < node->key)
			return contain(node->left, key);
		else
			return contain(node->right, key);
	}

	// 在以node为根的二叉搜索树中查找key所对应的value，使用递归算法
	// 若value不存在，返回nullptr
	Value* search(Node* node, Key key) {

		if (node == nullptr)
			return nullptr;
		if (key == node->key)
			return &(node->value);
		else if (key < node->key)
			return search(node->left, key);
		else
			return search(node->right, key);
	}
};


int main() {

	// 测试二分搜索树和顺序查找表之间的性能差距
// 二分搜索树的性能远远优于顺序查找表

// 使用圣经作为我们的测试用例
	string filename = "bible.txt";
	vector<string> words;
	if (FileOps::readFile(filename, words)) {

		cout << "There are totally " << words.size() << " words in " << filename << endl;
		cout << endl;


		// 测试BST
		time_t startTime = clock();

		// 统计圣经中所有词的词频
		// 注：这个词频统计法相对简陋，没有考虑很多文本处理中的特殊问题
		// 在这里只做性能测试用
		BST<string, int> bst;
		for (auto iter = words.begin(); iter != words.end(); iter++) {
			int* res = bst.search(*iter);
			if (res == nullptr)
				bst.insert(*iter, 1);
			else
				(*res)++;
		}

		// 输出圣经中god一词出现的频率
		if (bst.contain("god"))
			cout << "'god' : " << *bst.search("god") << endl;
		else
			cout << "No word 'god' in " << filename << endl;

		time_t endTime = clock();

		cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC
			<< " s." << endl;
		cout << endl;


		// 测试顺序查找表 SST
		startTime = clock();

		// 统计圣经中所有词的词频
		// 注：这个词频统计法相对简陋，没有考虑很多文本处理中的特殊问题
		// 在这里只做性能测试用
		SequenceST<string, int> sst;
		for (auto iter = words.begin(); iter != words.end(); iter++) {
			int* res = sst.search(*iter);
			if (res == nullptr)
				sst.insert(*iter, 1);
			else
				(*res)++;
		}

		// 输出圣经中god一词出现的频率
		if (sst.contain("god"))
			cout << "'god' : " << *sst.search("god") << endl;
		else
			cout << "No word 'god' in " << filename << endl;

		endTime = clock();

		cout << "SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC
			<< " s." << endl;
	}
	return 0;
}