typedef int s32;

struct Obj {
    char pad[0x54];
    s32 unk54;
};

extern "C" char D_00655340[];
extern "C" void func_00576100(Obj *arg0);
extern "C" void func_00576140(Obj *arg0);

extern "C" void func_00559330(Obj *arg0) {
    Obj *lock = (Obj *)D_00655340;
    func_00576100(lock);
    arg0->unk54 = 2;
    func_00576140(lock);
}
