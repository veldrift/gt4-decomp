typedef int s32;
typedef unsigned short u16;
typedef float f32;

struct V { s32 w[6]; };
struct Vec { s32 n; V *begin; V *end; };
struct Owner { char pad[0xA8]; s32 fA8; };
struct Node { char pad[4]; s32 *list; };
struct Src { char pad[2]; u16 count; s32 *list; };
struct Slot { s32 a; s32 b; s32 c; Owner *o; };
struct Frame {
    char buf[0x3000];
    s32 cnt;
    s32 pad3004;
    char obj[0x584];
    Owner *owner;
    s32 z;
    char pad3594[0xC];
    Vec v;
    s32 pad35AC;
    char o35B0[0x10];
    s32 s35C0;
    s32 s35C4;
    char pad35C8[8];
    s32 s35D0;
    Owner *s35D4;
};

extern "C" void func_003C6B08(s32, void *);
extern "C" void func_0049C6C8(s32, V *, s32, s32, s32);
extern "C" void func_004A53F8(void);
extern "C" void func_004A5400(void);
extern "C" V *func_004A5B70(s32);
extern "C" void func_004A7988(f32);
extern "C" void func_004AA1D8(f32, f32, f32, f32);
extern "C" void func_004AB040(s32);
extern "C" s32 func_005FBFB0(void *, void *, s32);
extern "C" Owner *func_005FC048(void *);
extern "C" void func_005FC070(void *);
extern "C" void *func_005FC0A8(void *, void *, void *, void *);
extern "C" void func_005FC150(void *, void *);

extern "C" void func_003C6860(Src *src, f32 a, f32 b, f32 c, f32 d) {
    Frame f;
    s32 i = 0;
    f.cnt = 0;
    func_005FC070(f.obj);
    f.owner = func_005FC048(f.obj);
    f.z = 0;
    for (i = 0; i < src->count; i++) {
        func_003C6B08(src->list[i], &f);
    }
    Vec *pv = &f.v;
    pv->n = f.cnt + src->count * 2 - 4;
    pv->end = pv->begin = func_004A5B70((pv->n * 0x18 + 0xF) >> 4);
    func_004AA1D8(a, b, c, d);
    func_004AB040(0xF);
    func_004AB040(2);
    func_005FBFB0(&f, pv, 0x4000);
    func_004A53F8();
    func_004A7988(90.0f);
    func_0049C6C8(((s32 *)f.v.end - (s32 *)f.v.begin) / 6, f.v.begin, 0, 0, 0);
    func_004A5400();
    f.s35D4 = f.owner;
    f.s35C4 = f.owner->fA8;
    func_005FC0A8(f.o35B0, f.obj, &f.s35C0, &f.s35D0);
    func_005FC150(f.obj, f.owner);
}
