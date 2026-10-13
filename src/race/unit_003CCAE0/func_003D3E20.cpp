typedef int s32;
typedef float f32;

struct Obj;

extern "C" s32 func_003D3E40(struct Obj *arg0, f32 fparg0, f32 fparg1);

extern "C" s32 func_003D3E20(struct Obj *arg0, f32 fparg0) {
    return func_003D3E40(arg0, fparg0, 2.0f);
}
