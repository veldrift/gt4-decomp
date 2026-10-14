typedef int s32;
struct Res { s32 unk0; s32 unk4; };
struct Obj { s32 unk0; s32 pad4; s32 unk8; };
extern "C" s32 func_00533790(Obj *, void *, Res *);
extern "C" s32 func_00533CE8(Obj *, void *, Res *);
extern "C" s32 func_005336D0(Obj *arg0, Res *arg1) {
    if (arg1 == 0) return 0x17;
    arg1->unk4 = 3;
    arg1->unk0 = 1;
    if (arg0 == 0) {
        arg1->unk4 = 0x17;
        return 0x17;
    }
    if (arg0->unk0 == 0) {
        arg1->unk4 = 0x26;
        return 0x26;
    }
    s32 *p = &arg0->unk8;
    s32 v = *p;
    if (v == 1 || v == 3 || v == 4) {
        arg1->unk4 = func_00533790(arg0, p, arg1);
    } else if (v == 2) {
        arg1->unk4 = func_00533CE8(arg0, p, arg1);
    } else {
        arg1->unk4 = 0x17;
    }
    return arg1->unk4;
}
