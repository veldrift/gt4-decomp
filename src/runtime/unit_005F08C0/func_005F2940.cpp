typedef int s32;

extern "C" void func_003D62A8(void *, s32);
extern "C" void func_003BB3D8(void *, s32);
extern "C" void func_005C1628(void *);

extern "C" void func_005F2940(void *arg0, s32 arg1) {
    char *var_s0;
    char *temp_s1;

    if ((char *)arg0 != (char *)-0x130) {
        var_s0 = (char *)arg0 + 0x450;
        temp_s1 = (char *)arg0 + 0x130;
        if (temp_s1 != var_s0) {
            do {
                var_s0 -= 0x190;
                func_003D62A8(var_s0, 2);
            } while (temp_s1 != var_s0);
        }
    }
    func_003BB3D8(arg0, 0);
    if ((arg1 & 0x1) != 0) {
        return func_005C1628(arg0);
    }
}
