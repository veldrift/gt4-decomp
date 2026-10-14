typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef s32 (*Fn)(s32, s32);
extern "C" void func_00519880(void *, void *, Fn) throw();
extern "C" s32 func_00519A20(s8, void *, u32, u32, s32, void *, void *);
extern "C" s32 func_00519968(s8 a0, void *a1, u32 a2, u32 a3, s32 t0, void *t1, Fn t2) {
    char buf[0x10];
    if (a2 >= 6) return 0x17;
    if (a3 >= 0x100) return 0x17;
    if (t0 <= 0) return 0x17;
    if (t1 == 0) return 0x17;
    func_00519880(buf, a1, t2);
    return func_00519A20(a0, a1, a2, a3, t0, t1, buf);
}
