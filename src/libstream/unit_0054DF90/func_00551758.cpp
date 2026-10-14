/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
extern "C" s32 func_005782E8(s32, s32);
extern "C" s32 func_005AD980(s32, void *, s32);
extern "C" void func_005783A0(s32);
extern "C" void func_00578500(s32);
extern "C" void func_00551580(void) throw();
extern "C" s32 func_005AD9A0(s32, s32);
extern char D_0064C718[];
struct Flag { int v; };
extern volatile Flag D_0064C714;
static inline int active(volatile Flag *const p) { return p->v; }
extern char D_00551728[];
extern "C" void func_00551758(void) {
    {
        s32 *q = (s32 *)D_0064C718;
        *q = func_005782E8(0, 255);
    }
    s32 t = func_005AD980(2, D_00551728, 0);
    while (active(&D_0064C714) != 0) {
        func_00578500(*(s32 *)D_0064C718);
        func_00551580();
    }
    s32 *q = (s32 *)D_0064C718;
    func_00578500(*q);
    func_005AD9A0(2, t);
    func_005783A0(*q);
}
