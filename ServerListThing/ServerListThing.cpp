#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void printVals(string servName, int numOfTimes, int startPortVal) {
	cout << "Address: " << servName << endl;
	cout << "Starting Port Value: " << startPortVal << endl;
	cout << "Number of Servers: " << numOfTimes << endl;
}


string newServName() {
	string newVal;
	cout << "Enter New Address: " << endl;
	cin >> newVal;
	return newVal;
}

int newPortVal() {
	int newVal;
	cout << "Enter New Starting Port Value: " << endl;
	cin >> newVal;
	return newVal;
}

int newAmountVal() {
	int newVal;
	cout << "Enter Amount Of Servers: " << endl;
	cin >> newVal;
	return newVal;
}

int main(int argc, char* argv[]) {
	ofstream myfile;
	ifstream inFS;
	int i;
	if (argc == 4) {
		myfile.open("servlist.txt");
		for (i = 0; i < stoi(argv[3]); i++) {
			myfile << "server" << stoi(argv[2]) + i << " = " << argv[1] << ":" << stoi(argv[2]) + i << "\n";
		}
		cout << "Done";
		myfile.close();
		return 0;
	}
	if (argc > 1) {
		cout << "You're probably seeing this if you don't have 3 arguments. Make sure that\n(1) The Server Address is the first argument\n(2) The Starting Port number is the second\n(3) The Number Of Servers to Generate is the third";
		return 0;
	}
	string servName = "example.com";
	int numOfTimes = 10;
	int startPortVal = 14242;
	int curVal = 69;
	system("cls");

	cout << "Welcome to the Clone Hero Online Server List Generator" << endl;
	cout << "---------------- Made By Davey Dollar ----------------" << endl << endl;
	cout << "Only like 1 person would want to use this so yea" << endl << endl;
	
	while (curVal != 0) {

		cout << "Choose one of the following options: " << endl;
		cout << "(0) - End Program" << endl; 
		cout << "(1) - Enter New Server Address (Current Value: " << servName << ")\n";
		cout << "(2) - Enter Starting Port Value (Current Value: " << startPortVal << ")\n";
		cout << "(3) - Enter Amount Of Servers To Generate (Current Value: " << numOfTimes << ")\n";
		cout << "(4) - Load Data From File\n";
		cout << "(5) - Save Current Values To File\n";
		cin >> curVal;
		cout << endl;
		if (curVal == 1) {
			servName = newServName();
		}
		else if (curVal == 2) {
			startPortVal = newPortVal();
		}
		else if (curVal == 3) {
			numOfTimes = newAmountVal();
		}
		else if (curVal == 4) {
			cout << "Make sure you have your 'input.txt' file properly formatted as such:\n\n";
			cout << "address=www.example.com\nstartport=14242\nnumtimes=10\n";
			cout << "(obviously replacing with your own values)\n\n";
			cout << "Are you ready to import? (y/n)\n";
			char val = 'n';
			cin >> val;
			if (val == 'y') {
				inFS.open("input.txt");
				string newVal;
				
				while (inFS >> newVal) {
					if (newVal.find("address=") != string::npos) {
						servName = newVal.substr(8, newVal.length() - 1);
					}
					else if (newVal.find("startport=") != string::npos) {
						startPortVal = stoi(newVal.substr(10, newVal.length() - 1));
					}
					else if (newVal.find("numtimes=") != string::npos) {
						numOfTimes = stoi(newVal.substr(9, newVal.length() - 1));
					}
				}
				inFS.close();
			}
		}
		else if (curVal == 5) {
			cout << "Before you save, make sure all your values are correct: " << endl << endl;
			printVals(servName, numOfTimes, startPortVal);
			cout << endl << "Is this correct? (y/n)" << endl;
			char val = 'n';
			cin >> val;
			if (val == 'y') {
				myfile.open("servlist.txt");
				cout << "Would you like to print out the progress? (y/n)\n(This will take a lot longer to do but there's only a substancial difference if your amount of servers is greater than 1000)" << endl;
				cin >> val;
				if (val == 'y') {
					for (i = 0; i < numOfTimes; ++i) {
						myfile << "server" << startPortVal + i << " = " << servName << ":" << startPortVal + i << "\n";
						cout << "(" << i+1 << " out of " << numOfTimes << ") - server" << startPortVal + i << " = " << servName << ":" << startPortVal + i << "\n";
					}
				}
				else {
					for (i = 0; i < numOfTimes; ++i) {
						myfile << "server" << startPortVal + i << " = " << servName << ":" << startPortVal + i << "\n";
					}
				}
				myfile.close();
				cout << "Done" << endl;
				system("pause");
			}
		}
		system("cls");
	}
	return 0;
}
