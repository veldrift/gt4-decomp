typedef int s32;
typedef float f32;
struct Obj {
    char pad0[0x50];
    f32 f50;
    char pad1[0x60 - 0x54];
    s32 i60;
    f32 f64;
};
extern "C" void func_00154330(Obj *o, s32 a) {
    if (a) {
        o->f50 = 1.0f;
        o->f64 = 0.0083333333f;
    } else {
        o->f50 = 0;
        o->f64 = -0.0083333333f;
    }
    o->i60 = 0;
}
