typedef unsigned int u32;
extern "C" void func_001D4BC8(void *, u32, void *, int, int);
extern "C" void func_001D4CA8(void *, u32, void *, u32, float);
extern "C" u32 func_00572C90(void *, u32);
extern "C" void func_005792E8(void *, u32);
extern "C" u32 func_00579358();
extern "C" int func_00579420(void *, u32);
extern "C" void func_005D2680(void *, u32, void *, void *);

struct H { u32 k0; u32 k4; };

extern "C" void func_001D4D10(H *arg0, int arg1, u32 arg2, int arg3, float f0, float f1) {
    char sp[0x9D0];
    char sp9D0[0x10];
    u32 s6 = (arg1 + 0x47) & ~0x3F;
    u32 s2 = s6 - 8;
    void *s1 = (char *)arg0 + 8;
    u32 s7 = s6 - 4;
    arg0->k4 = func_00572C90(s1, s2) ^ arg2;
    u32 v = func_00579358();
    arg0->k0 = v;
    func_00579420(sp, arg0->k4 + v);
    func_005792E8(sp9D0, arg0->k4 ^ arg0->k0);
    func_005D2680(s1, s2, sp, sp9D0);
    func_001D4CA8(((char *)arg0 + 4), s7, ((char *)arg0 + 4), 4, f0);
    if (arg3 != 0) {
        func_00579420(sp, arg0->k0 ^ arg2);
        func_001D4BC8(((char *)arg0 + 4), s7, sp, 0, 0);
    }
    func_001D4CA8(arg0, s6, arg0, 4, f1);
}
