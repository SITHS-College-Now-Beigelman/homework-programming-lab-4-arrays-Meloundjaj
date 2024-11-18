//Meloundja Joseph
//Homework Lab 4 

#include <iostream>  // For input/output operations
#include <string>    // For string operations
#include <limits>    // For numeric_limits (to ignore leftover input in the buffer)

using namespace std;

// Function prototypes
void filterEvens(int arr[], int size);
string dna_to_rna(const string &dna);

int main() {
    const int SIZE = 8;  // Size of the array
    int myArray[SIZE];   // Array to store user input
    
    cout << "Enter 8 integers:" << endl;
    
    // Input 8 integers from the user
    for (int i = 0; i < SIZE; ++i) {
        cin >> myArray[i];
    }

    // Function call to filter even numbers
    filterEvens(myArray, SIZE);

    // Car sales data
    int cars[10] = {7, 3, 6, 0, 14, 8, 1, 2, 9, 8};
    int totalCarsSold = 0;
    int bestSalesperson = 0;

    // Calculate total cars sold and find the best salesperson
    for (int i = 0; i < 10; ++i) {
        totalCarsSold += cars[i];
        if (cars[i] > cars[bestSalesperson]) {
            bestSalesperson = i;  // Update best salesperson if the current one sold more
        }
    }

    // Output total sales and best salesperson info
    cout << "Total number of cars sold at the entire dealership: " << totalCarsSold << endl;
    cout << "Salesperson #" << (bestSalesperson + 1) << " sold the most cars." << endl;
    cout << "They sold " << cars[bestSalesperson] << " cars." << endl;

    // Clear the input buffer before reading the DNA sequence
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Input DNA sequence
    string dna;
    cout << "Enter a DNA sequence: ";
    getline(cin, dna);  // Reads the entire line, including spaces

    // Convert DNA to RNA and output the result
    string rna = dna_to_rna(dna);
    cout << "The RNA sequence is: " << rna << endl;

    return 0;
}

// Function to filter and print even numbers in an array
void filterEvens(int arr[], int size) {
    cout << "Even numbers in the array are:" << endl;
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 0) {  // Check if the number is even
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

// Function to convert DNA sequence to RNA sequence
string dna_to_rna(const string &dna) {
    string rna = "";  // Initialize an empty RNA sequence
    for (char nucleotide : dna) {
        switch (nucleotide) {
            case 'A': rna += 'U'; break;  // Replace 'A' with 'U'
            case 'C': rna += 'G'; break;  // Replace 'C' with 'G'
            case 'G': rna += 'C'; break;  // Replace 'G' with 'C'
            case 'T': rna += 'A'; break;  // Replace 'T' with 'A'
            default:
                // Ignore any non-DNA characters
                break;
        }
    }
    return rna;
}
