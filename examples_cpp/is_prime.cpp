#include <iostream>
#include <string>
#include <chrono>

using std::cin;
using std::cout;
using std::cerr;
using std::string;

using namespace std::chrono;

const bool comparing (const bool& b1, const bool& b2)
{
  return (b1==b2) ? true : false; // compare;
}

const string is_prime_result (const bool& b)
{
  return (b) ? "prime." : "NOT prime.";
}

const string my_result (const bool& b)
{
  return (b) ? "1" : "0";
}

// Method to compute if a positive number is a prime number
const bool isPrime(const int& n)
{
  // Corner case
  if (n <= 1) return false;
  // Check from 2 to n-1
  for (int i = 2; i < n; i++)
    if (n % i == 0) return false;
  return true;
}
// Time complexity  O(n)

// Method to compute if a positive number is a prime number
const bool is_prime(const size_t& _n)
{
  // Assumes that n is a (positive) natural number
  if (_n <= 1) return false; // 1 is not a prime, nor 0.

  size_t factors = 0;
  for (size_t i = 1; i <= _n; ++i)
  {
    if (_n%i == 0)
      factors += 1;
    // end if
  }
  if (factors == 2) return true;
  return false;
}
// Time complexity  O(_n)

const bool optimized_is_prime (const size_t& _n)
{
  // Assumes that n is a (positive) natural number
  if (_n <= 1)      return false; // 1 is not a prime, nor 0.
  for (size_t i = 2; (i*i) <= _n; i++)
  {
    if (_n % i == 0)  return false;
  }
  return true;
}
// Time complexity : O(√_n)

// Driver Program to test above function
int main()
{

  const size_t N = 37;

  cout << " -------------------------------------------- "<< '\n';
  // starting time
  auto start = high_resolution_clock::now();

  // Main loop
  for (size_t k = 1; k <= N; ++k)
  {
    /*
    cout << "Iteration: " << k << '\n';
    cout << "Comparing isPrime with is_prime: "
      << my_result(comparing(isPrime(k), is_prime(k))) << '\n';
    // end cout
    cout << "Comparing isPrime with optimized_is_prime: "
      << my_result(comparing(isPrime(k), optimized_is_prime(k))) << '\n';
    // end cout
    cout << " -------------------------------------------- "<< '\n';
    */

    cout << "The number: " << k << " is: "
      << is_prime_result(optimized_is_prime(k)) << '\n';

  }
  cout << '\n';

  // stopping time
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds> (stop - start);
  cout << "Duration of the program: " << duration.count() <<
    " microseconds." << '\n';
  // end cout

  return 0;
}
