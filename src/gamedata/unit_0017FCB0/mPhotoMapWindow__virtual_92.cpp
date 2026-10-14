/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V { short d, i; void (*fn)(void *, void *); };
struct V2 { short d, i; char *(*fn)(void *); };
struct Node { char pad[4]; char *vtbl; };
struct Rec { int flags; unsigned short idx; char pad[0x3A]; };
struct Ent { int a; int **b; int c, d; };
struct Tbl { char pad[0x18]; int count; Rec *recs; char pad2[4]; Ent *ents; };
struct Mid { char pad[0x80]; };
struct Win {
    char pad0[0xC0];
    Node *w_c0;
    char pad1[8];
    Node *w_cc;
    char pad2[8];
    Node *w_d8;
    Node *w_dc;
    Node *w_e0;
    char pad3[8];
    int w_ec;
};
struct M4 { char pad[0xCC]; Tbl *t; };
struct M80 { char pad[4]; M4 *m4; };
struct M6C { char pad[0x80]; M80 *m80; };
struct Ctx { char pad[0x64]; char *vtbl; char pad2[4]; M6C *m6c; };

extern "C" void *func_00192E20(void *);
extern "C" void func_00231508(void *, void *);
extern "C" void func_00231798(void *, void *);
extern "C" void func_00231C10(void *);
extern "C" void func_00231C48(void *);
extern "C" void mWidget__setWindowPosition(void *, float, float);
extern "C" void mWidget__getWindowSize(void *, float *, float *);
extern "C" void mSceneViewFace__virtual_92(void *, void *);
extern "C" int func_00265DC8(void *);
extern "C" void mWidget__setRotate(void *, float);
extern "C" float func_0036FFC0(void *, float);
extern "C" float func_00370010(void *, float);
extern "C" float func_003705A0(void *, int);
extern "C" void func_003C6B90(void *, float *);

#define DRAW(fld) do { \
    func_00231508(a1, self->fld); \
    V *v = (V *)(self->fld->vtbl + 0x2E8); \
    v->fn((char *)self->fld + v->d, a1); \
    func_00231798(a1, self->fld); } while (0)

extern "C" void mPhotoMapWindow__virtual_92(Win *self, void *a1)
{
    float sz[2];
    float p[2];
    int i;
    mSceneViewFace__virtual_92(self, a1);
    if (func_00265DC8(self) != 0) {
        func_00231C10(a1);
        if (self->w_e0 != 0) {
            i = 0;
            char *o = (char *)func_00192E20(a1);
            Tbl *s3 = ((Ctx *)o)->m6c->m80->m4->t;
            V2 *v = (V2 *)(((Ctx *)o)->vtbl + 0x4B0);
            char *s4 = v->fn(o + v->d) + 0xE28;
            mWidget__getWindowSize(self->w_e0, &sz[0], &sz[1]);
            sz[0] *= 0.5f;
            sz[1] *= 0.5f;
            if (s3->count > 0) {
                do {
                    Rec *r = s3->recs + i;
                    if (r->flags & 1) {
                        Ent *e = s3->ents + r->idx;
                        void *s0 = *e->b;
                        float f21 = func_003705A0(s4, i);
                        func_003C6B90(s0, p);
                        float f20 = func_0036FFC0(s4, p[0]);
                        float y = func_00370010(s4, p[1]);
                        float xx = f20 - sz[0];
                        float yy = y - sz[1];
                        mWidget__setWindowPosition(self->w_e0, xx, yy);
                        mWidget__setRotate(self->w_e0, f21);
                        DRAW(w_e0);
                    }
                    i++;
                } while (i < s3->count);
            }
        }
        if (self->w_cc != 0) DRAW(w_cc);
        if (self->w_c0 != 0) DRAW(w_c0);
        if (self->w_d8 != 0) DRAW(w_d8);
        if (self->w_dc != 0 && (unsigned)(self->w_ec - 1) < 2) DRAW(w_dc);
        func_00231C48(a1);
    }
}
