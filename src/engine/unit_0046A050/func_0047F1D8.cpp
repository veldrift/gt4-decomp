typedef int s32;
typedef unsigned int u32;

struct Obj {
    s32 unk0;
    s32 unk4;
};

extern "C" void func_0047F2F8(Obj *arg0, s32 arg1);

extern "C" void func_0047F1D8(char *arg0, s32 arg1)
{
    Obj *s0 = (Obj *)(arg0 + 0x20);
    s32 s2 = arg1;

    if (s0->unk0 != 0) {
        s0->unk0 = s0->unk0 + s2;
    }

    u32 s1 = 0;

    if (s0->unk4 != 0) {
        do {
            s32 a0 = s0->unk0 + s1 * 8;
            s1 += 1;
            func_0047F2F8((Obj *)a0, s2);
        } while (s1 < (u32)s0->unk4);
    }
}
