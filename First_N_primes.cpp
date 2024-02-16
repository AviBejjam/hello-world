#include <iostream>
using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    // If the number is less than or equal to 1, it's not prime
    if (num <= 1) return false;
    // If the number is 2 or 3, it's prime
    if (num <= 3) return true;
    // If the number is divisible by 2 or 3, it's not prime
    if (num % 2 == 0 || num % 3 == 0) return false;
    // Check divisibility by numbers of the form 6k +/- 1, up to sqrt(num)
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    // If not divisible by any number up to sqrt(num), it's prime
    return true;
}

// Function to print the first n prime numbers
void printPrimes(int n) {
    int count = 0; // Initialize counter for prime numbers
    int num = 2;   // Start checking from 2, the first prime number
    // Loop until n prime numbers are printed
    while (count < n) {
        if (isPrime(num)) { // If num is prime
            cout << num << " "; // Print the prime number
            count++; // Increment the counter
        }
        num++; // Move to the next number
    }
}

int main() {
    int n;
    // Ask the user for the number of prime numbers to print
    cout << "Enter the value of n: ";
    cin >> n;
    // Print the first n prime numbers
    cout << "First " << n << " prime numbers are: ";
    printPrimes(n);
    return 0;
}
