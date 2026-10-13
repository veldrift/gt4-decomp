typedef int s32;
typedef float f32;

struct F64 {
    f32 v[64];
};

extern "C" {
void func_004071D8(void *, f32);                 /* extern */
s32 func_00407208(s32, void *);                  /* extern */
}

extern "C" s32 func_00407238(s32 arg0, s32 arg1, s32 arg2, f32 fparg0) {
    f32 sp[64];
    F64 *p1 = (F64 *)arg1;
    F64 *p2 = (F64 *)arg2;
    s32 i;

    func_004071D8((void *)sp, 0.0f);
    for (i = 0; i < 0x40; i++) {
        sp[i] = p1->v[i] * (1.0f - fparg0) + p2->v[i] * fparg0;
    }
    func_00407208(arg0, (void *)sp);
    return arg0;
}
