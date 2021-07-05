#include <set>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	set<int> s;
	for (auto i : operations) {
		int num;
		if (i[0] == 'I') {
			num = stoi(i.substr(2));
			s.insert(num);
		}
		else {
			if (i[2] == '-') {
				if (s.size() > 0) s.erase(s.begin());
			}
			else {
				if (s.size() > 0) s.erase(--s.end());
			}
		}
	}

	if (s.size() == 0) {
		return { 0, 0 };
	}
	else {
		return { *s.rbegin(), *s.begin() };
	}
}
