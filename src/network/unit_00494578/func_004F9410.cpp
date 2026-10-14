/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef signed char s8;
struct Obj {
    char pad0[0xCBC];
    s32 unkCBC;
    char padCC0[0xFDC - 0xCC0];
    s32 unkFDC;
    char unkFE0[0x20];
    char pad1000[0x2228 - 0x1000];
    s32 unk2228;
};
struct Msg {
    char b0;
    char pad1[0x17];
    s32 f18;
    char a[0x20];
    s32 f3C;
    char c40;
    char t[0x3F];
};
extern "C" void func_004F8820(Obj *, s32) throw();
extern "C" s32 func_0052EAF8(s8, s32, s32, s32, s32, s32, void *);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" s32 func_005A6AB0(void *, void *, s32) throw();
extern "C" s32 func_004F9410(Obj *arg0, char *arg1) {
    Msg m;
    if (arg0->unk2228 == 0) return 0;
    m.b0 = 0;
    m.f18 = arg0->unkFDC;
    func_005A6AB0(m.a, arg0->unkFE0, 0x20);
    m.f3C = 0xFFFFFF;
    func_005A6AB0(m.t, arg1, 0x3F);
    func_0057F260(arg1);
    m.c40 = 0x31;
    s32 r = func_0052EAF8(0x40, arg0->unk2228, -1, 2, arg0->unkCBC, 0x80, &m);
    if (r != 0) {
        func_004F8820(arg0, r);
        return 0;
    }
    return 1;
}
