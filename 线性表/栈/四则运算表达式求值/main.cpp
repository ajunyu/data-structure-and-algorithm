#include <iostream>
#include <string>
#include <stack>
#include <deque>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stack;
using std::deque;

deque<string> infixToPostfix(deque<string> infix) {
	deque<string> postfix;
	stack<string> symbol;

	while (infix.size()) {
		string str = infix.front();
		infix.pop_front();

		char *p;
		double num = strtod(str.c_str(), &p);

		if (!*p) {
			postfix.push_back(std::to_string(num));
		} else {
			switch (*str.c_str()) {
				case '+':
				case '-':
					while (symbol.size() && symbol.top() != "(") {
						string top = symbol.top();
						postfix.push_back(top);
						symbol.pop();
					}
					symbol.push(str);
					break;

				case '*':
				case '/' :
					while (symbol.size() && symbol.top() != "(") {
						string top = symbol.top();
						if (top == "*" || top == "/") {
							postfix.push_back(top);
							symbol.pop();
						} else {
							break;
						}
					}
					symbol.push(str);
					break;
				case '(':
					symbol.push(str);
					break;

				case ')':
					while (symbol.top() != "(") {
						string top = symbol.top();
						postfix.push_back(top);
						symbol.pop();
					}
					symbol.pop();
					break;
			
				default:
					break;
			}
		}
	}

	while (symbol.size()) {
		string top = symbol.top();
		postfix.push_back(top);
		symbol.pop();
	}

	return postfix;
}

double calculate(deque<string> postfix) {
	stack<double> number;

	while (postfix.size()) {
		string front = postfix.front();

		char *p;
		double num = strtod(front.c_str(), &p);

		if (!*p) {
			number.push(num);
		} else {
			double right = number.top();
		number.pop();
		double left = number.top();
		number.pop();

		double result;

		switch (*front.c_str()) {
			case '+':
				result = left + right;
				break;
			case '-':
			result = left - right;
			break;
			case '*':
			result = left * right;
			break;
			case '/':
			result = left / right;
			break;
			default:
				break;
		}

		number.push(result);
		}

		postfix.pop_front();
	}

	double result = number.top();
	number.pop();

	return result;
}

int main()
{
	deque<string> infix;
	deque<string> postfix;

	string s;
	cin >> s; // 5+((1+2)*4)-3, 9+(3-1)*3+10/2, 1.1+1.2

	for (auto i = 0; i < s.length(); i++) {
		if (s.at(i) >= '0' && s.at(i) <= '9') {
			string number(1, s.at(i));

			while (i != s.length() - 1 && (s.at(i + 1) >= '0' && s.at(i + 1) <= '9' || s.at(i + 1) == '.')) {
				number.push_back(s.at(i + 1));
				++i;
			}

			infix.push_back(number);
		} else {
			string symbol(1, s.at(i));
			infix.push_back(symbol);
		}
	}

	for each (auto i in infix) {
		cout << i;
	}
	cout << endl;

	postfix = infixToPostfix(infix);
	for each (auto i in postfix) {
		cout << i;
	}

	cout << endl << calculate(postfix) << endl;

	return 0;
}
