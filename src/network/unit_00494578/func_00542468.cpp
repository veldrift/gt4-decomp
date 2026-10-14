struct A { char pad0[0x8414]; char buf[0x800]; int len; };
struct B { int flag; char *data; int len; };
extern "C" int func_00541208(A *, char **, int) throw();
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" int func_00542468(A *a, B *b) {
 char **p = &b->data;
 int r = func_00541208(a, p, a->len + 1);
 if (r != 0) return r;
 {
  b->len = a->len;
  b->flag = 1;
  func_005A4724(*p, a->buf, a->len);
  a->buf[0] = 0;
  a->len = 0;
  return 0;
 }
}
