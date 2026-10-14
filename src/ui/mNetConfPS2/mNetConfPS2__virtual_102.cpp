typedef int s32;

struct func_004ED4D8_arg0;
extern char D_0069A578[];
extern "C" s32 func_004ED4D8(struct func_004ED4D8_arg0 *arg0, s32 arg1, s32 arg2);

extern "C" void mNetConfPS2__virtual_102(void *arg0, void **arg1, void **arg2) {
    char *d1 = (char *)*arg1;
    s32 n1 = ((s32 *)d1)[-4];
    const char *c1;
    if (n1 == 0) {
        c1 = D_0069A578;
    } else {
        d1[n1] = 0;
        c1 = (const char *)*arg1;
    }

    char *d2 = (char *)*arg2;
    s32 n2 = ((s32 *)d2)[-4];
    const char *c2;
    if (n2 == 0) {
        c2 = D_0069A578;
    } else {
        d2[n2] = 0;
        c2 = (const char *)*arg2;
    }

    func_004ED4D8(*(struct func_004ED4D8_arg0 **)((char *)arg0 + 0x268), (s32)c1, (s32)c2);
}
