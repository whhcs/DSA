#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
#include "SequenceST.hpp"
#include "FileOps.hpp"

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
	// ���캯����Ĭ�Ϲ���һ�ÿն���������
	BST() {		
		root = nullptr;
		count = 0;
	}

	// �����������ͷŶ��������������пռ�
	~BST() {
		destroy(root);
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
};


int main() {

	//// ���Զ�����������˳����ұ�֮������ܲ��
	//// ����������������ԶԶ����˳����ұ�

	//// ʹ��ʥ����Ϊ���ǵĲ�������
	//string filename = "bible.txt";
	//vector<string> words;
	//if (FileOps::readFile(filename, words)) {

	//	cout << "There are totally " << words.size() << " words in " << filename << endl;
	//	cout << endl;

	//	
	//	// ����BST
	//	time_t startTime = clock();

	//	// ͳ��ʥ�������дʵĴ�Ƶ
	//	// ע�������Ƶͳ�Ʒ���Լ�ª��û�п��Ǻܶ��ı������е���������
	//	// ������ֻ�����ܲ�����
	//	BST<string, int> bst;
	//	for (auto iter = words.begin(); iter != words.end(); iter++) {
	//		int* res = bst.search(*iter);
	//		if (res == nullptr)
	//			bst.insert(*iter, 1);
	//		else
	//			(*res)++;
	//	}

	//	// ���ʥ����godһ�ʳ��ֵ�Ƶ��
	//	if (bst.contain("god"))
	//		cout << "'god' : " << *bst.search("god") << endl;
	//	else
	//		cout << "No word 'god' in " << filename << endl;

	//	time_t endTime = clock();

	//	cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC
	//		<< " s." << endl;
	//	cout << endl;


	//	// ����˳����ұ� SST
	//	startTime = clock();

	//	// ͳ��ʥ�������дʵĴ�Ƶ
	//	// ע�������Ƶͳ�Ʒ���Լ�ª��û�п��Ǻܶ��ı������е���������
	//	// ������ֻ�����ܲ�����
	//	SequenceST<string, int> sst;
	//	for (auto iter = words.begin(); iter != words.end(); iter++) {
	//		int* res = sst.search(*iter);
	//		if (res == nullptr)
	//			sst.insert(*iter, 1);
	//		else
	//			(*res)++;
	//	}

	//	// ���ʥ����godһ�ʳ��ֵ�Ƶ��
	//	if (sst.contain("god"))
	//		cout << "'god' : " << *sst.search("god") << endl;
	//	else
	//		cout << "No word 'god' in " << filename << endl;

	//	endTime = clock();

	//	cout << "SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC
	//		<< " s." << endl;
	//}


	// ���Զ�����������ǰ�к������

	srand(time(nullptr));
	BST<int, int> bst;

	// ȡn��ȡֵ��Χ��[0...m)����������Ž�������������
	int N = 10;
	int M = 100;
	for (int i = 0; i < N; i++) {
		int key = rand() % M;
		// Ϊ�˺�����Է��㣬����valueֵ��keyֵһ��
		int value = key;
		cout << key << " ";
		bst.insert(key, value);
	}
	cout << endl;

	// ���Զ�����������size()
	cout << "size: " << bst.size() << endl;
	cout << endl;

	// ���Զ�����������ǰ����� preOrder
	cout << "preOrder: " << endl;
	bst.preOrder();
	cout << endl;

	// ���Զ������������������ inOrder
	cout << "inOrder: " << endl;
	bst.inOrder();
	cout << endl;

	// ���Զ����������ĺ������ postOrder
	cout << "postOrder: " << endl;
	bst.postOrder();
	cout << endl;

	// ���Զ����������Ĳ������ levelOrder
	cout << "levelOrder: " << endl;
	bst.levelOrder();
	cout << endl;

	return 0;
}