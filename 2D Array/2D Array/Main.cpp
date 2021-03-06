// Includes n Usings
#include <iostream>
using std::cout; using std::cin;
#include <vector>
using std::vector;
#include <chrono>
#include <thread>
// Variables
vector<vector<int>> grid2d;
int base, length;
char goOn;
// Entry Point
int main() {
	do {
		// Get base from user
		cout << "+---------------------------------------------+\n"
			<< "| What number would you like your base to be? |\n"
			<< "+---------------------------------------------+\n";
		cin >> base;
		// Validate input
		while (!(base > -10 && base < 10) && !(base == 0)) {
			cout << "+----------------------------------------+\n"
				<< "| Invalid input, please enter an integer |\n"
				<< "+----------------------------------------+\n";
			cin >> base;
		}
		// Get length from user
		cout << "+----------------------------------------+\n"
			<< "| How long do you want each array to be? |\n"
			<< "+----------------------------------------+\n";
		cin >> length;
		// Validate input
		while (!(length > 0 && length < INT_MAX)) {
			cout << "+-----------------------------------------------+\n"
				<< "| Invalid input, please enter a positive integer |\n"
				<< "+------------------------------------------------+\n";
			cin >> length;
		}
		// Generate cube
		grid2d.resize(length, vector<int>(length));
		// Fill cube
		for (int i = 0; i < length; ++i) {
			for (int j = 0; j < length; ++j) {
				grid2d[i][j] = (((i + 1) * base)*((j + 1) * base));
			}
		}
		// Print cube
		for (int i = 0; i < length; ++i) {
			for (int j = 0; j < length; ++j) {
				if (grid2d[i][j] == 0) {
					// Skip this print
				}
				else {
					cout << "[" << (1 + i) * base << "] * "
						<< "[" << (1 + j) * base << "] = "
						<< grid2d[i][j] << "\n";
				}
				std::this_thread::sleep_for(std::chrono::milliseconds(1));
			}
		}
		// Ask user if they would like to try again
		cout << "+---------------------------------------+\n"
			 << "| Would you like to go again? ( y / n ) |\n"
			 << "+---------------------------------------+\n";
		cin >> goOn;
		goOn = tolower(goOn);
		// Validate input
		while (goOn != 'y' && goOn != 'n') {
			cout << "+----------------------------------------------+\n"
				<< "| Invalid input, please enter a valid character |\n"
				<< "+-----------------------------------------------+\n";
			cin >> goOn;
			goOn = tolower(goOn);
		}
		// Hold System
		system("pause");
	} while (goOn == 'y');
}