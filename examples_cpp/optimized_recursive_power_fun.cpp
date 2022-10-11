double optimized_recursive_power(double x, size_t n) {
  if (x == 0. && _n == 0)  return 1.;
  if (n == 1)              return x;
  if (n%2 == 0)      return     optimized_recursive_power(x * x,   n  /2);
  else               return x * optimized_recursive_power(x * x, (n-1)/2);
}
// Time complexity  O(log n)
