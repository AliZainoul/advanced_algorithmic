#include <iostream>

using std::cout;
using std::cin;

/*
Recursive call to Euclide's algorithm
function euclide(a, b)
  if b = 0 then return a
  else return euclide(b, a modulo b)
*/

size_t euclide(size_t a, size_t b) {return (b==0) ?  a : euclide(b, a%b);}

int main()
{

  size_t a,b = 0;
  cout << "Please enter two positive integers a and b: " << '\n';
  cin >> a >> b;
  cout << " Euclide of (" << a << " , " << b << ") is: "
    << euclide(a,b) << '\n';
  // end cout
  return 0;
}
