typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
typedef float f32;

struct Sub { u8 pad[0x18]; f32 f; };
struct Obj { u8 pad[0x10]; Sub *s; };
struct V { u8 p0; u8 n; u8 pad[0x12]; u8 b[1]; };

extern "C" void *func_00359510(void *arg0);

extern "C" f32 func_00344C08(Obj *arg0, s32 arg1) {
    f32 var_f0;
    V *temp_v0;
    s8 temp_s0;
    s8 *e;

    temp_v0 = (V *)func_00359510(arg0->s);
    var_f0 = 0.0f;
    e = (s8 *)(arg1 + (s32)temp_v0);
    if (arg1 < temp_v0->n) {
        var_f0 = arg0->s->f * 0.5f;
        temp_s0 = e[0x3C];
        if (temp_s0 > 0) {
            var_f0 = -var_f0;
        } else if (temp_s0 < 0) {
            /* keep the scaled value */
        } else {
            var_f0 = 0.0f;
        }
    }
    return var_f0;
}
