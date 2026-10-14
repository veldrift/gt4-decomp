struct Rep { int len, cap, ref, sel; };
struct Info { const char *name; };
struct Pair { char *p; int h[3]; };
extern "C" void func_00208F00(void *, const void *) throw();
extern "C" void func_00208F18(void *, int) throw();
extern "C" int func_005D5DF0(void *, char **);
extern "C" void func_005D5F80(void *, void *, Pair *);
extern "C" char *func_005C2560(Rep *);
extern "C" Info *func_005C11A8();
extern "C" void func_00326798(void *, int, int, const char *);
static inline void copy(Pair *dst, char **src) {
 int q=*(int *)src;
 Rep *r=(Rep *)(q-16);
 int d=q;
 if(r->sel) d=(int)func_005C2560(r);
 else r->ref=r->ref+1;
 *(int *)&dst->p=d;
}
extern "C" void func_00209CA0(char *o, char **str, int *h) {
 if (*h == 0) { func_005D5DF0(o + 0x20, str); return; }
 char *dest = o + 0x20;
 int result[4];
 Pair pair;
 Pair *ps=&pair;
 copy(ps,str);
 func_00208F00(ps->h, h);
 func_005D5F80(result, dest, ps);
 func_00208F18(pair.h, 2);
 Rep *q = (Rep *)(*(int *)&ps->p - 0x10);
 if (--q->ref == 0) {
  int cap = q->cap + 0x10;
  func_00326798(q, cap, 4, func_005C11A8()->name);
 }
}
