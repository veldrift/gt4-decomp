typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct Item { char pad0[4]; s32 unk4; char pad8[0x10]; s32 unk18; };
struct Obj { char pad0[4]; s32 unk4; s32 unk8; char padC[0x70]; Item *unk7C; };
struct Vt { char pad0[0x80]; s32 (*f80)(void *, void *); };
extern Vt *D_0064B4B0;
extern "C" s32 func_0051E028(Obj *, Item &) throw();
extern "C" s32 func_00538F98(u8 *, u16 *);
static inline int fits(u32 size, u32 offset) { return offset + 1 < size; }
extern "C" s32 func_0051EFD0(Obj *arg0, void *arg1, void *arg2, u32 arg3) {
    u16 sp0;
    s32 t = arg0->unk4;
    if (t != 1) return 0xCB20;
    Item *it = arg0->unk7C;
    if (it == 0) return 3;
    if (arg3 < 0x10) return 0xCB20;
    D_0064B4B0->f80((char *)it + 0x10, arg2);
    u8 *p = (u8 *)arg2 + 0x10;
    if (!fits(arg3, 16)) return 0xCB20;
    func_00538F98(p, &sp0);
    it->unk18 = sp0;
    if (sp0 == 0) return 0xCB20;
    it->unk4 = t;
    s32 r = func_0051E028(arg0, *it);
    if (r == 0) arg0->unk8 = 6;
    return r;
}
