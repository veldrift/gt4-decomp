/* compiler: ee-gcc2.96-nogcse */
typedef int s32;
typedef unsigned char u8;

extern "C" s32 func_0057F260(const u8 *arg0);

extern "C" void func_002A6B88(char *arg0, const u8 *arg1) {
    s32 temp_a2;
    s32 temp_v0;
    s32 var_a1;
    unsigned int var_a3;
    s32 temp_t0;

    temp_v0 = func_0057F260(arg1);
    temp_a2 = (temp_v0 >= 0x40) ? 0x3F : temp_v0;
    var_a1 = 0;
    if (temp_a2 > 0) {
        var_a3 = (s32)(arg0 + 0xC);
        temp_t0 = var_a3;
        do {
            u8 temp_a0 = arg1[var_a1];
            s32 temp_v0_2 = var_a1 + (*(s32 *)(arg0 + 0x56C) << 6);
            var_a1 += 1;
            *(u8 *)(temp_v0_2 + temp_t0 + 0x160) = temp_a0;
        } while (var_a1 < temp_a2);
    } else {
        var_a3 = (s32)(arg0 + 0xC);
    }
    *(u8 *)((var_a1 + (*(s32 *)(arg0 + 0x56C) << 6)) + var_a3 + 0x160) = 0;
    {
        s32 temp_v1 = *(s32 *)(arg0 + 0x56C) + 1;
        *(s32 *)(arg0 + 0x56C) = temp_v1;
        if (temp_v1 >= 0x10) {
            *(s32 *)(arg0 + 0x56C) = 0;
        }
    }
    {
        s32 temp_v1_2 = *(s32 *)(arg0 + 0x570);
        if (temp_v1_2 < 0x10) {
            *(s32 *)(arg0 + 0x570) = temp_v1_2 + 1;
        }
    }
}
