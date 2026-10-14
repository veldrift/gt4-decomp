struct Face;
struct VEntry { short delta; short index; void (*fn)(void *, int, Face *); };
struct VEntry2 { short delta; short index; int (*fn)(void *, int *); };
struct Obj { void *f0; char *vtbl; };
struct Face { char pad[0xA0]; Obj *fA0; Obj *fA4; };
extern "C" void mColorChipFace__virtual_69(Face *, int, int);
extern "C" void func_001C5938(void);
extern "C" void func_001BF5C0(Obj *, int);

extern "C" void mEyetoyFacePS2__virtual_69(Face *a, int b) {
    Obj **p = &a->fA0;
    mColorChipFace__virtual_69(a, b, 0);
    func_001C5938();
    Obj *o = *p;
    if (o) {
        VEntry *e = (VEntry *)(o->vtbl + 0x1A0);
        e->fn((char *)o + e->delta, b, a);
        int v = 0;
        Obj *o2 = *p;
        VEntry2 *e2 = (VEntry2 *)(o2->vtbl + 0x1B8);
        if (e2->fn((char *)o2 + e2->delta, &v))
            func_001BF5C0(a->fA4, v);
    }
}
