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
const bool is_prime(const size_t& _n)
{
  // Assumes that n is a (positive) natural number
  if (_n <= 0)  cerr << "The number should be positive ! " << '\n';
  // Otherwise we continue
  else
  {
    if (_n == 1) return false; // 1 is not a prime, nor 0.

    size_t factors = 0;
    for (size_t i = 1; i <= _n; ++i)
    {
      if (_n%i == 0)
        factors += 1;
      // end if
    }
    if (factors == 2)
      return true;
    // means only 1 and _n are factors of _n; hence _n is a prime
  }
  return false;
}
// Time complexity  O(_n)

/*
  Now the main part is, the loop runs till the square root of n not till n.
  To prove that this optimization works, let us consider the following property
  of composite numbers:

  ~Property:
  Every composite number has at least one prime factor less than or equal
  to the square root of itself.
  This property can be proved using a counter statement.
  Let a and b be two factors of n such that a*b = n.
  If both are greater than √n, then a.b > √n, * √n,
  which contradicts the expression “a * b = n”.
*/


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

int main ()
{
  const size_t N = 36;

  /*
  // starting time
  auto _start = high_resolution_clock::now();
  // Call of the function optimized_is_prime(k)
  for (size_t k = 1; k <= N; ++k)
  {
    cout << "The number: " << k << " is: "
    << is_prime_result(optimized_is_prime(k)) << '\n';
  }
  // stopping time
  auto _stop = high_resolution_clock::now();
  auto _duration = duration_cast<microseconds> (_stop - _start);
  cout << "Duration of the call : optimized_is_prime(k) " << _duration.count() <<
    " microseconds." << '\n';
  */

  cout << " -------------------------------------------- "<< '\n';
  // starting time
  auto start = high_resolution_clock::now();

  // Call of the function optimized_is_prime(k)
  for (size_t k = 1; k <= N; ++k)
  {
    cout << my_result(comparing(optimized_is_prime(k), is_prime(k)));
  }
  cout << '\n';
  cout << " -------------------------------------------- "<< '\n';

  // stopping time
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds> (stop - start);
  cout << "Duration of the program: " << duration.count() <<
    " microseconds." << '\n';
  // end cout
  return 0;
}
