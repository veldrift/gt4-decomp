/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_004A1638(int);
extern "C" void func_004A2808(int, float);
extern "C" void func_004AB040(int);
extern "C" void mRenderContextPS2__virtual_55(void *self, int kind) {
    switch (kind) {
    case 0:
        func_004A1638(6);
        return func_004A2808(0x44, 1.0f);
    case 1:
        func_004A1638(6);
        return func_004A2808(0x48, 1.0f);
    case 2:
        return func_004AB040(6);
    }
}
