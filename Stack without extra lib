#include <iostream>
#include <string>
using namespace std;

class Stack {
protected:
    char *data;
    int capacity;
    int headidx;
public:
    Stack(int size) : capacity(size), headidx(-1) {
        data = new char[size];
    }
    ~Stack() { delete[] data; }

    void push(char x) {
        if (headidx>=capacity) {
            return;
        }
        else {
            data[++headidx] = x;
        }
    }
    void pop() {
        if (headidx == -1) { return; }
        else {
            headidx--;
        }
    }
    char top() {
        return data[headidx];
        cout << "Head: " << data[headidx] << endl;
    }
    bool isEmpty() {
        if (headidx == -1) return true;
        return false;
    }
};

bool prover(const string& line) {
    Stack st(line.length());
    for (int i = 0; i < line.length(); i++) {
        char c = line[i];
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        }
        else if (c==')') {
            if (st.isEmpty()) {
                cout << "Uneccessary bracket" << endl;
                return false;
            }
            if (st.top() != '(') {
                cout<< "Nonconforming bracket. Need ')'" << endl;
                return false;
            }
            st.pop();
        }
        else if (c == ']') {
            if (st.isEmpty()) {
                cout << "Uneccessary bracket" << endl;
                return false;
            }
            if (st.top() != '[') {
                cout << "Nonconforming bracket. Need ']'" << endl;
                return false;
            }
            st.pop();
        }
        else if (c == '}') {
            if (st.isEmpty()) {
                cout << "Uneccessary bracket" << endl;
                return false;
            }
            if (st.top() != '{') {
                cout << "Nonconforming bracket. Need '}'" << endl;
                return false;
            }
            st.pop();
        }
    }
    if (!st.isEmpty()) {
        cout<< "Need one more bracket for "<< st.top() << endl;
        return false;
    }
    cout << "Correct line" << endl;
    return true;
}

int main() {

    string line = "{{}}[]";
    prover(line);

    return 0;
}
