typedef int s32;
typedef unsigned char u8;
struct Obj { u8 unk0; char pad1[3]; s32 unk4; s32 unk8; };
extern "C" s32 func_00539B08(Obj *);
extern "C" s32 func_00539BE0(s32 *);
extern "C" s32 func_00539818(Obj *arg0, s32 *arg1) {
    s32 sp0;
    s32 r;
    if (arg0 == 0) return 2;
    if (arg0->unk0 != 1) return 2;
    r = func_00539BE0(&sp0);
    if (r != 0) return r;
    if (arg0->unk4 == 0 || sp0 != arg0->unk8) {
        r = func_00539B08(arg0);
        if (r != 0) return r;
        r = func_00539BE0(&arg0->unk8);
        if (r != 0) return r;
        arg0->unk4 = arg0->unk4 + 1;
    } else {
        arg0->unk4 = arg0->unk4 + 1;
    }
    if (arg1 != 0) *arg1 = *(volatile s32 *)&arg0->unk4;
    return 0;
}
