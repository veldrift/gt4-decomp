typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct Obj { u32 unk0; char pad4[4]; s32 unk8; };
struct Vt { char pad0[0x2C]; s32 (*f2C)(u32, u32, u8 *, u32); };
extern Vt *D_0064B710;
extern "C" s32 func_0051DE30(Obj *) throw();
extern "C" s32 func_00538F98(u8 *, u16 *);
extern "C" s32 func_0051EF10(Obj *arg0, s32 arg1, u8 *arg2, s32 arg3) {
    u16 sp0;
    u16 id = 0xFFFF;
    if (arg1 == 0x1B) {
        func_00538F98(arg2, &sp0);
        arg2 += 2;
        arg3 -= 2;
        id = sp0;
    }
    if (arg3 != 0x40) return 2;
    u32 a = arg0->unk0;
    D_0064B710->f2C(a & 0x7FFFFFFF, id, arg2, a);
    if (arg0->unk8 == 3) {
        s32 r = func_0051DE30(arg0);
        if (r != 0) return r;
        arg0->unk8 = 4;
    }
    return 0;
}
