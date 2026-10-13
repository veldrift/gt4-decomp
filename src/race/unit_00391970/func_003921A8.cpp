
extern void func_00392168(void *arg0, void *arg1);
extern void func_003921A8(char *arg0)
{
  char *s1;
  int s2;
  func_00392168(arg0 + 0x278, (void *) 0x1C);
  s2 = 3;
  func_00392168(arg0 + 0x298, (void *) 0x1D);
  func_00392168(arg0 + 0x408, (void *) 0x13);
  func_00392168(arg0 + 0x428, (void *) 0xC);
  func_00392168(arg0 + 0x448, (void *) 0x47);
  s1 = arg0;
  do
  {
    func_00392168(s1 + 0x488, (void *) (0x19 & 0xFFFF));
    func_00392168(s1 + 0x4E8, (void *) 0x15);
    s2--;
    func_00392168(s1 + 0x568, (void *) 0x1B);
    func_00392168(s1 + 0x508, (void *) 0x16);
    func_00392168(s1 + 0x4A8, (void *) 0x18);
    func_00392168(s1 + 0x4C8, (void *) 0x1A);
    func_00392168(s1 + 0x588, (void *) 0x39);
    func_00392168(s1 + 0x5A8, (void *) 0x3A);
    func_00392168(s1 + 0x5C8, (void *) 0x3A);
    func_00392168(s1 + 0x528, (void *) 0x37);
    func_00392168(s1 + 0x548, (void *) 0x3B);
    s1 += 0x1A0;
  }
  while (s2 >= 0);
}
