/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *, s32, f32);
};
struct VEntry0 {
    short delta;
    short index;
    void (*fn)(void *);
};
struct Other {
    char pad0[4];
    char *vtbl;
};
struct Self {
    char pad0[4];
    char *vtbl;
    char pad8[0xC];
    void *wid;
    Other *obj;
    s32 flag;
    f32 t;
    f32 x;
    f32 y;
    f32 w;
    f32 h;
    char pad34[4];
    s32 loop;
    s32 dir;
    f32 speed;
};

extern "C" void mWidget__setWindowX(void *w, f32 v);
extern "C" void mWidget__setWindowY(void *w, f32 v);
extern "C" void mWidget__setWindowW(void *w, f32 v);
extern "C" void mWidget__setWindowH(void *w, f32 v);
extern "C" s32 func_00265FE0(void *w);

extern "C" void mButtonActor__update(Self *a) {
    if (func_00265FE0(a->wid) != 0) {
        f32 v, s, nw, nh;
        a->t = a->t + a->speed;
        if (a->t > 1.0f) {
            if (a->loop != 0) {
                a->t = 0.0f;
            } else {
                a->t = 1.0f;
            }
        }
        v = a->t;
        if (a->dir == 0) {
            v = 1.0f - v;
        }
        s = v * 0x1.333332p-3f + 1.0f;
        nw = a->w * s;
        nh = a->h * s;
        mWidget__setWindowX(a->wid, a->x + (a->w - nw) * 0.5f);
        mWidget__setWindowY(a->wid, a->y + (a->h - nh) * 0.5f);
        mWidget__setWindowW(a->wid, nw);
        mWidget__setWindowH(a->wid, nh);
        {
            Other *o = a->obj;
            VEntry *e = (VEntry *)(o->vtbl + 0x1D8);
            e->fn((char *)o + e->delta, -1, v);
        }
        a->flag = 1;
    } else if (a->flag != 0) {
        a->flag = 0;
        {
            VEntry0 *e = (VEntry0 *)(a->vtbl + 0x190);
            e->fn((char *)a + e->delta);
        }
        {
            VEntry0 *e = (VEntry0 *)(a->vtbl + 0x198);
            e->fn((char *)a + e->delta);
        }
    }
}
