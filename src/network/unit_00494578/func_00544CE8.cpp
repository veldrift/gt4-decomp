typedef unsigned int u32;
extern "C" void func_00544830(int *, int) throw();
extern "C" void func_00544978(u32 *, u32) throw();
extern "C" u32 func_00545A54(void *);
extern "C" int func_00545BF0(void *, void *);
extern "C" void func_00545C58(void *, u32);
extern "C" void func_00545D7C(void *, u32);
extern "C" void func_00545FC0(void *, void *);
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" void func_00544CE8(void *arg0, void *arg1, u32 *arg2, void *arg3) {
    int sp[32];
    func_005A4724(sp, arg1, 0x80);
    func_005A4724(arg3, arg0, 0x80);
    u32 s1 = func_00545A54(arg3);
    u32 s0 = func_00545A54(sp);
    func_00544830((int *)arg2, 0);
    u32 s2 = s0;
    if (s0 < s1) {
        u32 d = s1 - s0;
        s0 = s1;
        func_00545D7C(sp, d);
    }
    int s4 = s1 < s2;
    for (;;) {
        if (s4) return;
        if (s1 < s0) {
            u32 d = s0 - s1;
            s0 = s1;
            func_00545C58(sp, d);
        }
        if (func_00545BF0(arg3, sp)) {
            func_00545FC0(arg3, sp);
            s1 = func_00545A54(arg3);
            func_00544978(arg2, s0 - s2);
            s4 = s1 < s2;
        } else {
            if (s2 >= s0) return;
            --s0;
            func_00545C58(sp, 1);
        }
    }
}
