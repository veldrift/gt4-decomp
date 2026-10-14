typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef unsigned char u8;

extern char mSound__vtable[];
extern char D_00698E08[];

extern "C" void *hObject__structor_0(void *);
extern "C" void *func_00326750(u32, s32, const char *);
extern "C" void mMusic__structor_0(void *);
extern "C" void func_002C2848(void *, s32 *);

extern "C" void mSound__structor_0(s8 *arg0) {
    s32 sp[4];
    s32 v_s1;
    s32 v_s0;
    s32 *p1;

    hObject__structor_0(arg0);
    *(s32 *)(arg0 + 0x4) = (s32)mSound__vtable;
    v_s1 = (s32)func_00326750(0x24, 4, D_00698E08);
    mMusic__structor_0((void *)v_s1);
    sp[0] = v_s1;
    func_002C2848(arg0 + 0x10, sp);
    p1 = &sp[1];
    v_s0 = (s32)func_00326750(0x24, 4, D_00698E08);
    mMusic__structor_0((void *)v_s0);
    sp[1] = v_s0;
    func_002C2848(arg0 + 0x14, p1);
}
