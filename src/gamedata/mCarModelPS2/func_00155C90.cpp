/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Sub { char pad[0x30]; void *f30; };
struct Arg { char pad[0x4C]; Sub *f4C; char pad50[0x34]; s32 f84; };
extern "C" void func_00154C18(void *) throw();
extern "C" void func_00154CE0(void *,void *) throw();
extern "C" s32 func_001564D8(void *);
extern "C" void func_00453488(void *,void *);
extern "C" void func_00454410(void *);
extern "C" void func_004AFD50(void *);
extern "C" void free(void *) throw();
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" void func_005ADF20(s32);
extern "C" void func_00155C90(char *self, Arg *arg) {
    char *lock = self + 0xEC;
    void *old = 0;
    func_00576788(lock);
    *(s32 *)(self + 0x150) = 0;
    Sub *sub = arg->f4C;
    if (arg->f84 == 0) {
        void *p = sub->f30;
        func_00454410(p);
        *(s32 *)(self + 0x19C) = 0;
        func_00154CE0(self + 0x1B4,self + 0x18C);
        old = *(void **)(self + 0x8A4);
        *(void **)(self + 0x8A4) = p;
        func_00453488(self + 0x2A4,p);
        func_005ADF20(0);
        *(s32 *)(self + 0x19C) = 1;
        *(s32 *)(self + 0x1D4) = 1;
        if (*(s32 *)(self + 0x1D8)) func_001564D8(self);
    } else {
        func_004AFD50(sub);
    }
    func_005767C0(lock);
    if (old) {
        if (*(s32 *)(self + 0x160) == 0) func_00154C18(self + 0x1B4);
        free(old);
    }
}
