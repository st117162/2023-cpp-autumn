#include<iostream>

struct Node {
	int data;
	Node* next;
	Node(int data, Node* next = nullptr) : data(data), next(next) {}
	Node(const Node& node) : data(node.data), next(nullptr) {}
	~Node() { data = 0; next = nullptr; }
	friend std::ostream& operator<<(std::ostream& stream, Node*& node){
		stream << node->data << " ";
		return stream;
	}
};

class LinkedList {
public:
	LinkedList() : head(nullptr) {}
	~LinkedList() { dispose(); }
	int Length();
	bool IsEmpty();
	void PushHead(int data); 
	void Insert(int index, int data);
	void PushTail(int data);
	int PopHead(); 
	int Extract(int index);
	int PopTail();
	int Data(int index);
	void swap(int ia, int ib);
	void sort();
	friend std::ostream& operator<<(std::ostream& stream, const LinkedList& list) {
		Node* tmp = list.head;
		while (tmp != nullptr) {
			stream << tmp << " ";
			tmp = tmp->next;
		}
		return stream;
	}

private:
	Node* head;
	void dispose();
	int PopData(Node* node);
	void InsertNode(int index, Node* node);
	Node* ExtractNode(int index);
	bool IndexValid(int index);
};

int main(int argc, char* argv[]) {
	LinkedList list;
	std::cout << list << std::endl;
	list.PushHead(1);
	std::cout << list << std::endl;
	list.PushTail(3);
	std::cout << list << std::endl;
	list.Insert(1, 2);
	std::cout << list << std::endl;
	list.Insert(3, 4);
	std::cout << list << std::endl << std::endl;
	std::cout << list << std::endl;
	std::cout << list.PopHead() << " ";
	std::cout << list.Extract(1) << " ";
	std::cout << list.PopTail() << " ";
	std::cout << list.Extract(0) << std::endl;
	std::cout << list << std::endl << std::endl;

	list.PushHead(3); list.PushHead(4); list.PushHead(1); list.PushHead(2);
	list.PushHead(7); list.PushHead(5); list.PushHead(8); list.PushHead(6);
	std::cout << list << std::endl;
	list.sort();
	std::cout << list << std::endl;
	return EXIT_SUCCESS;
}

int LinkedList::Length() {
	int len = 0;
	Node* tmp = head;
	while (tmp != nullptr){
		tmp = tmp->next;
		++len;
	}
	return len;
}

bool LinkedList::IsEmpty() {
	return head == nullptr;
}

void LinkedList::PushHead(int data) {
	Node* node = new Node(data);
	InsertNode(0, node);
}

void LinkedList::Insert(int index, int data) {
	Node* node = new Node(data);
	InsertNode(index, node);
}

void LinkedList::PushTail(int data) {
	Node* node = new Node(data);
	InsertNode(Length(), node);
}

int LinkedList::PopHead() {
	return PopData(ExtractNode(0));
}

int LinkedList::Extract(int index) {
	return PopData(ExtractNode(index));
}

int LinkedList::PopTail() {
	return PopData(ExtractNode(Length() - 1));
}

int LinkedList::Data(int index) {
	Node* tmp = head;
	for (int i = 0; i < index && tmp != nullptr; ++i) {
		tmp = tmp->next;
	}
	return tmp != nullptr ? tmp->data : 0;
}

void LinkedList::swap(int ia, int ib) {
	if (ia == ib || !IndexValid(ia) || !IndexValid(ib)) {
		return;
	}
	if (ia > ib) {
		swap(ib, ia);
		return;
	}
	Node* nodeA = ExtractNode(ia);
	Node* nodeB = ExtractNode(ib - 1);
	if (nodeA == nullptr || nodeB == nullptr) {
		return;
	}
	InsertNode(ia, nodeB);
	InsertNode(ib, nodeA);
}

void LinkedList::sort() {
	for (int i = Length() - 1; i > 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (Data(j) > Data(j + 1)) {
				swap(j, j + 1);
			}
		}
	}
}

void LinkedList::dispose() {
	while (!IsEmpty()) {
		Node* tmp = head;
		head = head->next;
		delete tmp;
	}
}

int LinkedList::PopData(Node* node) {
	if (node == nullptr) {
		return 0;
	}
	int res = node->data;
	delete node;
	return res;
}

void LinkedList::InsertNode(int index, Node* node) {
	if (index == 0 || head == nullptr) {
		node->next = head;
		head = node;
		return;
	}
	Node* tmp = head;
	for (int i = 0; i < index - 1 && tmp->next != nullptr; ++i)
	{
		tmp = tmp->next;
	}
	node->next = tmp->next;
	tmp->next = node;
}

Node* LinkedList::ExtractNode(int index) {
	if (!IndexValid(index)) {
		return nullptr;
	}

	Node* tmp = head;
	if (index == 0) {
		head = head->next;
		return tmp;
	}
	for (int i = 0; i < index - 1; ++i) {
		tmp = tmp->next;
	}
	Node* res = tmp->next;
	tmp->next = tmp->next->next;
	return res;
}

bool LinkedList::IndexValid(int index)
{
	return (index >= 0 && index < Length());
}
