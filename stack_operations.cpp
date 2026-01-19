#include <iostream>
#include <stack>
using namespace std;

stack<int> st;

void pushElement() {
    int value;
    cout << "Enter the value to push: ";
    cin >> value;
    st.push(value);
    cout << "Element " << value << " pushed successfully.\n";
}

void popElement() {
    if (st.empty()) {
        cout << "Stack is empty. Cannot pop.\n";
        return;
    }
    int top = st.top();
    st.pop();
    cout << "Element " << top << " popped successfully.\n";
}

void topElement() {
    if (st.empty()) {
        cout << "Stack is empty.\n";
        return;
    }
    cout << "Top element: " << st.top() << endl;
}

void isEmpty() {
    if (st.empty()) {
        cout << "Stack is empty.\n";
    } else {
        cout << "Stack is not empty.\n";
    }
}

void size() {
    cout << "Stack size: " << st.size() << endl;
}

void displayStack() {
    if (st.empty()) {
        cout << "Stack elements: [empty]\n";
        return;
    }
    
    stack<int> temp = st;
    stack<int> display;
    
    while (!temp.empty()) {
        display.push(temp.top());
        temp.pop();
    }
    
    cout << "Stack elements (top to bottom): ";
    while (!display.empty()) {
        cout << display.top() << " ";
        display.pop();
    }
    cout << endl;
}

int main() {
    int option;
    
    while (true) {
        cout << "\n1. Push\n2. Pop\n3. Top Element\n4. Is Empty\n5. Size\n6. Display Stack\n7. Exit\n";
        cout << "Enter your option: ";
        cin >> option;
        
        switch (option) {
            case 1:
                pushElement();
                break;
                
            case 2:
                popElement();
                break;
                
            case 3:
                topElement();
                break;
                
            case 4:
                isEmpty();
                break;
                
            case 5:
                size();
                break;
                
            case 6:
                displayStack();
                break;
                
            case 7:
                cout << "Exiting...\n";
                return 0;
                
            default:
                cout << "Invalid option\n";
                break;
        }
    }
    
    return 0;
}
