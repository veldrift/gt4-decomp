/* compiler: ee-gcc2.96-no-strict-aliasing */

typedef unsigned int u32;
typedef int s32;
inline u32 inline_fn(u32 arg0)
{
  return arg0;
}

extern "C" void func_004C3F90(unsigned char *p, u32 n)
{
  unsigned char *q = p;
  u32 four = 4;
  s32 cnt;
  if (n < 8)
  {
    while (inline_fn(n--))
    {
      *q = 0;
      q += 1;
    }

    return;
  }
  cnt = ((s32) p) & 3;
  if (cnt != 0)
  {
    cnt = four - cnt;
    n -= cnt;
    do
    {
      cnt -= 1;
      *q = 0;
      q += 1;
    }
    while (cnt != 0);
  }
  cnt = n / four;
  if (cnt != 0)
  {
    do
    {
      cnt -= 1;
      *((u32 *) q) = 0;
      q += 4;
    }
    while (cnt != 0);
  }
  cnt = n & 3;
  if (cnt != 0)
  {
    do
    {
      cnt -= 1;
      *q = 0;
      q += 1;
    }
    while (cnt != 0);
  }
  return;
}
