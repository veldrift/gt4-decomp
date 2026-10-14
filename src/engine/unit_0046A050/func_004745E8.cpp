/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
struct Obj { char p0[4]; s32 f4; };
struct S { char p[0x6E14]; Obj *o; };
extern "C" void func_00473380(void *, void *);
extern "C" void func_00473538(void *, int, int, int, int);
extern "C" void func_00473608(void *, int, int, int);
extern "C" void func_00473620(void *, s32, s32, s32);
extern "C" void func_004792B8(void *);
extern "C" void func_004AB040(s32);
extern "C" void func_004745E8(S *self, s32 a1, s32 a2, s32 a3, s32 a4) {
    func_00473620(self->o, a1, a2, a2);
    func_00473608(self->o, a3, a4, 0xFF);
    Obj *t = self->o;
    func_004AB040(2);
    t->f4 = 0;

    func_00473380(self->o, (void *)0x80000000);
    func_00473538(self->o, 0, 0, 0, 0);
    func_004792B8(self);
    func_00473538(self->o, 1, 1, 1, 1);
}
