//quiz2.cpp

#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>

void main() {

	int rand_num[2];
	int sum = 0;
	int user_answer;

	srand((unsigned)time(NULL));
	for (int i = 0; i < 2; i++) {
		rand_num[i] = 10 + rand() % 90;;
	}

	sum = rand_num[0] + rand_num[1];

	while (1) {

		cout << rand_num[0] << " + " << rand_num[1] << " = ";
		cin >> user_answer;

		if (sum == user_answer) {
			cout << "Correct!" << endl;
			break;
		}
		else {
			cout << "Wrong answer! Try again." << endl;

			//입력 버퍼 비우기
			cin.clear();
			cin.ignore();
		}

	} //while - end

}
