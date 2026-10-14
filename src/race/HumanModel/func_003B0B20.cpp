/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef float f32;

struct Pair { u16 a,b; Pair &operator=(const Pair &o) { const u16 *q=&o.b; u16 *p=&b; p[-1]=q[-1]; p[0]=q[0]; return *this; } };
struct VE { s16 d; s16 i; void (*fn)(void *); };
struct Sub {
    char pad[0x760];
    s32 words[20];
    char pad2[0x10];
    f32 vec[3];
    s32 word(int i) { return words[i]; }
    void setword(int i, s32 val) { words[i] = val; }
    f32 v(int i) { return vec[i]; }
    void setv(int i, f32 val) { vec[i] = val; }
};
struct HM {
    s32 f0;
    char pad4[0xC];
    char f10[0x6B0 - 0x10 + 4];
    s32 f6B4;
    s32 f6B8;
    char pad6BC[4];
    char f6C0[0x48];
    f32 f708;
    f32 f70C;
    Pair f710[20];
    u16 f760;
    u16 f762;
    s32 f764[20];
    char pad7B4[0];
    s32 f7B4;
    s32 f7B8;
    s32 f7BC;
    s32 f7C0;
    f32 f7C4[3];
    f32 f7D0[3];
    char *vptr;
};

extern "C" void *func_003B08F8(void *, void *) throw();
extern "C" void func_003B0848(void *, void *) throw();
extern "C" void func_003B0F00(void *);

extern "C" HM *func_003B0B20(HM *self, HM *o) {
    VE *ve = (VE *)(self->vptr + 0x20);
    s32 i;
    ve->fn((char *)self + ve->d);
    self->f0 = o->f0;
    func_003B08F8(self->f10, o->f10);
    func_003B0F00(self);
    self->f6B4 = o->f6B4;
    self->f6B8 = o->f6B8;
    func_003B0848(self->f6C0, o->f6C0);
    self->f708 = o->f708;
    self->f70C = o->f70C;
    for (i = 0; i < 20; i++) {
        self->f710[i] = o->f710[i];
        ((Sub *)((char *)self + 4))->setword(i, ((Sub *)((char *)o + 4))->word(i));
    }
    self->f760 = o->f760;
    self->f762 = o->f762;
    self->f7B4 = o->f7B4;
    self->f7B8 = o->f7B8;
    self->f7C0 = o->f7C0;
    for (i = 0; i < 3; i++) {
        ((Sub *)((char *)self + 4))->setv(i, ((Sub *)((char *)o + 4))->v(i));
        self->f7D0[i] = o->f7D0[i];
    }
    self->f7BC = 1;
    return self;
}
