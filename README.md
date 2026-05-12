# Лабораторная работа №3
Выполнила Пермякова Екатерина Алексеевна ИДБ-25-02

# Проверка скобочных последовательностей (Stack)
## Описание проекта
Программа на C++ для проверки корректности скобочных последовательностей с использованием структуры данных 'Stack'.
Поддерживаемые скобки: (), [], {}

## Идея решения
Стек работает по принципу LIFO (Last In - First Out), что идеально подходит для проверки вложенных скобок: последняя открытая скобка должна закрываться первой.

## Реализация кода:
```cpp
#include <iostream>
#include <string> 
#include <stack>
using namespace std;

bool proverka(const string& line) {
	stack<char> stack;
	for (int i = 0; i < line.length(); i++) {
		char c = line[i];
		if (c == '(' || c == '[' || c == '{') {
			stack.push(c); //кладем в стек
		}
		else if (c == ')') {
			if (stack.empty()) { //если стек пуст
				cout << "Error: unnecessary bracket " << c << endl;
				return false;
			}
			if (stack.top() != '(') { //если верхний элемент не (
				cout << "Error: nonconformig bracket " << c << endl;
				return false;
			}
			stack.pop(); //удаление верхнего элемента
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

```
## Тесты
```cpp
int main() {    
    cout << "1. Проверка: ()[]{}" << endl;
    proverka("()[]{}");
    cout << endl;
    
    cout << "2. Проверка: ([)]" << endl;
    proverka("([)]");
    cout << endl;
    
    cout << "3. Проверка: (()" << endl;
    proverka("(()");
    cout << endl;
    
    cout << "4. Проверка: ())" << endl;
    proverka("())");
    cout << endl;
    
    cout << "5. Проверка: {[(())]}" << endl;
    proverka("{[(())]}");
    cout << endl;
    
    cout << "6. Проверка: ([]{})" << endl;
    proverka("([]){})");
    
    return 0;
}
```

## Результаты

№ |	Входная строка | Результат |
--|----------------|-----------|
1 |	()[]{} | All is good | 
2 |	([)] | Error: nonconformig bracket |
3 |	(()	| Error needs one more bracket |
4 |	())	| Error: unnecessary bracket  |
5 |	{[(())]} | All is good |
6 | ([]{}) | Error: unnecessary bracket  |
