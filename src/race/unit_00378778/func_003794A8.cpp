typedef int s32;
typedef float f32;

struct Obj {
    char pad[0xC];
    f32 unkC;
};

extern "C" void func_00378F18(void *arg0, f32 fparg0, f32 fparg1, f32 fparg2);
extern "C" f32 func_0057D380(f32 x);

extern "C" void func_003794A8(struct Obj *arg0) {
    f32 one = 1.0f;
    f32 t;
    f32 *p = &arg0->unkC;

    t = (one / func_0057D380(*p * 0.5f * 0.017453292f)) * 0.70020754f;
    func_00378F18(arg0, t, one, one / func_0057D380(*p * 0.5f * 0.017453292f));
}
