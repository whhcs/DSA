#include <iostream>
#include <queue>

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
		destroy(root);
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

	// 二分搜索树的前序遍历
	void preOrder() {
		preOrder(root);
	}

	// 二分搜索树的中序遍历
	void inOrder() {
		inOrder(root);
	}

	// 二分搜索树的后序遍历
	void postOrder() {
		postOrder(root);
	}

	// 二分搜索树的层序遍历
	void levelOrder() {

		if (root == nullptr)
			return;

		queue<Node*> q;
		q.push(root);
		while (!q.empty()) {

			Node* node = q.front();
			q.pop();

			cout << node->key << endl;

			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
		}
	}

	// 寻找最小的键值
	Key minimum() {
		assert(count != 0);
		Node* minNode = minimum(root);
		return minNode->key;
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

	// 对以node为根的二叉搜索树进行前序遍历，递归算法
	void preOrder(Node* node) {

		if (node != nullptr) {
			cout << node->key << endl;
			preOrder(node->left);
			preOrder(node->right);
		}
	}

	// 对以node为根的二叉搜索树进行中序遍历，递归算法
	void inOrder(Node* node) {

		if (node != nullptr) {
			inOrder(node->left);
			cout << node->key << endl;
			inOrder(node->right);
		}
	}

	// 对以node为根的二叉搜索树进行后序遍历，递归算法
	void postOrder(Node* node) {

		if (node != nullptr) {
			postOrder(node->left);
			postOrder(node->right);
			cout << node->key << endl;
		}
	}

	// 释放以node为根的二分搜索树的所有节点
	// 采用后序遍历的递归算法
	void destroy(Node* node) {

		if (node != nullptr) {
			destroy(node->left);
			destroy(node->right);

			delete node;
			count--;
		}
	}

	Node* minimum(Node* node) {
		if (node->left == nullptr)
			return node;

		return minimum(node->left);
	}
};

int main() {

	return 0;
}