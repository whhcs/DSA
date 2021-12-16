#include <iostream>

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
};


int main() {

	return 0;
}