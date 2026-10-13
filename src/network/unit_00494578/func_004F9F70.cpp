typedef int s32;

extern "C" s32 func_004FA178(void *, s32);
extern "C" void func_00576100(char *);
extern "C" void func_00576140(char *);

extern "C" char *func_004F9F70(char *arg0, s32 arg1) {
    char *var_s2;
    s32 idx;
    s32 off;
    s32 *temp_v1;

    var_s2 = 0;
    idx = func_004FA178(arg0, arg1);
    if (idx != -1) {
        var_s2 = arg0 + idx * 0xE4 + 0x2288;
        func_00576100(arg0);
        *(s32 *)(arg0 + 0x223C) = *(s32 *)(arg0 + 0x223C) + 1;
        off = idx * 4;
        off = off + 0x2240;
        temp_v1 = (s32 *)(arg0 + off);
        *temp_v1 = *temp_v1 + 1;
        func_00576140(arg0);
    }
    return var_s2;
}
