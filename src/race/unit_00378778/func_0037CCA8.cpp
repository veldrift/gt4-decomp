/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Inner { char pad[0x18]; void *unk18; };
struct Obj {
    char pad0[8];
    f32 m8;
    f32 mC;
    char pad1[0x180 - 0x10];
    Inner *m180;
    f32 m184;
};

extern f32 D_006211F4;
extern f32 D_006211F8;
extern f32 D_006211FC;

extern "C" f32 func_00344798(void *, f32);
extern "C" f32 func_003447F8(void *, f32);
extern "C" f32 func_00344828(void *, f32);
extern "C" float func_0036EAD8(float) throw();
extern "C" void func_004A0690(void);
extern "C" void func_004A06F0(void);
extern "C" void func_004A53F8(void);
extern "C" void func_004A5400(void);
extern "C" void func_004A7454(void);
extern "C" void func_004A7550(void *);
extern "C" void func_004A7844(f32, f32, f32);
extern "C" void func_004A7988(f32);
extern "C" void func_004A79B0(float);

extern "C" s32 func_0037CCA8(Obj *o) {
    void *t = o->m180->unk18;
    o->m184 = func_0036EAD8(o->m184 + 0.5f);
    func_004A0690();
    func_004A53F8();
    func_004A7454();
    func_004A7844(0.0f, 0.0f, -D_006211FC);
    func_004A7988(D_006211F8);
    func_004A79B0(o->m184);
    f32 a = -func_00344798(t, 0.0f);
    f32 b = -func_003447F8(t, 0.0f);
    func_004A7844(a, b, -func_00344828(t, 0.0f));
    func_004A7550((char *)o + 0x100);
    func_004A5400();
    func_004A06F0();
    o->m8 = D_006211FC;
    o->mC = D_006211F4;
    return 1;
}
