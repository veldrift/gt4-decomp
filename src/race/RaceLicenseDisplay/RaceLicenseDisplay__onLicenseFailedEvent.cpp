typedef int s32;
typedef float f32;

extern "C" void func_003A98A0(void *self, f32 t);

extern "C" void func_003BD438(char *arg0) {
    char *p;
    s32 i;

    func_003A98A0(arg0 + 0xBC, 0x1.000000p-2f);
    p = arg0 + 0x423C;
    i = 4;
    do {
        char *temp_a0 = p;
        i = i - 1;
        p += 0x1C;
        func_003A98A0(temp_a0, 0x1.000000p-2f);
    } while (i >= 0);
}
