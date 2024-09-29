#include <iostream>
#include <vector>
#include <cctype>
#include <stdio.h>
#include <math.h>  
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    vector<int> numList;
    bool programShouldRun = true;
    char userInput;
    int newNumber;

    do {
        cout << "P - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display the mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "Q - Quit" << endl << endl;

        cout << "Enter your choice: ";
        cin >> userInput;

        userInput = tolower(userInput);

        switch (userInput) {
            case 'q':
                
                cout << "\nGoodbye...\n" << endl; 
            
                programShouldRun = false;
                break;
            case 'p': {
                if (numList.empty()) {
                    cout << "[] - The list is empty" << endl;
                } else {
                    cout << "[ ";
                    for (int i : numList)
                        cout << i << ' ';
                    cout << "]" << endl;
                }
                break;
            }

            case 'a': {
                cout << "Enter an integer to add to the list: ";
                cin >> newNumber;
                cout << "\n";

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter a VALID integer!! \n" << endl;
                    break;
                }

                numList.push_back(newNumber);
                cout << newNumber << " added \n\n";
                break;
            }

            case 'm': {
                if (numList.empty()) {
                    cout << "\nAdd numbers before getting the average \n" << endl;
                } else {
                    double mean = accumulate(numList.begin(), numList.end(), 0.0) / numList.size();
                    cout << "\nThe mean is: " << mean << "\n" << endl;
                }
                break;
            }

            case 's': {
                if (numList.empty()) {
                    cout << "\nAdd numbers before getting the smallest number \n" << endl;
                } else {
                    int smallest = *min_element(numList.begin(), numList.end());
                    cout << "\nThe smallest number is: " << smallest << "\n" << endl;
                }
                break;
            }

            case 'l': {
                if (numList.empty()) {
                    cout << "\nAdd numbers before getting the biggest number \n" << endl;
                } else {
                    int maxNumber = *max_element(numList.begin(), numList.end());
                    cout << "\nThe biggest number is: " << maxNumber << "\n" << endl;
                }
                break;
            }

            default:
                cout << "Unknown selection, please try again..." << endl;
        }

    } while (programShouldRun);

    return 0;
}
