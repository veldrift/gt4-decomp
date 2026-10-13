typedef float f32;

extern "C" void func_003A9850(char *o, f32 t);

extern "C" void func_003BD4A8(char *self) {
    f32 zero = 0.0f;
    func_003A9850(self + 0x14D0, zero);
    func_003A9850(self + 0x15B0, zero);
}
