typedef int s32;

extern "C" void func_00576788(s32 a0);
extern "C" void func_005767C0(s32 a0);
extern char D_00872280[];

struct Obj {
    char pad[0x290];
    s32 f290;
    s32 f294;
};

extern "C" void func_00557A70(Obj *arg0, s32 arg1, s32 arg2) {
    s32 lock = (s32)D_00872280;
    func_00576788(lock);
    arg0->f290 = arg1;
    arg0->f294 = arg2;
    func_005767C0(lock);
}
