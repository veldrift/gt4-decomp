typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

struct B8 {
    char d[8];
};
struct Entry {
    B8 b0;
    s32 f8;
    s32 fC;
    void (*fn)(s32, void *, s32, ...);
    s32 t14;
    s32 f18;
    s32 f1C;
};
struct Pkt {
    s32 unk0;
    u8 unk4;
    signed char unk5;
};
struct Slot {
    char pad0[0x20];
    s32 unk20;
};
struct Msg {
    s32 v;
    u8 b4;
    u8 b5;
};
struct Sys {
    char pad0[0x60];
    B8 b60;
    s32 f68;
};

extern Entry D_008A05B0[];
extern Sys *D_0064B47C;

extern "C" {
s32 func_00531878(void *, Entry *) throw();
s32 func_00531CA8() throw();
s32 func_00531CC8() throw();
s32 func_00532310(s32, s32, s32, s32, s32, s32, Msg *) throw();
Slot *func_00535C88(s32 *, u32) throw();
}

extern "C" s32 func_00537458(s32 *arg0, s32 arg1, s32 arg2, Pkt *p)
{
    if (p->unk5 != 0) {
        if (arg0 != 0) {
            if (arg2 != 0x100) {
                Slot *sl = func_00535C88(arg0, arg2);
                if (sl == 0) return 8;
                {
                    if (sl->unk20 != 0) {
                        Msg m;
                        m.v = func_00531CC8();
                        m.b4 = p->unk4;
                        m.b5 = 0;
                        func_00532310(-0x80, (s32)arg0, arg2, 0, 1, 8, &m);
                    }
                    return 8;
                }
            }
            return 8;
        }
    } else {
        func_00531CA8();
        void (*fn)(s32, void *, s32, ...) = D_008A05B0[p->unk4].fn;
        if (fn == 0) return 8;
        {
            char sp10[16];
            s32 t;
            t = func_00531CA8() - D_008A05B0[p->unk4].t14;
            func_00531878(sp10, &D_008A05B0[p->unk4]);
            D_0064B47C->b60 = D_008A05B0[p->unk4].b0;
            D_0064B47C->f68 = D_008A05B0[p->unk4].f8;
            if (D_008A05B0[p->unk4].fC == 1) {
                fn(0, sp10, t, p->unk0, D_008A05B0[p->unk4].f18, D_008A05B0[p->unk4].f1C);
            } else {
                fn(0, sp10, t);
            }
            D_008A05B0[p->unk4].fn = 0;
        }
    }
    return 8;
}
