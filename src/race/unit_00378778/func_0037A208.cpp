/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
typedef int s32;
typedef unsigned char u8;

struct Cam { char pad0[0xC]; f32 fC; char pad1[0x24 - 0x10]; f32 f24; char pad2[0x266 - 0x28]; u8 m266; };
struct S {
    long long q0;
    char pad0[0x4C - 8];
    f32 f4C;
    char pad1[0x80 - 0x50];
};

extern "C" void func_00379AA8(Cam *, f32) throw();
extern "C" void func_003FB4C0(S *, u8);

extern "C" void func_0037A208(Cam *cam, S *src) {
    S loc = *src;
    loc.f4C = cam->f24;
    func_003FB4C0(&loc, cam->m266);
    func_00379AA8(cam, cam->fC);
}
