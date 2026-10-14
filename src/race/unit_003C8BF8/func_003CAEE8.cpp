typedef int s32;

extern char D_006A2F18[];
extern char D_006A2F20[];

extern "C" s32 pdiRiderman__Skeleton__getBoneIndex(s32 arg0);
extern "C" s32 func_0057F238(void *arg0, s32 arg1);

extern "C" void *func_003CAEE8(char *arg0, s32 arg1) {
    s32 temp = pdiRiderman__Skeleton__getBoneIndex(arg1);
    char *var = arg0 + (temp << 6) + 0x544;
    if (temp >= 0) {
        return var;
    }
    if (arg1 == 0) {
        return 0;
    }
    void *a = *(void **)(arg0 + 0xA98);
    if (a != 0) {
        if (func_0057F238(a, arg1) == 0) {
            return arg0 + 0xA44;
        }
    }
    if (func_0057F238(D_006A2F18, arg1) == 0) {
        return *(void **)(arg0 + 0xA84);
    }
    if (func_0057F238(D_006A2F20, arg1) == 0) {
        return *(void **)(arg0 + 0xA88);
    }
    return 0;
}
