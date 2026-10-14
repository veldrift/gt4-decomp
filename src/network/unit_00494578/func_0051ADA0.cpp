typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
enum State { STATE_0, STATE_5 = 5 };
struct Ent { char pad0[0xC]; State unkC; char pad10[0x10]; s32 unk20; };
struct Obj { Ent *slots[0x41]; s32 unk104; };
struct Msg { u8 b0, b1, b2, b3; };
extern "C" void func_0051B018(Obj *, u8, u8, u8);
extern "C" void func_005310D0(Obj *, u8);
extern "C" Ent *func_00535C88(Obj *, u32);
extern "C" s32 func_0051ADA0(Obj *arg0, s32 a1, u32 a2, Msg *m) {
    s32 ret = -1;
    if (arg0 != 0 && a2 < 0x40) {
        Ent *e = func_00535C88(arg0, m->b1);
        if (e == 0) return -1;
        if (e->unk20 == 0) return -1;
        u8 b0 = m->b0;
        s32 idx = arg0->unk104;
        e->unkC = (State)b0;
        if (idx == 0x100) return -1;
        func_005310D0(arg0, m->b1);
        Ent *c = arg0->slots[idx];
        if (c->unkC == STATE_5) func_0051B018(arg0, m->b1, m->b2, m->b3);
        ret = 4;
    }
    return ret;
}
