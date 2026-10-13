typedef int s32;
typedef unsigned char u8;

extern "C" {
int func_004EEFE8(void *dev, s32 mode);
int func_00578B50(unsigned int mode, int c);
u8 *func_00578610(u8 *arg0);
void *func_00575098(void *arg0, void *arg1);
s32 func_005788B8(void *arg0);
extern char D_004EF258[];
}

extern "C" s32 func_004EF0F8(void *arg0, s32 arg1) {
    s32 sp[4];
    s32 r = func_004EEFE8(arg0, arg1);
    if (r != 0) {
        void *t;
        sp[0] = (s32)D_004EF258;
        sp[1] = (s32)arg0;
        t = func_00575098(sp, func_00578610((u8 *)func_00578B50(3, 0)));
        *(s32 *)((u8 *)t + 0x40) = 1;
        func_005788B8(t);
        return 1;
    }
    return r;
}
