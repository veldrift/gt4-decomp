typedef int s32;

struct P8 {
    s32 a;
    s32 b;
};

extern "C" void func_00574EE8(void *arg0);

extern "C" void func_004B04E8(void *arg0) {
    s32 idx = *(s32 *)((char *)arg0 + 0x3094);
    s32 off = idx * 8;
    char *e = (char *)(off + (s32)arg0);
    *(struct P8 *)((char *)arg0 + 0x329C) = *(struct P8 *)(e + 0x3084);
    func_00574EE8((char *)arg0 + 0x31D0);
}
