//Двозвязний список
#include <iostream>
using namespace std;
class Node {
	int val;
public:
	Node* next;
	Node* prev;
	Node(int v) :val(v) { next = nullptr; prev = nullptr; }
	int GetValue() const { return val; }
	void SetValue(int v) { val = v; }

};
//////////////////////////////////
class List {
	Node* head;
	Node* tail;
	Node* AddressNode(int p);
	int count;
public:
	List() :head(0), tail(0), count(0) {}
	void push_tail(int v);
	void push_head(int v);
	void Print();
	int GetCount() const { return count; }
	void insert(int v, int p);
	void del_head();
	void del_tail();
	void clear();
};
Node* List::AddressNode(int p)
{
	Node* temp = head;
	int k = 0;
	while (temp)
	{
		if (p == k++) break;
		temp = temp->next;
	}
	return temp;
}
void List::push_tail(int v)
{
	Node* node = new Node(v);
	if (!head)
		head = node;
	else
	{
		node->prev = tail;
		tail->next = node;
	}
	tail = node;
	count++;
}
void List::push_head(int v)
{
	Node* node = new Node(v);
	if (!head)
		tail = node;
	else
	{
		node->next = head;
		head->prev = node;
	}
	head = node;
	count++;
}
void List::Print()
{
	Node* temp = head;
	while (temp)
	{
		cout << temp->GetValue() << "\t";
		temp = temp->next;
	}
	cout << endl;
}
void List::insert(int v, int p)
{
	if (p == 0) {
		push_head(v);
		return;
	}
	if (p == count) {
		push_tail(v);
		return;
	}
	Node* temp = AddressNode(p - 1);
	if (!temp || p<0 || p>count)return;
	Node* node = new Node(v);
	node->next = temp->next;
	node->prev = temp;
	temp->next = node;
	node->next->prev = node;
	count++;
}
void List::del_head()
{
	Node* del = head;
	if (head) {
		head = head->next;
		if (head)
			head->prev = 0;
		delete del;
		count--;
	}
	else
		tail = 0;
}
void List::del_tail()
{
	if (tail) {
		Node* del = tail;
		tail = tail->prev;
		if (tail)
			tail->next = 0
		else
			head = 0;
		delete del
			count--;
	}
}
List::~List()
{
	clear();
}

int main()
{
	List A;
	A.push_head(30);
	A.push_tail(50);
	A.push_tail(10);
	A.push_tail(20);
	A.Print();
	A.insert(15, 0);
	A.Print();
	A.del_head();
	A.Print();
}