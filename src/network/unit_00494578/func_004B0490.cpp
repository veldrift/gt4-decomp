typedef int s32;

extern "C" void func_00574EB0(void *arg0);
extern "C" void func_00574EE8(void *arg0);

struct func_004B0490_S8 {
    s32 a;
    s32 b;
};

extern "C" void func_004B0490(void *arg0) {
    char *p = (char *)arg0;
    if (*(s32 *)(p + 0x3294) != 0) {
        struct func_004B0490_S8 z;
        z.a = 0;
        z.b = 0;
        *(struct func_004B0490_S8 *)(p + 0x32A4) = z;
        func_00574EE8(p + 0x3230);
        func_00574EB0(p + 0x31A0);
        *(s32 *)(p + 0x3294) = 0;
    }
}
