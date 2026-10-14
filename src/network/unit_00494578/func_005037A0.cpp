/* compiler: ee-gcc2.96-no-strict-aliasing */
struct B { int a; int b; };
struct S { char pad[0xC]; int f0C; int f10; int pad14; int f18; };
extern "C" void func_0060F9A0(void *, void *);
extern "C" void *func_00578D40(void *);
extern "C" int func_005037A0(S *s) {
    func_0060F9A0(s, s);
    s->f0C = 0;
    s->f10 = 0;
    s->f18 = 0;
    func_00578D40((char *)s + 0x1C);
    B *b = (B *)((char *)s + 0x40);
    b->a = 0;
    b->b = 0x1000;
}
