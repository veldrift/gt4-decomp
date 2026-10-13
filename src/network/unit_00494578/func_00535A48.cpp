typedef int s32;
typedef unsigned int u32;

struct Vt {
    s32 unk0;
    void (*fn)(s32);
};

struct Holder {
    char pad[4];
    struct Vt *vt;
};

struct Obj {
    char pad0[0x100];
    s32 f100;
    s32 f104;
    s32 f108;
    char pad1[0x134 - 0x10C];
    s32 f134;
    s32 f138;
    s32 f13C;
    s32 f140;
    s32 f144;
    s32 f148;
    s32 f14C;
    char pad2[0x164 - 0x150];
    s32 f164;
};

extern struct Vt *D_0064B4B8;

extern "C" void func_00535C10(char *arg0);
extern "C" s32 func_00535C88(s32 *arg0, u32 arg1);
extern "C" void func_005A48D8(s32, s32, s32);

extern "C" s32 func_00535A48(struct Obj *arg0) {
    u32 i = 0;
    if (arg0->f164 != 0) {
        D_0064B4B8->fn(arg0->f164);
        arg0->f164 = 0;
    }
    do {
        s32 p = func_00535C88((s32 *)arg0, i);
        i++;
        if (p != 0) {
            func_005A48D8(p, 0, 0x2C);
        }
    } while (i < 0x40);
    arg0->f104 = 0x100;
    arg0->f108 = 0x100;
    arg0->f148 = -1;
    arg0->f144 = 0;
    arg0->f100 = 0;
    arg0->f134 = 0;
    arg0->f138 = 0;
    arg0->f13C = 0;
    arg0->f140 = 0;
    arg0->f14C = 0;
    func_00535C10((char *)arg0);
    return 0;
}
