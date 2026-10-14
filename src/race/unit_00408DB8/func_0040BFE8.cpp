/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
typedef unsigned char u8;

struct Info {
    char pad0;
    u8 count;
    char pad2[0x12];
    u8 ids[1];
};

struct Obj {
    char pad[0x10];
    char *slots;
};

extern "C" Info *func_00359538(Obj *);
extern "C" f32 func_003447F8(Obj *, f32);

extern "C" f32 func_0040BFE8(s32 unused, Obj *o, s32 idx, f32 f) {
    Info *info = func_00359538(o);
    u8 v = 0;
    char *slots = o->slots;
    if (idx < info->count) {
        v = info->ids[idx];
    }
    f32 base = *(f32 *)(slots + v * 0x58 + 0x308);
    return func_003447F8(o, 0.0f) - base - f + 0.1f;
}
