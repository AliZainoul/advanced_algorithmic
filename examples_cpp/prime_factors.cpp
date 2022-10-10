#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>

using std::cin;
using std::cout;
using std::vector;

using namespace std::chrono;

template <typename C>
std::ostream& operator<<(std::ostream& os, const std::vector<C>& c) {
  os << "[";
  for (const auto& v : c) {
    os << v << " ";
  }
  os << "]";
  return os;
}


template <typename T>
T vector_product(const vector<T>& _v)
{
  T product = 1;
  for (const auto& element: _v)
    product *= element;
  return product;
}

// A function to store all prime
// factors of a given number n
vector<int> primeFactors(const int& _n)
{
  int n = _n;
  vector<int> v_primeFactors;
  // Store the number of 2s that divide n
  while (n % 2 == 0)
  {
    v_primeFactors.push_back(2);
    n = n/2;
  }

  // n must be ODD at this point. So we can skip one element (Note i += 2)
  for (int i = 3; i <= sqrt(n); i += 2)
  {
    // While i divides n, store i and divide n
    while (n % i == 0)
    {
      v_primeFactors.push_back(i);
      n = n/i;
    }
  }

  // This condition is to handle the case when n
  // is a prime number greater than 2
  if (n > 2)
    v_primeFactors.push_back(n);
  return v_primeFactors;
}
// time complexity: O(sqrt(_n))

vector<int> optimized_primeFactors(const int& _n)
{
  int n = _n;
  vector<int> v_primeFactors;
  int c = 2;
  while(n>1)
  {
    if (n%c == 0)
    {
      v_primeFactors.push_back(c);
      n /= c;
    }
    else
      c++;
  }
  return v_primeFactors;
}
// time complexity: O(log(_n))



int main()
{

  const int n = 315;

  // starting time
  auto start = high_resolution_clock::now();

  // Call of the function
  cout << "The result of the call primeFactors(" << n
    << ") is: " << primeFactors(n) << '\n';
  // end cout

  cout << "The product of the resulting vector: "
    << vector_product(optimized_primeFactors(n)) << '\n';
  // end cout

  // stopping time
  auto stop = high_resolution_clock::now();

  // printing time duration
  auto duration = duration_cast<microseconds> (stop - start);
  cout << "Duration of the program : " << duration.count() <<
    " microseconds." << '\n';
  // end cout

  return 0;
}




/*
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
*/
