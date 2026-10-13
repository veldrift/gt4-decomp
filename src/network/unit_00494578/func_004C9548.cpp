/* compiler: ee-gcc2.96-nsa-nosib */
typedef int s32;

s32 func_004C9548(s32 *arg0) {
    s32 *var_a0;
    s32 temp_v0;
    s32 var_a1;

    var_a0 = arg0;
    var_a1 = 9;
    do {
        s32 temp_v1 = *var_a0;
        var_a0 += 1;
        if (temp_v1 != 0) {
            return 0;
        }
        temp_v0 = var_a1;
        var_a1 -= 1;
    } while (temp_v0 > 0);
    return 1;
}
