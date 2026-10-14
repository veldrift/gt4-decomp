typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef signed char s8;
struct Msg { s32 unk0; s32 unk4; s8 unk8; s8 unk9; char padA[6]; u32 unk10; s16 unk14; char data[1]; };
extern char D_0064A280[];
extern char D_0064A200[];
extern s32 D_0064A1F4;
extern void (*D_0064A2C8)(s32, u32 *, s32);
extern "C" void func_0057DA20(void *, const char *, ...);
extern "C" void *func_005A6AB0(void *, void *, s32) throw();
extern "C" void func_00506FB8(s32 a0, s32 a1, s32 a2, Msg *m) {
    u32 sp0;
    s32 s0 = m->unk0;
    func_0057DA20(D_0064A280, "Medius Billing Service Version %d.%d", m->unk8, m->unk9);
    func_005A6AB0(D_0064A200, m->data, m->unk14);
    s32 t = m->unk4;
    if (t == 0) {
        u32 v = m->unk10;
        sp0 = v;
        if (v < 4) {
            if (v >= 2) D_0064A1F4 = 2;
        }
    } else {
        sp0 = 0;
    }
    if (D_0064A2C8 != 0) D_0064A2C8(t, &sp0, s0);
}
