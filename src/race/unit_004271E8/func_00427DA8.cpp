typedef int s32;
typedef float f32;

extern "C" {

struct S {
    s32 a;
    s32 b;
    s32 c;
};

f32 func_0042C300(s32 arg0, s32 arg1, f32 arg2, s32 arg3);  /* extern */
void func_0042D7C8(struct S *arg0, int arg1);                /* extern */

extern char D_006877A0[];

struct func_00427DA8_sub {
    char pad0[0x10];
    char *unk10;
};

struct func_00427DA8_arg0 {
    char pad0[4];
    struct func_00427DA8_sub *unk4;
};

s32 func_00427DA8(struct func_00427DA8_arg0 *arg0, s32 arg1) {
    struct S tmp;
    s32 ret = 0;
    s32 s0;

    if (arg0->unk4 != 0) {
        tmp.b = (s32)D_006877A0;
        tmp.a = 0;
        tmp.c = 0;
        func_0042C300((s32)(arg0->unk4->unk10 + arg1 * 0x10), 0, 0.0f, (s32)&tmp);
        s0 = tmp.c;
        func_0042D7C8(&tmp, 2);
        ret = s0;
    }
    return ret;
}

}
