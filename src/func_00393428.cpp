extern int D_006213E8;
extern "C" float func_00391CD8(void);
extern "C" void func_00463378(void *a, void *b, unsigned int c, float x, float y);

extern "C" void func_00393428(void *a, void *b, float x, float y) {
    if (D_006213E8 == 0) {
        float s = func_00391CD8();
        func_00463378(a, b, 0x7FFFFFFF, x * s, y);
    }
}
