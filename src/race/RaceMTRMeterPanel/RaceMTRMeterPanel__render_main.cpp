/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Entry { short delta, index; void (*fn)(void *, void *); };
struct Sub { char pad[0x14]; Entry *vt; char rest[0x58]; };
struct Panel {
    char pad0[0xC];
    f32 fC;
    char pad10[8];
    s32 i18;
    void *p1C;
    Sub subs[4];
};
struct Pos { f32 x, y; };
extern f32 D_006A1780[];

extern "C" int func_00105250(char *);
extern "C" void func_00105280(void *, int);
extern "C" void func_001056A0(void *);
extern "C" void func_00105728(s32 *);
extern "C" void RaceMTRMeterPanel__init_texset(Panel *) throw();
extern "C" void func_003AF108(void *, s32, s32, f32, f32, f32, f32);
extern "C" void func_003AF6E0(f32, f32, f32, f32, f32, f32, f32, f32);
extern "C" void func_004A1638(s32);
extern "C" void func_004A2808(s32, f32);
extern "C" void func_004A29A8(s32);
extern "C" void func_004A4550(s32, s32);
extern "C" void func_004AA1D8(f32, f32, f32, f32);
extern "C" void func_004AB040(s32);

extern "C" void RaceMTRMeterPanel__render_main(Panel *self, void *arg) {
    char buf[0x40];
    if (self->i18 != 0) {
        Sub *s = self->subs;
        RaceMTRMeterPanel__init_texset(self);
        func_004AB040(5);
        func_004A29A8(0);
        func_004A1638(6);
        func_004A2808(0x44, 0.0f);
        func_004AA1D8(1.0f, 1.0f, 1.0f, self->fC);
        func_003AF108(self->p1C, 2, 1, 320.0f, 448.0f, 640.0f, 156.0f);
        s32 n = 3;
        func_00105250(buf);
        const f32 *pos = D_006A1780;
        do {
            Entry *e = s->vt + 6;
            e->fn((char *)s + e->delta, buf);
            s++;
            func_001056A0(arg);
            func_00105728((s32 *)buf);
            func_004AA1D8(1.0f, 1.0f, 1.0f, self->fC);
            func_004A1638(6);
            func_004A2808(0x44, 0.0f);
            func_004A4550(2, 1);
            func_004A4550(3, 1);
            f32 x = pos[0];
            f32 y = pos[1];
            pos += 2;
            func_003AF6E0(x, y, x + 128.0f, y + 128.0f, 0.0f, 0.0f, 1.0f, 1.0f);
        } while (--n >= 0);
        func_004A4550(2, 1);
        func_004A4550(3, 1);
        func_00105280(buf, 2);
    }
}
