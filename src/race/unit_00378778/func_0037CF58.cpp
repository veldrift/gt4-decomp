typedef int s32;
typedef unsigned char u8;
typedef long long s64;

struct Obj0037CF58 {
    char pad0[0x168];
    s64 unk168;
    char pad1[0x268 - 0x168 - 8];
    s64 unk268;
};

struct Arg0037CF58 {
    s32 unk0;
    u8 unk4;
};

extern "C" void func_0037BC20(struct Obj0037CF58 *arg0, s32 arg1);

extern "C" void func_0037CF58(struct Obj0037CF58 *arg0, struct Arg0037CF58 *arg1) {
    s64 temp;
    s64 lo;

    func_0037BC20(arg0, arg1->unk0);
    lo = arg0->unk168;
    temp = (((-1LL << 0x10) | 0xFF) << 0x10) | 0xFFFF;
    arg0->unk168 = lo & temp;
    arg0->unk268 = (arg0->unk268 & temp) | ((s64)arg1->unk4 << 0x18);
}
