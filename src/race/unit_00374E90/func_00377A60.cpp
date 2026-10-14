/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Tgt { char *vtbl; char pad[0x234 - 4]; float f234; };
struct Entry { short delta, index; Tgt *(*fn)(void *, int); };
struct Entry3 { short delta, index; void (*fn)(void *, int, int); };
struct Entry1 { short delta, index; void (*fn)(void *); };
struct Entry2 { short delta, index; void *(*fn)(void *); };
struct Obj { char *vtbl; };
extern "C" int func_00377A28(float) throw();
extern "C" void func_0037BC20(void *, int);
extern "C" void func_0037BC48(void *, int, int);
extern "C" float func_00578598(void *);
extern "C" int func_00377A60(Obj *self, int a1, int a2, int idx, unsigned flags, float *out) {
    char *s3 = (char *)self + idx * 0x19C + 0x10;
    Tgt *s2 = *(Tgt **)(s3 + 0x148);
    Entry *e = (Entry *)(self->vtbl + 0xD8);
    int hit = 0;
    Tgt *r = e->fn((char *)self + e->delta, idx);
    if (r != s2) hit = 1;
    if (flags & 2) hit = 1;
    if (flags & 4) hit = 1;
    if (!hit) return 0;
    {
        int s0 = func_00377A28(func_00578598((char *)self + 4));
        Entry3 *e1 = (Entry3 *)(s2->vtbl + 0x140);
        e1->fn((char *)s2 + e1->delta, (int)s3, 0);
        Entry1 *e2 = (Entry1 *)(s2->vtbl + 0x168);
        e2->fn((char *)s2 + e2->delta);
        s2->f234 = 0.5f;
        Entry1 *e3 = (Entry1 *)(s2->vtbl + 0x170);
        e3->fn((char *)s2 + e3->delta);
        func_0037BC48(s2, s0, 1);
        Entry2 *e4 = (Entry2 *)(s2->vtbl + 0xB8);
        void *q = e4->fn((char *)s2 + e4->delta);
        if ((int)q != s0) func_0037BC20(s2, 0);
        *(Tgt **)(s3 + 0x12C) = s2;
        *(int *)out = 1;
        out[2] = 0.5f;
    }
    return 0;
}
