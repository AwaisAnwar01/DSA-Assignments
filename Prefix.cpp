#include<iostream>
using namespace std;
void main() {
	char number[100];
	int opr1 = 0, num1 = 0, num2 = 0;
	
	float operands[100];
	char operations[100];
	cout << "PLEASE ENTER AN EXPRESSION HAVING ARITHMETIC OPERATIONS: ";
	cin >> number;
	cout << endl;
	int i = 0;
	while (number[i] != '\0') {
		while(number[i] >= '0' && number[i] <= '9') {
			opr1 = opr1 * 10;
			opr1 = opr1 + (number[i] - 48);
			i++;
		}
			operands[num2] = opr1;
			opr1 = 0;
			num2++;
			if (number[i] != 0)
				operations[num1] = number[i];
			else
				break;
		num1++;
		i++;
	}
	for (int i = 0; i < num1; i++) {
		cout << "THE OPERATION IS: " << operations[i] <<endl;
	}
	for (int i = 0; i < num2; i++) {
		cout << "THE OPERATORS ARE: " << operands[i]<<endl;
	}
	int t = 0;
	for (t = 0; t < num1;t++) {
		if (operations[t] == '+') {
			operands[t+1] = operands[t] + operands[t + 1];
		}
		else if (operations[t] == '-') {
			operands[t+1] = operands[t] - operands[t + 1];
		}
		else if (operations[t] == '*') {
			operands[t+1] = operands[t] * operands[t + 1];
		}
		else {
			if (operands[t + 1] != 0) {
				operands[t+1] = operands[t] / operands[t + 1];
			}
			else {
				cout << "DIVISION WITH ZERO NOT POSSIBLE....." << endl;
				break;
			}
		}

	}
	cout << "THE ANSWER IS: " << operands[t];
}