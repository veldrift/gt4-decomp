typedef int s32;
extern "C" void func_0045C718(char *arg0);
extern "C" void func_0045C750(char *arg0);

extern "C" void func_0045C488(char *arg0, float arg1) {
    *(float *)(arg0 + 0x4DC) = arg1;
    *(float *)(arg0 + 0x3A0) = 1.0f;
    *(float *)(arg0 + 0x390) = *(float *)(arg0 + 0x454);
    *(float *)(arg0 + 0x394) = *(float *)(arg0 + 0x458);
    *(float *)(arg0 + 0x398) = *(float *)(arg0 + 0x45C);
    *(float *)(arg0 + 0x39C) = *(float *)(arg0 + 0x474);
    *(float *)(arg0 + 0x3C4) = *(float *)(arg0 + 0x460);
    *(float *)(arg0 + 0x3C8) = *(float *)(arg0 + 0x464);
    *(float *)(arg0 + 0x3CC) = *(float *)(arg0 + 0x468);
    *(float *)(arg0 + 0x3D0) = *(float *)(arg0 + 0x480);
    *(s32 *)(arg0 + 0x434) = 0;
    *(s32 *)(arg0 + 0x438) = 0;
    *(s32 *)(arg0 + 0x440) = 0;
    *(s32 *)(arg0 + 0x43C) = 0;
    *(s32 *)(arg0 + 0x444) = 0;
    *(s32 *)(arg0 + 0x448) = 0;
    *(s32 *)(arg0 + 0x38C) = 0;
    if (*(s32 *)(arg0 + 0x3EC) != 0) {
        return func_0045C718(arg0);
    }
    *(s32 *)(arg0 + 0x3EC) = 1;
    func_0045C750(arg0);
}
