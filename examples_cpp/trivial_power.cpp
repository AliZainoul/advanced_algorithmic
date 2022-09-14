#include <iostream>
#include <chrono>

using std::cin;
using std::cout;
using std::cerr;

using namespace std::chrono;

/*
  Trivial test cases:
  x = x, n = 0 => recursive_power(x,0) = 1 for all x in real numbers
  x = x, n = 1 => recursive_power(x,1) = x for all x in real numbers
  x = 0, n = n => recursive_power(0,n) = 0 for all n in natural numbers U {0}
  x = 1, n = n => recursive_power(1,n) = 1 for all n in natural numbers U {0}
*/


double trivial_power(double _x, size_t _n)
{
  double result = 1.0;
  if (_n < 0)
    cerr << "The exponent is negative, it should be positive." << '\n';
  if (_x == 0 && _n == 0) return 1.0;
  if (_n == 0) return 1.0;
  else
  {
    for (size_t i = 0; i < _n; i++)
    {
      result *= _x;
    }
  }
  return result;
}

int main()
{
  // Our base x
  double x = 0.0;
  cout << "Please enter your base number x : " << '\n';
  cin >> x;

  // Our exponent n
  size_t n = 0;
  cout << "Please enter your exponent number n : " << '\n';
  cin >> n;


  // starting time
  auto start = high_resolution_clock::now();
  // Call of the function
  cout << "The result of the call recursive_power(" << x << " , " << n
    << ") is: " << trivial_power(x,n) << '\n';
  // end cout

  // stopping time
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds> (stop - start);
  cout << "Duration of the program : " << duration.count() <<
    " microseconds." << '\n';
  // end cout

  return 0;
}
