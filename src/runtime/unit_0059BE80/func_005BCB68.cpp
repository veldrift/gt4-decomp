
void func_00575DA0(int arg0);
char *func_005BC6C0(void);
void func_005BCB68(int arg0)
{
  char *base = func_005BC6C0();
  int off = arg0 - ((int) base);
  int idx = off - 0x10;
  if (((unsigned) idx) < 0xC0u)
  {
    int bit = 1 << (idx / 16);
    int v = *((int *) (base + 0xD0));
    if (arg0)
    {
      v ^= bit;
      bit <<= 1;
    }
    else
    {
      v ^= bit;
      bit <<= 1;
    }
    while (v & bit)
    {
      v ^= bit;
      bit <<= 1;
    }

    *((int *) (base + 0xD0)) = v;
    return;
  }
  return func_00575DA0(arg0);
}
