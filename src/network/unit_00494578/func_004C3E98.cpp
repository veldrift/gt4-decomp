
typedef unsigned int u32;
typedef int s32;
inline u32 inline_fn(u32 arg0)
{
  return arg0;
}

extern void *func_004C3E98(unsigned char *p, int c, u32 n)
{
  unsigned char *q = p;
  u32 four = 4;
  u32 v = c & 0xFF;
  s32 cnt;
  if (n < 8)
  {
    while (inline_fn(n--))
    {
      *q = c;
      q += 1;
    }

    return p;
  }
  cnt = ((s32) p) & 3;
  if (cnt != 0)
  {
    cnt = four - cnt;
    n -= cnt;
    do
    {
      cnt -= 1;
      *q = c;
      q += 1;
    }
    while (cnt != 0);
  }
  cnt = n / four;
  if (cnt != 0)
  {
    if (v != 0)
    {
      v = v | (v << 8);
      v = v | (v << 16);
    }
    do
    {
      cnt -= 1;
      *((u32 *) q) = v;
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
      *q = c;
      q += 1;
    }
    while (cnt != 0);
  }
  return p;
}
