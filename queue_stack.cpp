#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

stack<int> s1, s2;

void enqueue(int x) {
    s1.push(x);
}

int dequeue() {
    if (s1.empty() && s2.empty()) {
        cout << "Queue is empty\n";
        return -1;
    }

    if (s2.empty()) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

    int front = s2.top();
    s2.pop();
    return front;
}

int frontelement() {
    if (s1.empty() && s2.empty()) {
        cout << "Queue is empty\n";
        return -1;
    }

    if (s2.empty()) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

    return s2.top();
}

bool isEmpty() {
    return s1.empty() && s2.empty();
}

void printQueue() {
    if (isEmpty()) {
        cout << "Queue elements: [empty]\n";
        return;
    }

    stack<int> a = s1, b = s2;
    vector<int> ans;

    while (!b.empty()) {
        ans.push_back(b.top());
        b.pop();
    }
    reverse(ans.begin(), ans.end());

    vector<int> temp;
    while (!a.empty()) {
        temp.push_back(a.top());
        a.pop();
    }
    reverse(temp.begin(), temp.end());

    for (int x : temp) ans.push_back(x);

    cout << "Queue elements: ";
    for (int x : ans) cout << x << " ";
    cout << endl;
}

int main() {
    int option, value;

    while (true) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Front Element\n4. Is Empty\n5. Exit\n";
        cout << "Enter your option: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter the value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;

            case 2: {
                int x = dequeue();
                if (x != -1) cout << "Dequeued element: " << x << endl;
                break;
            }

            case 3: {
                int x = frontelement();
                if (x != -1) cout << "Front element: " << x << endl;
                break;
            }

            case 4:
                cout << (isEmpty() ? "Queue is empty\n" : "Queue is not empty\n");
                break;

            case 5:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid option\n";
                break;
        }

        printQueue();
    }

    return 0;
}
