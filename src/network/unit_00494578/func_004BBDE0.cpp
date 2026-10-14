/* compiler: ee-gcc2.96-no-strict-aliasing */
struct S { char p0[12]; int *pC; char p10[20]; int v24; char p28[4]; int *p2C; char p30[8]; int *p38; };
extern S *D_006452D4;
extern "C" void func_004BC6E8(void *);
extern "C" int func_004C1768(int);
extern "C" int func_004BFC70(void *, int);
extern "C" int func_004BC098();
extern "C" int func_004BBDE0() {
 int result = 0x80000240;
 if (*D_006452D4->p2C == 0x65) return result;
 {
  func_004BC6E8(D_006452D4);
  int r = func_004C1768(D_006452D4->v24);
  if (r == 0) {
   r = func_004BFC70(D_006452D4, 0x300);
   if (r == 0) { func_004BC098(); *D_006452D4->p38 = 0; }
  }
  *D_006452D4->pC = 0;
  return r;
 }
}
