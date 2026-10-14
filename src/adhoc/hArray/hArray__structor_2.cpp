/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { int pad; char *start, *finish, *eos; };
extern char hArray__vtable[], D_0069D5B0[];
extern "C" void func_00309378(void *, int);
extern "C" void hObject__structor_2(void *, int);
extern "C" void func_00326798(void *, int, int, const char *);
extern "C" const char **HObject__tf(void);
extern "C" void hArray__structor_2(char *self, int flags) {
 Vec *v = (Vec *)(self + 0x10);
 char *p, *e, *s;
 int n;
 char *sp[4];
 *(void **)(self + 4) = hArray__vtable;
 s = v->start;
 e = v->finish;
 p = s;
 sp[0] = s;
 if (s != e) {
  do {
   char *q = p;
   p += 4;
   func_00309378(q, 2);
  } while (p != e);
  s = v->start;
 }
 n = (v->eos - s) >> 2;
 if (s != 0) func_00326798(s, n << 2, 4, *HObject__tf());
 hObject__structor_2(self, 0);
 if (flags & 1) func_00326798(self, 0x24, 4, D_0069D5B0);
}
