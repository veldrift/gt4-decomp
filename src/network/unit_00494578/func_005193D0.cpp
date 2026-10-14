typedef int s32;
typedef unsigned int u32;
struct A { char pad[4]; s32 f4; char pad2[0xFC]; u32 f104; };
struct B { char pad[4]; s32 f4; };
extern A *D_00854150;
extern "C" B *func_0051B8A8(A *, u32);
extern "C" B *func_00515DD8(s32);
extern "C" void func_0051BAE0(A *, s32);
extern "C" s32 func_005193D0(s32 arg) {
    A *o = D_00854150;
    if (o == 0) return 8;
    B *s1 = func_0051B8A8(o, o->f104);
    if (s1 == 0) return 0x15;
    B *y = func_00515DD8(arg);
    if (y == 0) return 0x1E;
    if (y->f4 != o->f104) return 8;
    s1->f4 = arg;
    func_0051BAE0(o, -1);
    return 0;
}
