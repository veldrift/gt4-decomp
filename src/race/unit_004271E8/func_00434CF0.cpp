typedef short s16;
typedef int s32;

struct VEntry { s16 delta; s16 index; s32 (*fn)(void *, s32); };
struct Elem { struct VEntry *vtbl; char data[0x4BC]; };
struct Obj { struct VEntry *vtbl; char pad[4]; struct Elem elems[1000]; };

extern "C" void func_00434CF0(struct Obj *o, s32 arg1)
{
    s32 v = arg1;
    int i;
    struct Elem *p = &o->elems[0];
    for (i = 0; i < 1000; i++) {
        struct VEntry *e = p->vtbl + 6;
        v = e->fn((char *)p + e->delta, v);
        p++;
    }
    struct VEntry *f = o->vtbl + 4;
    f->fn((char *)o + f->delta, arg1);
}
