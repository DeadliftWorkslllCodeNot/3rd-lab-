#include <iostream>
#include <string> 
#include <stack>
using namespace std;

bool proverka(const string& line) {
	stack<char> stack;
	for (int i = 0; i < line.length(); i++) {
		char c = line[i];
		if (c == '(' || c == '[' || c == '{') {
			stack.push(c);
		}
		else if (c == ')') {
			if (stack.empty()) {
				cout << "Error: unnecessary bracket " << c << endl;
				return false;
			}
			if (stack.top() != '(') {
				cout << "Error: nonconformig bracket " << c << endl;
				return false;
			}
			stack.pop();
		}

		else if (c == ']') {
			if (stack.empty()) {
				cout << "Error: unnecessary bracket "<<c << endl;
				return false;
			}
			if (stack.top() != '[') {
				cout << "Error: nonconformig bracket " << c << endl;
				return false;
			}
			stack.pop();
		}

		else if (c == '}') {
			if (stack.empty()) {
				cout << "Error: unnecessary bracket " << c << endl;
				return false;
			}
			if (stack.top() != '{') {
				cout << "Error: nonconformig bracket " << c << endl;
				return false;
			}
			stack.pop();
		}
	}
	if (!stack.empty()) {
		cout << "Error needs one more bracket for '"<<stack.top()<<"'" << endl;
		return false;
	}
	cout << "All is good" << endl;
	return true;
}

int main()
{
	cout << "Puts the string: ";

	string line;
	getline(cin, line);
	cout << line << endl;
	
	proverka(line);

	return 0;
}

