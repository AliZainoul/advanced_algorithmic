#include <iostream>
#include <chrono>

using std::cin;
using std::cout;

using namespace std::chrono;

/*
  Trivial test cases:
  x = x, n = 0 => recursive_power(x,0) = 1 for all x in real numbers
  x = x, n = 1 => recursive_power(x,1) = x for all x in real numbers
  x = 0, n = n => recursive_power(0,n) = 0 for all n in natural numbers U {0}
  x = 1, n = n => recursive_power(1,n) = 1 for all n in natural numbers U {0}
*/

/* (*) : the same function as below
  double recursive_power(double _x, size_t _n)
  {
    if (_x == 0. && _n == 0)  return 1;
    if (_n == 0)              return 1;
    else                      return _x * recursive_power(_x, _n -1);
  }
*/

double recursive_power(double _x, size_t _n)
{
  // Case when x = n = 0 ?! We know that: (1/n)^(1/n) -> 1 when n -> +oo
  // Because: (1/n) ^(1/n) = e ^(ln(1/n) / n)
  //                       = e ^( (ln(1)-ln(n)) / n) (ln(1) = 0)
  //                       = e ^( -ln(n) / n)
  //                       ~ 1 + (-ln(n)/n) + O((1/n)^2) where (O(1/n)^2) -> 0)
  //                       ~ 1 + (-ln(n)/n) + O((1/n)^2) where (O(1/n)^2) -> 0)
  //                       -> 1 when n -> +oo
  // so 0^0 = 1 ?! Yes, but the limit is approaching 1 not exactly equals to 1 !
  if (_x == 0. && _n == 0) return 1;

  // Ternary Operator equivalent to (*)
  return (_n==0) ? (1.0) :  (_x * recursive_power(_x, _n - 1)) ;
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
    << ") is: " << recursive_power(x,n) << '\n';
  // end cout

  // stopping time
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds> (stop - start);
  cout << "Duration of the program : " << duration.count() <<
    " microseconds." << '\n';
  // end cout

  return 0;
}
