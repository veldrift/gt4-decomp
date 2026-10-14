typedef short s16;
typedef unsigned char u8;
typedef int s32;

struct VEntry0 { s16 delta; s16 index; void (*fn)(void *self); };
struct VEntry1 { s16 delta; s16 index; void (*fn)(void *self, s32 a); };

struct Sub {
    u8 flag;
    char pad[0x13];
    char *vtbl;
};

struct Obj {
    char *vtbl;
    char pad0[0x3D - 4];
    u8 f3D;
    char pad1[0x58 - 0x3E];
    s32 flags;
    char pad2[0x11B0 - 0x5C];
    Sub s11B0;
    char pad3[0x2A6C - 0x11B0 - sizeof(Sub)];
    Sub s2A6C;
    char pad4[0x2BBC - 0x2A6C - sizeof(Sub)];
    Sub s2BBC;
    char pad5[0x2D78 - 0x2BBC - sizeof(Sub)];
    Sub s2D78;
};

extern "C" void func_0039FC50(Obj *);
extern "C" void func_0039FC88(Obj *);
extern "C" void func_0039FCB0(Obj *, s32);
extern "C" void func_0039FD30(Obj *, s32);
extern "C" void func_0039FF78(Obj *);
extern "C" void func_0039FFF8(Obj *, s32);
extern "C" void func_003A0178(Obj *);
extern "C" void RaceMessageDisplay__render_main(void *);
extern "C" void RaceMusicDisplay__render_main(void *);

static inline void sub_call0(Sub *s) {
    VEntry0 *e = (VEntry0 *)(s->vtbl + 0x28);
    e->fn((char *)s + e->delta);
}

extern "C" void func_0039F878(Obj *self, s32 arg1) {
    s32 flags = self->flags;
    if (flags & 2) {
        func_0039FC88(self);
    }
    if (flags & 0x40) {
        func_0039FCB0(self, arg1);
    }
    if (flags & 0x20) {
        func_0039FD30(self, arg1);
    }
    if (flags & 0x10) {
        VEntry0 *e = (VEntry0 *)(self->vtbl + 0xC8);
        e->fn((char *)self + e->delta);
        func_0039FF78(self);
    }
    func_0039FFF8(self, arg1);
    if ((flags & 0x80) || self->f3D != 0) {
        func_003A0178(self);
    }
    Sub *q = &self->s2D78;
    if (q->flag != 0) {
        VEntry1 *e = (VEntry1 *)(q->vtbl + 0x30);
        e->fn((char *)q + e->delta, arg1);
    }
    Sub *s = &self->s11B0;
    if (s->flag != 0) {
        sub_call0(s);
    }
    if ((flags & ~0x80) == 0) {
        func_0039FC50(self);
        RaceMusicDisplay__render_main((char *)self + 0x3EEC);
    }
    s = &self->s2A6C;
    if (s->flag != 0) {
        sub_call0(s);
    }
    s = &self->s2BBC;
    if (s->flag != 0) {
        sub_call0(s);
    }
    RaceMessageDisplay__render_main((char *)self + 0x267C);
    RaceMessageDisplay__render_main((char *)self + 0x27CC);
}
