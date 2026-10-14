/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct VEntry {
    short delta;
    short index;
    void *fn;
};
#define VCALL0(R, o, off) ({ VEntry *e_ = (VEntry *)(*(char **)((char *)(o) + 4) + (off)); ((R(*)(void *))e_->fn)((char *)(o) + e_->delta); })
#define VCALL1(R, o, off, a) ({ VEntry *e_ = (VEntry *)(*(char **)((char *)(o) + 4) + (off)); ((R(*)(void *, ...))e_->fn)((char *)(o) + e_->delta, a); })

struct Obj;
typedef void (Obj::*PM)(void *);
struct Obj {
    char pad0[0xA8];
    void *unkA8;
    void *unkAC;
    char padB0[8];
    s32 unkB8;
    char padBC[0x18];
    PM pmf;
};
extern "C" void func_001598B8(Obj *self, void *arg1, void *arg2) throw();
extern "C" void mWidget__virtual_70(Obj *self, void *arg1, s32 arg2);

extern "C" void mColorChipFace__virtual_70(Obj *self, void *arg1, s32 flag) {
    mWidget__virtual_70(self, arg1, 0);
    if (flag != 0) {
        if (self->pmf != 0) {
            VCALL1(void, arg1, 0x1C0, 0);
            (self->*(self->pmf))(arg1);
            VCALL0(void, arg1, 0x1C8);
            if (self->unkB8 != 0) {
                return func_001598B8(self, arg1, self->unkA8);
            }
            func_001598B8(self, arg1, self->unkAC);
        }
    }
}
