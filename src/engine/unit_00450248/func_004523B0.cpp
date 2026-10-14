typedef int s32;
typedef float f32;

struct Args {
    f32 a;
    f32 b;
    f32 c;
    s32 d;
};

extern "C" void func_004A7AA8(void *arg0, Args *args);
extern "C" char D_008465A0[];

extern "C" void func_004523B0(f32 fparg0, f32 fparg1, f32 fparg2) {
    Args args;
    args.a = fparg0;
    args.b = fparg1;
    args.c = fparg2;
    args.d = 0;
    func_004A7AA8(D_008465A0, &args);
}
