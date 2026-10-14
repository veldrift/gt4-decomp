typedef int s32;

extern "C" void func_001D6E80(void *arg0, int arg1);
extern "C" void func_001D6ED8(void *arg0, void *arg1);
extern "C" void func_001D9E68(char *a0, char *a1);
extern "C" void func_00221AD0(void *arg0, int arg1);
extern "C" void func_00221B28(void *arg0, void *arg1);

extern "C" void MHttp__setProxyByNetConf(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 buf0[4];
    s32 spare[4];
    s32 buf1[4];

    if (arg2 > 0) {
        func_001D6ED8(buf0, (void *)arg1);
        s32 base0 = buf0[0];
        s32 *p1 = buf1;
        func_00221B28(p1, (void *)arg3);
        func_001D9E68((char *)base0, (char *)(p1[0] + 0x10));
        func_00221AD0(p1, 2);
        func_001D6E80(buf0, 2);
    }
}
