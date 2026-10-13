typedef int s32;

struct Obj {
    char pad0[0x108];
    s32 unk108;
    char pad10C[0x18];
    s32 idx;
    char pad128[4];
    s32 unk12C;
    char pad130[0x1C];
    s32 unk14C;
};

extern "C" s32 func_002B2310(Obj *arg0) throw();
extern "C" void func_002B5500(void *list, s32 i, s32 on) throw();

extern "C" void func_002B3AF8(Obj *arg0, s32 arg1) {
    if (arg0->idx >= 0 && arg0->unk12C < 0) {
        func_002B5500(arg0, arg0->idx, 0);
    }
    arg0->idx = arg1;
    if (arg1 < 0) {
        if (func_002B2310(arg0) > 0) {
            arg0->idx = 0;
        }
    } else {
        if (arg0->idx >= func_002B2310(arg0)) {
            arg0->idx = func_002B2310(arg0) - 1;
        }
    }
    arg0->unk14C = 1;
    if (arg0->idx >= 0 && arg0->unk12C < 0) {
        func_002B5500(arg0, arg0->idx, arg0->unk108);
    }
}
