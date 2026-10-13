
typedef unsigned int unsigned32;
extern int func_005AC868(unsigned32 *y)
{
  register int k;
  int new_var;
  register unsigned32 x = *y;
  if (x & 7)
  {
    if (x & 1)
    {
      return 0;
    }
    if (x & 2)
    {
      *y = x >> 1;
      return 1;
    }
    *y = x >> 2;
    return 2;
  }
  k = 0;
  if (!(x & 0xffff))
  {
    k = 16;
    x >>= 16;
  }
  if (!(x & 0xff))
  {
    k += 8;
    x >>= 8;
  }
  if (!(x & 0xf))
  {
    k += 4;
    x >>= 4;
  }
  if (!(x & 0x3))
  {
    k += 2;
    x >>= 2;
  }
  if (!(new_var = x & 1))
  {
    k++;
    x >>= 1;
    if ((!x) & 1)
    {
      return 32;
    }
  }
  *y = x;
  return k;
}
