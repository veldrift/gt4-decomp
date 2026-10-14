/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Obj {
    char pad0[0x18]; s32 f18; char pad1[0x2C - 0x1C]; char f2C[0x30];
    char pad2[0x17C - 0x5C]; float f17C[8]; float pad4[0x19C - 0x19C]; float f19C; char pad3[0x1A8 - 0x1A0]; float f1A8;
};
extern "C" s32 func_00429360(char *, s32, const char *, float *, float, float);
extern "C" void func_001D5408(Obj *o) {
    float v = 0.0f;
    float z = v;
    for (s32 i = 0; i < 2; i++) {
        const char *a[4] = {"shadowDarkness0", "shadowDarkness1", "shadowDarkness2", "shadowDarkness3"};
        const char *b[4] = {"shadowBlur0", "shadowBlur1", "shadowBlur2", "shadowBlur3"};
        func_00429360(o->f2C, o->f18, a[i], &v, o->f1A8, z);
        o->f17C[i + 4] = (v < z) ? z : v;
        func_00429360(o->f2C, o->f18, b[i], &v, o->f1A8, 0.0f);
        o->f17C[i] = v;
    }
    func_00429360(o->f2C, o->f18, "bottomShadow", &v, o->f1A8, 0.0f);
    o->f19C = (v < 0.0f) ? 0.0f : v;
}
