/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned long u64;
struct Tgt;
struct Entry2 { short delta, index; Tgt *(*fn)(void *, int); };
struct EntryB { short delta, index; int (*fn)(void *); };
struct EntryC { short delta, index; void (*fn)(void *, void *, int); };
struct EntryD { short delta, index; void (*fn)(void *, int, float, float, float); };
struct EntryE { short delta, index; void (*fn)(void *); };
struct Cont { char *vtbl; };
struct Tgt { char *vtbl; char pad0[0xE4]; int mE8; char pad1[0x188 - 0xEC]; float f188; int m18C; char pad2[0x260 - 0x190]; u64 u260; };
struct P14 { char pad[0x10]; int m10; };
struct P0 { char pad[0x80]; void *m80; };
struct Self { P0 *p0; Cont *cont; int m8; Tgt *tgt; int idx; P14 *p14; int *out; };
struct W { int v; };
struct Arg1 { int m0; float f4, f8; };
extern "C" float RaceCourse__getCourseLength(void *);
extern "C" void func_00376F20(Self *self, Arg1 *arg1, int sp0) {
    int *pp = &sp0;
    int ok = 0;
    Cont *cont = self->cont;
    Entry2 *e0 = (Entry2 *)(cont->vtbl + 0xD8);
    Tgt *r0 = e0->fn((char *)cont + e0->delta, self->idx);
    Tgt *s1 = self->tgt;
    void *s3 = self->p0->m80;
    if (r0 == s1) {
        EntryB *e = (EntryB *)(s1->vtbl + 0xB8);
        int a1 = s1->m18C;
        int a2 = self->p14->m10;
        int x = a1 ^ a2;
        ok = x == 0;
        if (e->fn((char *)s1 + e->delta) != *pp) ok = 0;
    }
    if (!ok) {
        EntryC *e = (EntryC *)(s1->vtbl + 0x140);
        e->fn((char *)s1 + e->delta, self->p14, *pp);
    }
    float f = RaceCourse__getCourseLength(s3);
    EntryD *ed = (EntryD *)(s1->vtbl + 0x148);
    ed->fn((char *)s1 + ed->delta, 3, arg1->f4, arg1->f8, f);
    s1->mE8 = 1;
    EntryE *ee = (EntryE *)(s1->vtbl + 0x170);
    ee->fn((char *)s1 + ee->delta);
    s1->f188 = 100.0f;
    s1->u260 = (s1->u260 & (~0ul >> 8)) | ((u64)0x8000 << 41);
    char *slot = (char *)self->cont;
    slot += self->idx * 0x19C;
    *(Tgt **)(slot + 0x13C) = s1;
    *self->out = 1;
}
