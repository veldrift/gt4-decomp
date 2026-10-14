/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
typedef int s32;

struct Obj00104AE8 {
    char pad0[0x38];
    f32 unk38;
    char pad3C[0x4];
    s32 unk40;
    s32 unk44;
};

struct Obj00104AE8_00104AE8 {
    char pad0[0xAC];
    s32 unkAC;
};

extern "C" void func_00104368(struct Obj00104AE8 *arg0, struct Obj00104AE8_00104AE8 *arg1, f32 fparg0) throw();
extern "C" int func_0010AE40(void *arg0, f32 arg1);

static inline void setRate(float *f, float v) { *f = v; }

extern "C" void func_00104AE8(struct Obj00104AE8 *arg0, struct Obj00104AE8_00104AE8 *arg1, f32 fparg0) {
    func_00104368(arg0, arg1, fparg0);
    if (arg0->unk40 != 0) {
        if (arg0->unk44 == 0 && arg1->unkAC > 0) {
            setRate(&arg0->unk38, 1.0f);
            arg0->unk44 = 1;
        }
        func_0010AE40(&arg0->unk38, fparg0);
    }
}
