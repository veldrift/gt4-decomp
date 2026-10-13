typedef int s32;
struct Obj { s32 v; };
extern "C" char D_00845E90[];
extern "C" char D_00845E98[];
extern "C" char D_006A55C8[];
extern "C" char D_006A56A8[];
extern "C" void func_0057B198(Obj *arg0, s32 arg1, s32 arg2);

extern "C" void func_00431CE8(s32 init, s32 prio) {
    if (prio == 0xFFFF && init == 1)
        func_0057B198((Obj *)D_00845E90, (s32)D_006A55C8, 0x10);
    if (prio == 0xFFFF && init == 1)
        func_0057B198((Obj *)D_00845E98, (s32)D_006A56A8, 0xF);
}
