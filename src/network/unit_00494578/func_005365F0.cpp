typedef int s32;
struct Obj { char pad0[0x158]; s32 unk158; };
struct Vt { char pad0[0x18]; s32 (*f18)(Obj *); s32 (*f1C)(void); s32 (*f20)(Obj *, s32); };
extern Vt *D_0064B4AC;
extern "C" void func_00533188(Obj *, s32, s32, s32, s32) throw();
extern "C" void func_005365F0(s32 arg0, s32 arg1, s32 arg2, Obj *arg3) {
    s32 s1 = arg0 & 0xFFFF;
    if (arg3 == 0) return;
    if (arg3->unk158 == 2) {
        if (arg2 == 0 && s1 != 0xFFFE) {
            func_00533188(arg3, s1, 1, arg1, 0);
        } else {
            func_00533188(arg3, 0x100, 0, 0, 1);
        }
    }
    Vt *v = D_0064B4AC;
    if (v != 0 && v->f18(arg3) != 0) {
        D_0064B4AC->f20(arg3, s1);
    }
}
