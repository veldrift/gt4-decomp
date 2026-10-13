typedef int s32;
typedef unsigned char u8;

extern char D_0067E758[];

extern "C" void *func_0034C190(s32 arg0, s32 arg1);
extern "C" void func_003A3148(void *o, void *t);
extern "C" void *func_003A34E8(void *arg0);
extern "C" void func_003A35F0(void *s, s32 x);

struct Auto_unk84 {
    char pad0[0x70];
    s32 unk70;
};

struct Auto_arg0 {
    char pad0[0x84];
    struct Auto_unk84 *unk84;
    char pad88[0x54];
    s32 unkDC;
};

extern "C" void func_0035E078(struct Auto_arg0 *arg0, s32 arg1, s32 arg2) {
    s32 sp[4];
    if (*((u8 *)func_0034C190(arg0->unk84->unk70, arg1) + 0x736) == 0) {
        if (arg0->unkDC == 0) {
            func_003A34E8(sp);
            sp[1] = (s32)D_0067E758;
            sp[0] = arg1;
            func_003A35F0(sp, arg2);
            func_003A3148(sp, arg0);
        }
    }
}
