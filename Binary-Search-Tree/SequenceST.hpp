#ifndef BINARYSEARCHTREE_SEQUENCEST_H
#define BINARYSEARCHTREE_SEQUENCEST_H

#include <iostream>
#include <cassert>

using namespace std;

// ˳����ұ�
template<typename Key, typename Value>
class SequenceST {

private:
	// ˳����ұ��еĽڵ�Ϊ˽�нṹ�壬��粻��Ҫ�˽�˳����ұ��нڵ�ľ���ʵ��
	// ���ǵ�˳����ұ��ڲ�������һ������
	struct Node {
		Key key;
		Value value;
		Node* next;

		Node(Key key, Value value) :next(nullptr) {
			this->key = key;
			this->value = value;
		}
	};

	Node* head; // ��ͷ
	int count;	// ˳����ұ��еĽڵ����

public:
	// ���캯��
	SequenceST() :head(nullptr) {
		count = 0;
	}

	// ��������
	~SequenceST() {
		while (head != nullptr) {
			Node* node = head;
			head = head->next;
			delete node;
			count--;
		}

		assert(head == nullptr && count == 0);
	}

	// ����˳����ұ��еĽڵ����
	int size() const {
		return count;
	}

	// ����˳����ұ��Ƿ�Ϊ��
	bool isEmpty() {
		return count == 0;
	}

	// ��˳����ұ��в���һ���µ�(key, value)���ݶ�
	void insert(Key key, Value value) {

		// ����һ������˳������Ƿ������ͬ��key
		Node* node = head;
		while (node != nullptr) {
			// ����˳����з�����ͬ����Сkey�Ľڵ�
			// ��ǰ�ڵ㲻��Ҫ���룬����key��Ӧ��valueֵ���º󷵻�
			if (node->key == key) {
				node->value = value;
				return;
			}
			node = node->next;
		}

		// ��˳�����û��ͬ����С��key���򴴽��½ڵ㣬���½ڵ�ֱ�Ӳ��ڱ�ͷ
		Node* newNode = new Node(key, value);
		newNode->next = head;
		head = newNode;
		count++;
	}

	// �鿴˳������Ƿ������ֵΪkey�Ľڵ�
	bool contain(Key key) {
		
		Node* node = head;
		while (node != nullptr) {
			if (key == node->key)
				return true;
			node = node->next;
		}
		return false;
	}

	// ��˳����ұ��в���key����Ӧ��value����value�����ڣ��򷵻�nullptr
	Value* search(Key key) {

		Node* node = head;
		while (node != nullptr) {
			if (node->key == key)
				return &(node->value);
			node = node->next;
		}
		return nullptr;
	}

	// ��˳����ұ���ɾ��(key, value)����Ӧ�Ľڵ�
	void remove(Key key) {

		if (head == nullptr)
			return;

		// �����ɾ���Ľڵ����ͷ�ڵ㣬����Ҫ���⴦��
		// ˼����������������ʹ��ʲô������ȥ���⴦��ͷ�ڵ�����������
		// ���˻ش�ͷ�ڵ�������򲻴洢�κ���Ϣ��ָ����洢ָ���һ���ڵ��ָ��
		if (key == head->key) {
			Node* delNode = head;
			head = head->next;
			delete delNode;
			count--;
			return;
		}

		Node* node = head;
		while (node->next != nullptr && node->next->key != key)
			node = node->next;

		if (node->next != nullptr) {
			Node* delNode = node->next;
			node->next = delNode->next;
			delete delNode;
			count--;
			return;
		}
	}
};
#endif // !BINARYSEARCHTREE_SEQUENCEST_H
