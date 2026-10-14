/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Ent { s32 id; s32 pad4; f32 f8; f32 fC; };
struct Inner { char pad0[0x24]; f32 f24; };
struct Rect { char pad[12]; s32 w,h; };
struct Obj {
    Inner *p0;
    s32 id;
    char pad8[4];
    s32 fC;
    s32 f10;
    f32 f14;
    char pad18[8];
    Rect rect;
    s32 f34;
    s32 f38;
    char pad3C[0x20];
    char *f5C;
};

extern "C" Ent *func_001C93B0(s32 id) throw();
extern "C" f32 func_001CAB50(void *);
extern "C" char *func_001C9C68(void *, char *, s32, s32, s32, s32) throw();
extern "C" s32 func_005C1D00(char *);
extern char D_00693F50[];

extern "C" char *func_001CA070(Obj *o) {
    Ent *e = func_001C93B0(o->id);
    s32 s4 = (s32)(((e->f8 + 4.94f) * 360.0f) / 25.4f);
    s32 s3 = (s32)(((e->fC + 4.94f) * 360.0f) / 25.4f);
    s32 s1 = (s32)(((e->f8 - 2.0f * o->f14) * 360.0f) / 25.4f);
    s32 s2 = (s32)(((e->fC - 2.0f * o->f14) * 360.0f) / 25.4f);
    f32 ar = func_001CAB50(o);
    s32 t0, t1;
    if (o->fC != 0) {
        t0 = s1;
        t1 = s2;
        if (o->f10 == 0) {
            s32 extra=(s32)(4.0f*360.0f/25.4f);
            t0 += extra;
            t1 += extra;
        }
    } else {
        t0 = s4;
        t1 = s3;
    }
    if (o->f10 != 0) {
        f32 w = (f32)t0;
        f32 h = (f32)t1;
        if (w / h < ar) t1 = (s32)(w / ar);
        else t0 = (s32)(ar * h);
        s32 flag = 1;
        if (!(o->p0->f24 < 1.0f)) flag = 0;
        if (flag) {
            Rect *r=&o->rect;
            o->f34 = t0 - r->w;
            o->f38 = t1 - r->h;
        } else {
            o->f38 = 0;
            o->f34 = t0 - o->rect.h;
        }
    } else {
        f32 w = (f32)t0;
        f32 h = (f32)t1;
        if (w / h < ar) t0 = (s32)(ar * h);
        else t1 = (s32)(w / ar);
        s32 x = (t0 + s1) / 2;
        s32 y = (t1 + s2) / 2;
        s32 flag = 1;
        if (!(o->p0->f24 < 1.0f)) flag = 0;
        if (flag) {
            Rect *r=&o->rect;
            o->f34 = x - r->w;
            o->f38 = y - r->h;
        } else {
            o->f38 = t1 - y;
            o->f34 = x - o->rect.h;
        }
    }
    char *r = func_001C9C68(o, o->f5C, s4, s3, t0, t1);
    if (func_005C1D00(o->f5C) != 0) r = D_00693F50;
    return r;
}
