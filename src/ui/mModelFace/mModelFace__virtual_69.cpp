typedef int s32;
typedef short s16;
typedef float f32;

struct Wid { char pad0[4]; char *vtbl; };
struct VE { s16 delta; s16 index; s32 (*fn)(void *); };
struct Vec { f32 v[3]; f32 &operator[](int i) { return v[i]; } };
struct Obj {
    char pad0[0x2BC];
    Wid *w;
    char pad2C0[0x2F0 - 0x2C0];
    Vec cur;
    Vec tgt;
    s32 flags;
};
extern "C" void mColorChipFace__virtual_69(Obj *, void *, int);
extern "C" void func_002BD068(Obj *, Vec *) throw();
extern "C" void func_002BD258(Obj *, Vec *) throw();
extern "C" Vec *func_0021A850(void *);

extern "C" void mModelFace__virtual_69(Obj *self, void *p1, int flag) {
    mColorChipFace__virtual_69(self, p1, 0);
    if (flag != 0) {
        Wid *w = self->w;
        if (w != 0) {
            VE *e = (VE *)(w->vtbl + 0x48);
            if (e->fn((char *)w + e->delta) != 0) {
                if (((self->flags >> 1) & 1) == 0) {
                    Vec *t = &self->tgt;
                    func_002BD068(self, t);
                    if (self->flags & 1) {
                        Vec *m = func_0021A850((char *)self + 0xA0);
                        bool ok = true;
                        for (int i=0; i<3; ++i) {
                            Vec *target = &self->tgt;
                            if ((*target)[i] != 0.0f) {
                                float d = self->cur[i] - (*m)[i];
                                if (d >= 0.0f) { if (!(d > 1.0f)) continue; }
                                else { if (!(d < -1.0f)) continue; }
                                ok = false;
                            }
                        }
                        if (ok) {
                            for (int i=0; i<3; ++i) {
                                Vec *target = &self->tgt;
                            if ((*target)[i] != 0.0f) {
                                    (*m)[i] = self->cur[i];
                                    (*target)[i] = 0.0f;
                                }
                            }
                            self->flags = self->flags & ~1;
                        }
                    }
                } else {
                    func_002BD258(self, &self->tgt);
                }
            }
        }
    }
}
