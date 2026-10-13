typedef float f32;
typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

struct func_00364C60_obj {
    char pad0[0x618];
    f32 unk618;
};

typedef struct {
    u8 p0;
    u8 n;
    char pad[0x3A];
    s8 b[1];
} func_00364C60_V;

extern "C" void *func_00359510(struct func_00364C60_obj *arg0);

f32 func_00364C60(struct func_00364C60_obj **arg0, s32 arg1) {
    f32 var_f0;
    s8 temp_s0;
    func_00364C60_V *temp_v0;

    temp_v0 = (func_00364C60_V *)func_00359510((struct func_00364C60_obj *)((char *)*arg0 + 0x600));
    var_f0 = 0.0f;
    if (arg1 < temp_v0->n) {
        temp_s0 = temp_v0->b[arg1];
        var_f0 = (*arg0)->unk618 * 0.5f;
        if (temp_s0 > 0) {
            var_f0 = -var_f0;
        } else if (temp_s0 >= 0) {
            var_f0 = 0.0f;
        }
    }
    return var_f0;
}
