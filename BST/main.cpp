#include <iostream>

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
	};

	Node* root;		// ���ڵ�
	int count;		// �ڵ����

public:
	// Ĭ�Ϲ���һ�ÿն���������
	BST() {		
		root = nullptr;
		count = 0;
	}
	~BST() {
		// TODO:
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
		retturn search(root, key);
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
};

int main() {

	return 0;
}