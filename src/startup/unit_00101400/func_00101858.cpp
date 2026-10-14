/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Fn { void *fn; s32 arg; s32 pad[6]; };
struct Buf { void *ptr; s32 size; };

extern s32 D_00617D80;
extern volatile s32 D_00617D84;
extern char D_006D67E0[];

extern "C" void func_001016E8(void);
extern "C" void func_00100B60(void);
extern "C" void func_00100C38(s32);
extern "C" void func_00100C60(float, float, float);
extern "C" s32 func_00578B50(s32, s32);
extern "C" s32 func_00578610(s32);
extern "C" s32 func_00578968(Fn *, Buf *, s32);
extern "C" void func_005788B8(s32);

extern "C" void func_00101858(void) {
    Fn f;
    Buf b;
    Buf *pb = &b;
    D_00617D84 = 0;
    f.fn = (void *)func_001016E8;
    f.arg = 0;
    pb->ptr = D_006D67E0;
    pb->size = 0x8000;
    s32 r = func_00578968(&f, pb, func_00578610(func_00578B50(4, 0)));
    D_00617D80 = r;
    func_005788B8(r);
    func_00100B60();
    func_00100C60(0.0f, 0.0f, 0.0f);
    func_00100C38(2);
}
