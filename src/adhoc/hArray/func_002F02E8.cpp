typedef int s32;
typedef unsigned int u32;

extern "C" void func_00309378(void *arg0, s32 arg1);
extern "C" void func_003285A8(void *arg0);
extern "C" void func_003285F8(void *arg0);

extern "C" void func_002F02E8(s32 arg0, u32 arg1) {
    s32 temp_s4;
    s32 temp_a0;
    s32 temp_v1;
    s32 temp_v0;
    s32 temp_v1_2;
    s32 var_s1;
    s32 var_s2;
    s32 var_s3;
    s32 temp_s0;
    s32 temp_v0_2;
    s32 temp_a0_2;

    temp_s4 = arg0 + 0x10;
    temp_a0 = *(s32 *)(temp_s4 + 8);
    temp_v1 = *(s32 *)(temp_s4 + 4);
    if (arg1 < (u32)((s32)(temp_a0 - temp_v1) >> 2)) {
        temp_v0 = temp_v1 + (arg1 * 4);
        temp_v1_2 = temp_v0 + 4;
        if (temp_v1_2 != temp_a0) {
            var_s2 = temp_v1_2;
            var_s1 = temp_v0;
            var_s3 = (s32)(temp_a0 - var_s2) >> 2;
            if (var_s3 > 0) {
                do {
                    if (var_s1 != var_s2) {
                        temp_s0 = *(s32 *)var_s2;
                        if (temp_s0 != 0) {
                            func_003285A8((void *)temp_s0);
                        }
                        temp_v0_2 = *(s32 *)var_s1;
                        if (temp_v0_2 != 0) {
                            func_003285F8((void *)temp_v0_2);
                        }
                        *(s32 *)var_s1 = temp_s0;
                    }
                    var_s3 -= 1;
                    var_s2 += 4;
                    var_s1 += 4;
                } while (var_s3 > 0);
            }
        }
        temp_a0_2 = *(s32 *)(temp_s4 + 8) - 4;
        *(s32 *)(temp_s4 + 8) = temp_a0_2;
        func_00309378((void *)temp_a0_2, 2);
    }
}
