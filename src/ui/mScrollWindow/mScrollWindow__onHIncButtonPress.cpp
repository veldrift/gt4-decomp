typedef int s32;

extern "C" void func_002D2318(char *arg0, float fparg0);
extern "C" void func_0025B340(void *c, float y);

extern "C" s32 func_002D2EA0(char *arg0) {
    s32 var_v0 = 0;
    char *temp_s1 = arg0 + 0xFC;
    if (*(void **)(arg0 + 0xC0) == 0) {
        return var_v0;
    }
    func_002D2318(temp_s1, 8.0f);
    float y = -*(float *)(temp_s1 + 0x14);
    func_0025B340(*(void **)(arg0 + 0xC0), y);
    var_v0 = 1;
    return var_v0;
}
