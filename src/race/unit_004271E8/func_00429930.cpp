typedef int s32;

struct Elem00429930 {
    char pad[0x10];
    s32 unk10;
};

struct Mid00429930 {
    char pad[8];
    Elem00429930 *unk8;
};

struct Obj00429930 {
    char pad[0x10];
    Mid00429930 *unk10;
};

extern "C" s32 func_00429870(struct Obj00429930 *arg0, s32 arg1);

extern "C" s32 func_00429930(struct Obj00429930 *arg0, s32 arg1, s32 arg2) {
    char *v1 = (char *)arg0->unk10 + arg2 * 0x10;
    Mid00429930 *m = (Mid00429930 *)v1;
    Elem00429930 *e = (Elem00429930 *)((char *)m->unk8 + (arg1 << 5));
    return func_00429870(arg0, e->unk10);
}
