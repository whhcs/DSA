#ifndef BINARYSEARCHTREE_BST_H
#define BINARYSEARCHTREE_BST_H

#include <iostream>
#include <queue>
#include <cassert>

using namespace std;

// ����������
template<typename Key, typename Value>
class BST {

private:
	// �����������еĽڵ�Ϊ˽�нṹ�壬��粻��Ҫ�˽�����������ڵ�ľ���ʵ��
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

		Node(Node* node) {
			this->key = node->key;
			this->value = node->value;
			this->left = node->left;
			this->right = node->right;
		}
	};

	Node* root;		// ���ڵ�
	int count;		// �ڵ����

public:
	// ���캯����Ĭ�Ϲ���һ�ÿն���������
	BST() {
		root = nullptr;
		count = 0;
	}

	// �����������ͷŶ��������������пռ�
	~BST() {
		destroy(root);
		root = nullptr;
	}

	// ���ض����������Ľڵ����
	int size() const {
		return count;
	}

	// ���ض����������Ƿ�Ϊ��
	bool isEmpty() const {
		return count == 0;
	}

	// ������������в���һ���µ�(key, value)���ݶ�
	void insert(Key key, Value value) {
		root = insert(root, key, value);
	}

	// �鿴�������������Ƿ���ڼ�ֵkey
	bool contain(Key key) {
		return contain(root, key);
	}

	// �ڶ���������������key����Ӧ��ֵ��������ֵ�����ڣ��򷵻�nullptr
	Value* search(Key key) {
		return search(root, key);
	}

	// ������������ǰ�����
	void preOrder() {
		preOrder(root);
	}

	// �������������������
	void inOrder() {
		inOrder(root);
	}

	// �����������ĺ������
	void postOrder() {
		postOrder(root);
	}

	// �����������Ĳ������
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

	//Ѱ�Ҷ�������������С��ֵ
	Key minimum() {
		assert(count != 0);
		Node* minNode = minimum(root);
		return minNode->key;
	}

	// Ѱ�Ҷ���������������ֵ
	Key maximum() {
		assert(count != 0);
		Node* maxNode = maximum(root);
		return maxNode->key;
	}

	// �Ӷ�����������ɾ����Сֵ���ڵĽڵ�
	void removeMin() {
		if (root)
			root = removeMin(root);
	}

	// �Ӷ�����������ɾ�����ֵ���ڵĽڵ�
	void removeMax() {
		if (root)
			root = removeMax(root);
	}

	// �Ӷ�����������ɾ����ֵΪkey�Ľڵ�
	void remove(Key key) {
		root = remove(root, key);
	}

private:
	// ����nodeΪ���Ķ����������У�����ڵ�(key, value)��ʹ�õݹ��㷨
	// ���ز����½ڵ��Ķ����������ĸ�
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

	// �鿴��nodeΪ���ڵ�Ķ������������Ƿ������ֵΪkey�Ľڵ㣬ʹ�õݹ��㷨
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

	// ����nodeΪ���Ķ����������в���key����Ӧ��value��ʹ�õݹ��㷨
	// ��value�����ڣ�����nullptr
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

	// ����nodeΪ���Ķ�������������ǰ��������ݹ��㷨
	void preOrder(Node* node) {

		if (node != nullptr) {
			cout << node->key << endl;
			preOrder(node->left);
			preOrder(node->right);
		}
	}

	// ����nodeΪ���Ķ�����������������������ݹ��㷨
	void inOrder(Node* node) {

		if (node != nullptr) {
			inOrder(node->left);
			cout << node->key << endl;
			inOrder(node->right);
		}
	}

	// ����nodeΪ���Ķ������������к���������ݹ��㷨
	void postOrder(Node* node) {

		if (node != nullptr) {
			postOrder(node->left);
			postOrder(node->right);
			cout << node->key << endl;
		}
	}

	// �ͷ���nodeΪ���Ķ��������������нڵ�
	// ���ú�������ĵݹ��㷨
	void destroy(Node* node) {

		if (node != nullptr) {
			destroy(node->left);
			destroy(node->right);

			delete node;
			count--;
		}
	}

	// ������nodeΪ���Ķ�������������С��ֵ���ڵĽڵ�
	Node* minimum(Node* node) {

		if (node->left == nullptr)
			return node;

		return minimum(node->left);
	}

	// ������nodeΪ���Ķ���������������ֵ���ڵĽڵ�
	Node* maximum(Node* node) {

		if (node->right == nullptr)
			return node;

		return maximum(node->right);
	}

	// ɾ����nodeΪ���Ķ�������������С�ڵ�
	// ����ɾ���ڵ���µĶ����������ĸ�
	Node* removeMin(Node* node) {

		if (node->left == nullptr) {
			Node* rightNode = node->right;
			delete node;
			count--;
			return rightNode;
		}
		node->left = removeMin(node->left);
		return node;
	}

	// ɾ����nodeΪ���Ķ��������������ڵ�
	// ����ɾ���ڵ���µĶ����������ĸ�
	Node* removeMax(Node* node) {

		if (node->right == nullptr) {
			Node* leftNode = node->left;
			delete node;
			count--;
			return leftNode;
		}

		node->right = removeMax(node->right);
		return node;
	}

	// ɾ����nodeΪ���ڵ�Ķ����������м�ֵΪkey�Ľڵ㣬�ݹ��㷨
	// ����ɾ���ڵ���µĶ����������ĸ�
	Node* remove(Node* node, Key key) {

		if (node == nullptr)
			return nullptr;

		if (key < node->key) {
			node->left = remove(node->left, key);
			return node;
		}
		else if (key > node->key) {
			node->right = remove(node->right, key);
			return node;
		}
		else { // key == node->key

			// ��ɾ���ڵ�������Ϊ�յ����
			if (node->left == nullptr) {
				Node* rightNode = node->right;
				delete node;
				count--;
				return rightNode;
			}

			// ��ɾ���ڵ�������Ϊ�յ����
			if (node->right == nullptr) {
				Node* leftNode = node->left;
				delete node;
				count--;
				return leftNode;
			}

			// ��ɾ���ڵ�������������Ϊ�յ����

			// �ҵ��ȴ�ɾ���ڵ�����С�ӽڵ㣬����ɾ���ڵ������������С�ڵ�
			// ������ڵ㶥��ɾ���ڵ��λ��
			Node* successor = new Node(minimum(node->right));
			count++;

			successor->right = removeMin(node->right);
			successor->left = node->left;

			delete node;
			count--;

			return successor;
		}
	}
};

#endif // !BINARY_SEARCH_TREE_BST
