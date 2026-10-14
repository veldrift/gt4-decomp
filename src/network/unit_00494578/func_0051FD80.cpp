extern unsigned D_0064AE1C;
extern int D_0064AE18;
extern "C" int func_00538BF8(int *, unsigned long);
extern "C" int func_00538C68(int *);
extern "C" int func_0051FD80(unsigned n) {
 if (!n) return 2;
 if (D_0064AE1C < n) {
  if (D_0064AE18) func_00538C68(&D_0064AE18);
  int result=func_00538BF8(&D_0064AE18, n);
  if (result) return result;
  D_0064AE1C=n;
 }
 return 0;
}
