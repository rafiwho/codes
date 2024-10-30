#include <bits/stdc++.h>
using namespace std;

typedef struct Q {
	int data;
	Q*next;
} Q;
Q *f = nullptr;
Q *r = nullptr;

void push(int data) {
	Q *new_node = (Q*)malloc(sizeof(Q));
	if (new_node == nullptr) {
		exit(0);
	}
	new_node->data = data;
	new_node->next = nullptr;
	if (f == r && f == nullptr) {
		f = new_node;
		r = new_node;
	} else {
		r->next = new_node;
		r = new_node;
	}
}

void deq() {
	if (f == r && f == nullptr) {
		return ;
	}
	Q *temp = f;
	f = f->next;
	free(temp);
}
void trav() {
	Q *temp = f;
	while (temp != nullptr) {
		cout << temp->data << '\n';
		temp = temp->next;
	}
}
void tcase() {
	for (int i = 0; i < 10; ++i) {
		push(i);
	}
	deq();
	deq();
	trav();

}
bool IS_EMAPTY() {
	return f == r && f == nullptr;
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}