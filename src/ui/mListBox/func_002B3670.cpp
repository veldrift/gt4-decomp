typedef int s32;
typedef float f32;
typedef unsigned long long u64;
struct Item {
    char pad0[0xC];
    f32 f0C;
    f32 f10;
    f32 f14;
    f32 f18;
};
struct Obj {
    char pad0[0x11C];
    s32 u11C;
    char pad120[4];
    s32 u124;
    char pad128[0x24];
    s32 u14C;
    char pad150[4];
    char *u154;
};
extern char D_0069C038[];
extern "C" void func_00207378(void *, void *, void *);
extern "C" void func_00230B68(void *, void *);
extern "C" void func_0023DDF0(void *, int);
extern "C" void func_0023F8C8(s32, const char *);
extern "C" void func_0023FB80(void *);
extern "C" void func_0025B538(void *, f32, f32, f32, f32);
extern "C" void func_00265E50(void *, s32);
extern "C" void mWidget__setActive(void *, s32);
extern "C" u64 func_00266088(Obj *);
extern "C" void func_00266200(void *, s32);
extern "C" Item *func_002B49B8(Obj *, s32);
extern "C" s32 mListBox__get_total_item_count(Obj *);
extern "C" void *func_002B4DA0(Obj *, s32, s32);
extern "C" void *func_002B50F0(Obj *);
extern "C" s32 func_002B52F8(Obj *, s32);
extern "C" s32 mListBox__getItemActive(Obj *, s32);
extern "C" s32 func_002B5580(Obj *, s32);

extern "C" void func_002B3670(Obj *self, s32 idx, void *arg2) {
    void *w = func_002B4DA0(self, idx, 0);
    if (w == 0) w = func_002B50F0(self);
    if (idx < mListBox__get_total_item_count(self)) {
        Item *a = func_002B49B8(self, idx);
        Item *b = func_002B49B8(self, idx);
        Item *c = func_002B49B8(self, idx);
        func_0025B538(w, a->f0C, b->f10, c->f14, func_002B49B8(self, idx)->f18);
        func_00265E50(w, func_002B52F8(self, idx));
        mWidget__setActive(w, mListBox__getItemActive(self, idx));
        func_00266200(w, func_002B5580(self, idx));
        func_00207378(self, arg2, w);
    }
    if (func_00266088(self) != 0) {
        if (idx == self->u124) {
            if (self->u14C == 2) {
                char **pp = &self->u154;
                if (*(s32 *)(*pp - 0x10) != 0) {
                    s32 x[4];
                    func_0023FB80(x);
                    s32 xv = x[0];
                    const char *str;
                    s32 len = *(s32 *)(*pp - 0x10);
                    if (len == 0) {
                        str = D_0069C038;
                    } else {
                        (*pp)[len] = 0;
                        str = *pp;
                    }
                    func_0023F8C8(xv, str);
                    func_0023DDF0(x, 2);
                }
            }
            self->u14C = 0;
            func_00230B68(arg2, self->u11C == 0 ? w : (void *)self->u11C);
        }
    }
}
