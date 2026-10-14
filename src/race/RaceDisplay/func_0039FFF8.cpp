/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef float f32;

struct Sub {
    u8 flag;
    char pad1[0xB];
    f32 f0C;
    char pad10[4];
    char *vtbl;
};

struct VE0 { s16 delta; s16 index; void (*fn)(void *self); };
struct VE1 { s16 delta; s16 index; void (*fn)(void *self, s32 a); };

struct Info {
    char pad[0xC4];
    s32 c4;
    f32 c8;
};

struct Self {
    char pad0[4];
    Info *info;
    char pad8[0x14 - 8];
    Sub *child;
    char pad18[0x58 - 0x18];
    s32 flags;
    char pad5C[0xBC - 0x5C];
    f32 bc;
    char padC0[0x10E4 - 0xC0];
    Sub s10E4;
    char pad10E4[0x228C - 0x10E4 - sizeof(Sub)];
    Sub s228C;
};

extern "C" void func_0039D500(Self *, s32) throw();
extern "C" void func_0039F698(Self *) throw();
extern "C" void func_0039F6E8(Self *) throw();
extern "C" s32 func_003A1EE0(Self *);
extern "C" void RaceSteeringDisplay__update(Sub *);

static inline void vcall28(Sub *s) {
    VE0 *e = (VE0 *)(s->vtbl + 0x28);
    e->fn((char *)s + e->delta);
}

extern "C" void func_0039FFF8(Self *self, s32 arg1) {
    func_0039F698(self);
    if (func_003A1EE0(self) != 0) {
        Sub *s = &self->s10E4;
        if (s->flag != 0) {
            vcall28(s);
        }
        RaceSteeringDisplay__update(s);
    }
    s32 flags = self->flags;
    if (flags & 8) {
        Sub *c = self->child;
        if (c != 0) {
            VE1 *e = (VE1 *)(c->vtbl + 0xB8);
            e->fn((char *)c + e->delta, (flags >> 8) & 1);
            s32 r = 0;
            if (flags & 0x200) {
                r = func_003A1EE0(self) == 0;
            }
            Sub *c2 = self->child;
            VE1 *e2 = (VE1 *)(c2->vtbl + 0xD0);
            e2->fn((char *)c2 + e2->delta, r);
            self->child->f0C = self->bc;
            Sub *c3 = self->child;
            if (c3->flag != 0) {
                VE1 *e3 = (VE1 *)(c3->vtbl + 0x30);
                e3->fn((char *)c3 + e3->delta, arg1);
            }
        }
        Sub *m = &self->s228C;
        if (m->flag != 0) {
            vcall28(m);
        }
    }
    Info *info = self->info;
    if (info->c4 != 0) {
        func_0039D500(self, ((s32)info->c8 + 0x3B) / 60);
    }
    func_0039F6E8(self);
}
