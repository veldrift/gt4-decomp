typedef int s32;

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

extern "C" void func_0055C008(Obj *arg0);

extern "C" void func_0055BFE0(Obj *arg0) {
    arg0->unk0 = -1;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
    return func_0055C008(arg0);
}
