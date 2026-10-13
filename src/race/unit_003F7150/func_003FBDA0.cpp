
extern void func_005A48D8(void *, int, int);
extern void func_003FBDA0(char *arg0)
{
  char *s1 = arg0 + 0x3C;
  char *s2 = arg0 + 0x30;
  char *s7 = arg0 + 0x4;
  char *s6 = arg0 + 0x8;
  int s4 = 0;
  int s5 = 1;
  do
  {
    char *s0 = arg0 + s4;
    func_005A48D8((arg0 + s4) + 0x14, 0, 0xC);
    func_005A48D8(s0 + 0x20, 0, 0xC);
    *((int *) (s1 - 0x10)) = 0;
    int v2 = s4 + 0x30;
    s4 += 0x2C;
    s5 -= 1;
    *((int *) (s7 + v2)) = (*((int *) s2) = 0);
    *((int *) (s6 + v2)) = 0;
    s2 += 0x2C;
    *((int *) s1) = 0;
    s1 += 0x2C;
  }
  while (s5 >= 0);
}
