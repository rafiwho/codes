#include <bits/stdc++.h>
using namespace std;

typedef struct Stack {
    int data;
    struct Stack*next;
} Stack;

Stack *top = NULL;

void insert(int data) {
    Stack *temp = (Stack*)malloc(sizeof(Stack));
    if (temp == NULL) {
        exit(0);
    }
    temp->data = data;
    temp->next = top;
    top = temp;
}

void pop() {
    if (top == nullptr) {
        exit(0);
    }
    Stack *temp = top;
    top = top->next;
    free(temp);
}

bool IS_EMPTY() {
    return top == nullptr;
}

void PRINT() {
    Stack *temp = top;
    while (temp != nullptr) {
        cout << temp->data << '\n';
        temp = temp->next;
    }
}

void tcase() {
    for (int i = 0; i < 10; ++i) {
        insert(i);
    }
    cout << boolalpha << IS_EMPTY() << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;

    while (t-- > 0)
        tcase();
}