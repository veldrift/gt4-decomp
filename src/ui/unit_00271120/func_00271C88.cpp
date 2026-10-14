/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Str { char *p; char pad[12]; };
struct Pair { int a, b; };
extern "C" void func_00522408(Pair *, const char *);
extern "C" int func_00520D88(void *, Pair, int, void *);
extern char D_0069A478[];
extern "C" int func_00271C88(char *self, Str *s, int arg2) {
 Pair buf;
 char *p = s->p;
 int len = *(int *)(p - 16);
 const char *c;
 if (len == 0) c = D_0069A478;
 else { p[len] = 0; c = s->p; }
 func_00522408(&buf, c);
 int r = func_00520D88(self+16, buf, arg2, self+20);
 *(int *)(self+32) = r;
 return r == 0;
}
