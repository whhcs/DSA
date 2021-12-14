#ifndef BINARYSEARCHTREE_SEQUENCEST_H
#define BINARYSEARCHTREE_SEQUENCEST_H

#include <iostream>
#include <cassert>

using namespace std;

// 顺序查找表
template<typename Key, typename Value>
class SequenceST {

private:
	// 顺序查找表中的节点为私有结构体，外界不需要了解顺序查找表中节点的具体实现
	// 我们的顺序查找表，内部本质是一个链表
	struct Node {
		Key key;
		Value value;
		Node* next;

		Node(Key key, Value value) :next(nullptr) {
			this->key = key;
			this->value = value;
		}
	};

	Node* head; // 表头
	int count;	// 顺序查找表中的节点个数

public:
	// 构造函数
	SequenceST() :head(nullptr) {
		count = 0;
	}

	// 析构函数
	~SequenceST() {
		while (head != nullptr) {
			Node* node = head;
			head = head->next;
			delete node;
			count--;
		}

		assert(head == nullptr && count == 0);
	}

	// 返回顺序查找表中的节点个数
	int size() const {
		return count;
	}

	// 返回顺序查找表是否为空
	bool isEmpty() {
		return count == 0;
	}

	// 向顺序查找表中插入一个新的(key, value)数据对
	void insert(Key key, Value value) {

		// 查找一下整个顺序表，看是否存在相同的key
		Node* node = head;
		while (node != nullptr) {
			// 若在顺序表中发现了同样大小key的节点
			// 则当前节点不需要插入，将该key对应的value值更新后返回
			if (node->key == key) {
				node->value = value;
				return;
			}
			node = node->next;
		}

		// 若顺序表中没有同样大小的key，则创建新节点，将新节点直接插在表头
		Node* newNode = new Node(key, value);
		newNode->next = head;
		head = newNode;
		count++;
	}

	// 查看顺序表中是否包含键值为key的节点
	bool contain(Key key) {
		
		Node* node = head;
		while (node != nullptr) {
			if (key == node->key)
				return true;
			node = node->next;
		}
		return false;
	}

	// 在顺序查找表中查找key所对应的value，若value不存在，则返回nullptr
	Value* search(Key key) {

		Node* node = head;
		while (node != nullptr) {
			if (node->key == key)
				return &(node->value);
			node = node->next;
		}
		return nullptr;
	}

	// 在顺序查找表中删除(key, value)所对应的节点
	void remove(Key key) {

		if (head == nullptr)
			return;

		// 如果待删除的节点就是头节点，则需要特殊处理
		// 思考：对于链表，可以使用什么技术不去特殊处理头节点的特殊情况？
		// 个人回答：头节点的数据域不存储任何信息，指针域存储指向第一个节点的指针
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
