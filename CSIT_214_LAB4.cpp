#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

// Merges two files into one and sorts them
void mergeFiles(ifstream& inStream1, ifstream& inStream2, ofstream& outStream) {
    int num1, num2;
    // Read number from each file
    inStream1 >> num1;
    inStream2 >> num2;
    // Merge two files
    while (inStream1 || inStream2) {
        if (!inStream2 || (inStream1 && num1 <= num2)) {
            outStream << num1 << endl; // Write num1 to the output file
            inStream1 >> num1; // Read the next number from file1
        } else {
            outStream << num2 << endl; // Write num2 to the output file
            inStream2 >> num2; // Read the next number from file2
        }
    }
}
//main function
int main() {
    ifstream inStream1, inStream2; //declare variables
    ofstream outStream; //declare variables

    // Ask user for file names
    string file1, file2, outputFile;
    cout << "Enter first input file: ";
    cin >> file1;
    cout << "Enter second input file: ";
    cin >> file2;
    cout << "Enter output file: ";
    cin >> outputFile;

    // Open first input file
    inStream1.open(file1);
    //make sure file open works
    if (inStream1.fail()) {
        cout << "Input file 1 opening failed." << endl;
        exit(1);
    }

    // Open second input file
    inStream2.open(file2);
    //make sure file open works
    if (inStream2.fail()) {
        cout << "Input file 2 opening failed." << endl;
        exit(1);
    }

    // Open output file
    outStream.open(outputFile);
    //make sure file open works
    if (outStream.fail()) {
        cout << "Output file opening failed." << endl;
        exit(1);
    }

    // merge function
    mergeFiles(inStream1, inStream2, outStream);

    // Close everything
    inStream1.close();
    inStream2.close();
    outStream.close();

    cout << "Merged sorted numbers have been written to " << outputFile << endl;

    return 0;
}