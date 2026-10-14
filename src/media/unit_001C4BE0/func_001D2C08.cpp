/* compiler: ee-gcc2.96-no-strict-aliasing */
struct S { char p[0x694]; volatile int a, b; };
extern "C" void func_001D2CA0(S *);
extern "C" void func_00576788(S *);
extern "C" void func_005767C0(S *);
extern "C" void func_00578B10(int);
extern "C" void func_001D2C08(S *s) {
    for (;; func_00578B10(0x3E80)) {
    func_00576788(s);
    if (s->b != 5) {
        s->a = s->b;
        s->b = 5;
    }
    func_005767C0(s);
    if (s->a == 0) {
        func_001D2CA0(s);
        continue;
    }
    if (s->a == 4) break;
    }
}
