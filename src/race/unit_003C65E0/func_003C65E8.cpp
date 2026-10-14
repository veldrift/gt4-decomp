typedef int s32;

struct Elem64 { char p[64]; };
struct Elem16 { char p[16]; };
struct Inner { char pad[0x7C]; s32 *f7C; };
struct Obj {
    char pad0[4];
    s32 f4;
    char pad8[0xC];
    Inner *f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
};

extern "C" void func_003C6718(void *, s32);
extern "C" void func_003C67A8(void *, s32);
extern "C" void func_00454410(void *);
extern "C" void func_00454698(s32, s32 *, s32, s32);

extern "C" void func_003C65E8(Obj *self) {
    s32 d = (s32)self - self->f4;
    if (d != 0) {
        s32 i;
        Inner **p = &self->f14;
        *p = (Inner *)((char *)*p + d);
        func_00454410(*p);
        func_00454698(*(*p)->f7C, (*p)->f7C, 0, 0);
        if (self->f1C != 0) {
            s32 *q = &self->f1C;
            *q += d;
            for (i = 0; i < self->f18; i++)
                func_003C6718((void *)(self->f1C + i * 64), d);
        }
        if (self->f24 != 0) {
            s32 *q = &self->f24;
            *q += d;
            for (i = 0; i < self->f20; i++)
                func_003C67A8((void *)(self->f24 + i * 16), d);
        }
    }
}
