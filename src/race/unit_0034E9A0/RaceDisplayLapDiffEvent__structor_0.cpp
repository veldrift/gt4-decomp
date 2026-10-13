typedef int s32;
typedef unsigned char u8;

extern char D_0067E730[];

extern "C" s32 func_0034C190(s32 arg0, s32 arg1);
extern "C" void *func_003A34E8(void *arg0);
extern "C" void func_003A3148(void *o, void *t);

extern "C" void func_0035E8E8(void **arg0, s32 arg1, s32 arg2) {
    s32 sp[4];
    if (*((u8 *)func_0034C190((s32)arg0, arg1) + 0x736) == 0) {
        char *t = (char *)*arg0;
        if (*(s32 *)(t + 0xDC) == 0) {
            func_003A34E8(sp);
            sp[1] = (s32)D_0067E730;
            sp[0] = arg1;
            sp[2] = arg2;
            func_003A3148(sp, t);
        }
    }
}
