double recursive_power(double _x, size_t _n)
{
  if (_x == 0. && _n == 0) return 1.;
  return (_n==0) ? (1.0) :  (_x * recursive_power(_x, _n - 1)) ;
}
