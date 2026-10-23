#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <vector>

// stack


//1
bool isBalanced(const std::string& str) {
	std::stack<char> sym;

	for (char k : str) {
		if (k == '{' || k == '[' || k == '(') {
			sym.push(k);
		}
		else {
			if (sym.empty() == true) {
				return false;
			}

			if (k == ')' && sym.top() != '(' || k == ']' && sym.top() != '[' || k == '}' && sym.top() != '{') {
				return false;
			}
			sym.pop();
		}
		
	}
	return sym.empty();
}

//2
int evaluateRPN(const std::vector<std::string>& expr) {
	std::stack<int> st;

	for (const std::string& element : expr) {
		if (element == "+" || element == "-" || element == "*" || element == "/") {
			int right = st.top();
			st.pop();
			int left = st.top();
			st.pop();
			
			if (element == "+") {
				st.push(left + right);
			}
			else if (element == "-") {
				st.push(left - right);
			}
			if (element == "*") {
				st.push(left * right);
			}
			if (element == "/") {
				st.push(left / right);
			}
		}
		else {
			st.push(std::stoi(element));
		}
	}
	return st.top();
}

//3
void reverseString(std::string& str) {
	std::stack<char> st;

	for (char p : str) {
		st.push(p);
	}
	for (size_t i = 0; i < str.length(); i++) {
		str[i] = st.top();
		st.pop();
	}
}


//queue 

 
//1.hot potato
std::string hotPotato(const std::vector<std::string>& players, int k) {
	std::queue<std::string> q;
	for (int i = 0; i < players.size(); i++) {
		q.push(players[i]);
	}

	while(q.size() > 1) {
		for (int i = 0; i < k; i++) {
			q.push(q.front());
			q.pop();
		}
		std::cout << "First player: " << q.front() << std::endl;
		q.pop();
	}
	return q.front();

}

//2
std::vector<std::string> generateBinaryNumbers(int N) {
	std::vector<std::string> result;
	std::queue<std::string> q;

	q.push("1");

	for (int i = 0; i < N; i++) {
		std::string current = q.front();
		q.pop();

		result.push_back(current);

		q.push(current + "0");
		q.push(current + "1");
	}
	return result;
}

//3
int timeRequiredToBuy(std::vector<int>& tickets, int k) {
	int time = 0;
	std::queue<std::pair<int, int>> q;

	for (int i = 0; i < tickets.size(); i++) {
		q.push({i, tickets[i]});
	}

	while (!q.empty()) {
		std::pair<int, int> person = q.front();
		q.pop();
		time++;
		person.second--;
		if (person.second > 0) {
			q.push(person);
		}
		else if (person.first == k && person.second == 0) {
			return time;
		}
	}	
	return 0;
}

int main() {

	//skobki
	std::cout << isBalanced("({[]})") << '\n';
	std::cout << isBalanced("([)]") << '\n';
	std::cout << isBalanced("{[}]") << '\n';

	//rpn
	std::vector<std::string> expr = { "2", "1", "+", "3", "*" };
	std::cout << evaluateRPN(expr) << '\n';  // 9
	// (2 + 1) * 3 = 9


	//razvorot
	std::string s = "Hello";
	reverseString(s);
	std::cout << s << '\n';  // olleH

	//potato check
	std::vector<std::string> players = { "Alice", "Bob", "Charlie", "David" };
	std::cout << hotPotato(players, 3) << '\n';

	//binary
	auto result = generateBinaryNumbers(5);
	for (const std::string& s : result) {
		std::cout << s << " " << std::endl;
	}
	// result: {"1", "10", "11", "100", "101"}

	//ochered
	std::vector<int> tickets1 = { 2, 3, 2 };
	std::cout << timeRequiredToBuy(tickets1, 2) << '\n';  // 6


	std::vector<int> tickets2 = { 5, 1, 1, 1 };
	std::cout << timeRequiredToBuy(tickets2, 0) << '\n';  // 8
	// человек 0 должен купить 5 билетов, остальные по 1


	return 0;
}