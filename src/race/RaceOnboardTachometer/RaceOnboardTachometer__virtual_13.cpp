/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad0[0xC]; float alpha; char pad1[0x850]; void *texture; };
extern "C" void func_0049D308(void *);
extern "C" void func_0049FE28();
extern "C" void func_004A2808(int, float);
extern "C" void func_004A2B10(float, float);
extern "C" void func_004A2C58(int, int, float);
extern "C" void RaceOnboardTachometer__virtual_13(Obj *self) {
    if (self->texture) {
        func_004A2808(0x64, self->alpha * 0x1.555554p-2f);
        for (int i = 0; i < 2; ++i) {
            func_0049FE28();
            func_004A2C58(2, i, 1.0f);
            func_0049D308(self->texture);
        }
        func_004A2B10(0.5f, 0.5f);
        func_004A2808(0x44, 1.0f);
    }
}
