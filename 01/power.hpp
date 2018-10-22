#pragma once
int power(int x, unsigned p) {
	int answer = 1;
	for(int i = p ; 0 < i; --i)
		answer *= x;
	return answer;
}
