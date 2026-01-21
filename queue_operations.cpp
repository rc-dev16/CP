#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

void enqueueElement() {
    int value;
    cout << "Enter the value to enqueue: ";
    cin >> value;
    q.push(value);
    cout << "Element " << value << " enqueued successfully.\n";
}

void dequeueElement() {
    if (q.empty()) {
        cout << "Queue is empty. Cannot dequeue.\n";
        return;
    }
    int front = q.front();
    q.pop();
    cout << "Element " << front << " dequeued successfully.\n";
}

void frontElement() {
    if (q.empty()) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Front element: " << q.front() << endl;
}

void rearElement() {
    if (q.empty()) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Rear element: " << q.back() << endl;
}

void isEmpty() {
    if (q.empty()) {
        cout << "Queue is empty.\n";
    } else {
        cout << "Queue is not empty.\n";
    }
}

void size() {
    cout << "Queue size: " << q.size() << endl;
}

void displayQueue() {
    if (q.empty()) {
        cout << "Queue elements: [empty]\n";
        return;
    }
    
    queue<int> temp = q;
    
    cout << "Queue elements (front to rear): ";
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
}

int main() {
    int option;
    
    while (true) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Front Element\n4. Rear Element\n5. Is Empty\n6. Size\n7. Display Queue\n8. Exit\n";
        cout << "Enter your option: ";
        cin >> option;
        
        switch (option) {
            case 1:
                enqueueElement();
                break;
                
            case 2:
                dequeueElement();
                break;
                
            case 3:
                frontElement();
                break;
                
            case 4:
                rearElement();
                break;
                
            case 5:
                isEmpty();
                break;
                
            case 6:
                size();
                break;
                
            case 7:
                displayQueue();
                break;
                
            case 8:
                cout << "Exiting...\n";
                return 0;
                
            default:
                cout << "Invalid option\n";
                break;
        }
    }
    
    return 0;
}
