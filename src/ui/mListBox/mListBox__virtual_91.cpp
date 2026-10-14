typedef int s32;
typedef unsigned long long u64;
struct VEntry {
    short delta;
    short index;
    void *fn;
};
struct Obj {
    char pad0[0x124];
    s32 u124;
    char pad128[0x14];
    s32 u13C;
    s32 u140;
};
extern char D_008381C8[];
extern "C" void mBox__virtual_91(Obj *, s32);
extern "C" s32 func_00265DC8(Obj *);
extern "C" u64 func_00266088(void *);
extern "C" void func_00266100(Obj *, u64);
extern "C" u64 func_00266128(void *);
extern "C" void func_002661A0(Obj *, u64);
extern "C" void *func_002B4DA0(Obj *, s32, s32);
extern "C" void func_00576788(char *);
extern "C" void func_005767C0(char *);

extern "C" void mListBox__virtual_91(Obj *self, s32 arg1) {
    mBox__virtual_91(self, arg1);
    u64 s3 = func_00266088(self);
    u64 s4 = func_00266128(self);
    if (func_00265DC8(self) != 0 && self->u124 >= 0) {
        func_00576788(D_008381C8);
        s32 i;
        for (i = self->u13C; i <= self->u140; i++) {
            void *w = func_002B4DA0(self, i, 0);
            if (w != 0) {
                VEntry *e = (VEntry *)(*(char **)((char *)w + 4) + 0x2E0);
                ((void (*)(void *, s32))e->fn)((char *)w + e->delta, arg1);
                if (func_00266088(w) != 0) s3 = 1;
                if (func_00266128(w) != 0) s4 = 1;
            }
        }
        func_005767C0(D_008381C8);
    }
    func_00266100(self, s3);
    func_002661A0(self, s4);
}
