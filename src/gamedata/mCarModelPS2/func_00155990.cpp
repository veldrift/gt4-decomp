typedef int s32;
extern "C" float func_00364D78(void *, s32);
extern "C" float func_00364D20(void *, s32);
extern "C" float func_00364DD0(void *, s32);
extern "C" void func_00450F50(void *, s32, float, float, float);
extern "C" void func_00155990(void *self, s32 arg1) {
    s32 start = arg1 == 0 ? 2 : 0;
    for (s32 i = 0; i < 2; ++i) {
        s32 idx = i + start;
        float a = func_00364D78((char *)self + 0x864, idx);
        float b = func_00364D20((char *)self + 0x864, idx);
        float c = func_00364DD0((char *)self + 0x864, idx);
        func_00450F50((char *)self + 0x2A4, idx, a, b, c);
    }
}
