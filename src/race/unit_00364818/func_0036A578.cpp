/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;
typedef float f32;

struct Info {
    char pad0;
    u8 count;
    char pad2[0x12];
    u8 b14[0x10];
    u8 b24[0x18];
    signed char c3C[1];
};
struct Params { f32 f0; f32 offset[2]; f32 scale[2]; char pad14[0x10]; f32 gain; };
struct Obj {
    char pad0[0x10C];
    f32 f10C;
    f32 f110;
    char pad114[0xFE0 - 0x114];
    Params params;
};

extern "C" Info *func_00359510(Obj *);

static inline u8 select(Info *info, int idx) {
    u8 result = 0;
    if (idx >= info->count) return result;
    result = info->b14[idx];
    return result;
}
static inline bool enabled(Info *info, int idx) {
    bool result = false;
    if (idx < info->count) result = info->c3C[idx] > 0;
    return result;
}

extern "C" f32 func_0036A578(Obj *self, s32 idx, f32 a, f32 b) {
    Info *info = func_00359510(self);
    u8 sel = select(info, idx);
    f32 r = self->params.offset[sel] + self->params.scale[sel] * b;
    bool flag = enabled(info, idx);
    if (flag != 0) {
        f32 s = self->params.gain;
        if (s != 0.0f) {
            f32 t = a * s;
            if (info->b24[idx] != 0x7F) {
                if (t >= 0.0f) {
                    if (idx == 0)
                        t *= self->f10C;
                    else
                        t = -(self->f110 * t);
                } else {
                    if (idx == 0)
                        t *= self->f110;
                    else
                        t = -(self->f10C * t);
                }
            }
            r += t;
        }
    }
    return r;
}
