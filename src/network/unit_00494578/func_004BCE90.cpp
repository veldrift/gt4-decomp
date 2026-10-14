/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

struct Ent {
    u16 h0;
    char pad2[6];
    u8 b08;
    char pad09;
    u16 h0A;
    union {
        u32 w0C;
        struct {
            u16 h0C;
            u8 b0E;
            u8 b0F;
        };
    };
    char pad10[8];
    s32 w18;
    s32 w1C;
};
struct Obj {
    char pad0[0x24];
    void *unk24;
};

extern "C" {
s32 func_004BC978(void *, s32, Ent *, s32) throw();
s32 func_004BD8F0(s32, s32, s32, s32);
s32 func_004BDD68(Obj *, s32, s32, s32, s32, u16 *, s32 *);
s32 func_004C07F8(void *, s32, u32, s32);
s32 func_004C92D8(const u8 *, const u8 *, u32);
}

extern "C" s32 func_004BCE90(Obj *obj, Ent *q, u16 key, u16 *out)
{
    Ent e;
    Ent *ep = &e;
    u16 v;
    s32 cnt;
    s32 r;
    s32 i;
    s32 a2;
    s32 a3;

    v = 0;
    cnt = 0;
    *out = 0;
    if ((key & 0xFF00) == 0x200) {
        a3 = q->b0E;
        a2 = q->w18;
    } else {
        a3 = q->b08;
        a2 = q->w18 + q->b0E - a3;
    }
    r = func_004BDD68(obj, key, a2, a3, 4, &v, &cnt);
    if (r <= 0) {
        return 0;
    }
    for (i = 0; i < cnt; i++) {
        ep->h0 = func_004C07F8(obj->unk24, key, v, 4);
        r = func_004BC978(obj->unk24, key, ep, 0);
        if (r > 0 && (q->w0C & 0xFFFF0000) == (ep->w0C & 0xFFFF0000) &&
            func_004BD8F0(q->w18, ep->w18, q->b0E, ep->b0E) == 0 && q->h0A == ep->h0A && q->h0C == ep->h0C) {
            r = func_004C92D8((const u8 *)q->w1C, (const u8 *)ep->w1C, ep->b0F);
            if (r == 0) {
                *out = ep->h0;
                return r;
            }
        }
        v = v + 1;
    }
    return 0;
}
