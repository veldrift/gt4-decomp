typedef int s32;

extern char D_00698BB0[];

extern "C" void func_0020D1B8(void *arg0, s32 arg1);
extern "C" void func_0020D738(void *arg0, void *arg1, s32 arg2, s32 arg3, void *arg4);
extern "C" void func_002319A0(s32 arg0, void *arg1);
extern "C" void func_0023DDF0(void *arg0, s32 arg1);
extern "C" void func_0023F8C8(s32 arg0, char *arg1);
extern "C" void func_0023FB80(void *arg0);

extern "C" void func_00238978(char *arg0, s32 arg1) {
    s32 buf;
    if (*(s32 *)(arg0 + 0x104) == 0) {
        func_0023FB80(&buf);
        func_0023F8C8(buf, D_00698BB0);
        func_0023DDF0(&buf, 2);
    }
    char *v = arg0 + 0xF8;
    if (*(s32 *)v != 0) {
        func_0020D738(&buf, v, 2, arg1, arg0);
        func_002319A0(arg1, &buf);
        func_0020D1B8(&buf, 2);
    }
}
