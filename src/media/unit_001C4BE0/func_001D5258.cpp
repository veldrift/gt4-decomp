/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Obj {
    char pad0[0x18]; s32 f18; s32 f1C; char pad1[0x2C - 0x20]; char f2C[0x30]; float f5C[0x144 / 4];
    char pad2[0x1A0 - 0x5C - 0x144]; float f1A0; float f1A4; float f1A8;
};
extern "C" s32 func_00429360(char *, s32, const char *, float *, float, float);
extern "C" void func_001D5258(Obj *o) {
    s32 i;
    for (i = 0; i < o->f1C; i++) {
        const char *names[8] = {"Alpha0", "Alpha1", "Alpha2", "Alpha3", "Alpha4", "Alpha5", "Alpha6", "Alpha7"};
        float v = 0.0f;
        if (func_00429360(o->f2C, o->f18, names[i], &v, o->f1A8, 0.0f)) {
            o->f5C[i] = (v < 0.0f) ? 0.0f : v;
        } else {
            o->f5C[i] = 0.0f;
        }
    }
    float v;
    func_00429360(o->f2C, o->f18, "BlackLevel", &v, o->f1A8, 0.0f);
    o->f1A0 = (v < 0.0f) ? 0.0f : v;
    func_00429360(o->f2C, o->f18, "WhiteLevel", &v, o->f1A8, 0.0f);
    o->f1A4 = (v < 0.0f) ? 0.0f : v;
}
