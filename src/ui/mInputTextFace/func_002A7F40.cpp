typedef int s32;

extern char D_0069BA70[];

extern "C" void func_004B80A0(s32 arg0);
extern "C" void func_004B8198(s32 arg0, char *arg1);
extern "C" void func_004B8270(s32 arg0);

extern "C" void func_002A7F40(s32 arg0, char **arg1) {
    s32 temp_s0;
    s32 temp_a1;
    char *var_v1;
    char *obj;

    temp_s0 = arg0 + 0x578;
    func_004B80A0(temp_s0);
    obj = *arg1;
    var_v1 = D_0069BA70;
    temp_a1 = *(s32 *)(obj - 0x10);
    if (temp_a1 != 0) {
        *(char *)(obj + temp_a1) = 0;
        var_v1 = *arg1;
    }
    func_004B8198(temp_s0, var_v1);
    func_004B8270(temp_s0);
}
