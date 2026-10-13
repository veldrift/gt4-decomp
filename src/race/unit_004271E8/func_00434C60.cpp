typedef short s16;
typedef int s32;

struct VEntry { s16 delta; s16 index; s32 (*fn)(void *, s32); };
struct Elem { struct VEntry *vtbl; char data[0x4BC]; };
struct Obj { struct VEntry *vtbl; char pad[4]; struct Elem elems[1000]; };

extern "C" void func_00434C60(struct Obj *o, s32 arg1)
{
    s32 v = arg1;
    int n = 0x3E7;
    struct Elem *p = (struct Elem *)((char *)o + 8);
    do {
        n--;
        struct VEntry *ve = p->vtbl + 5;
        v = ve->fn((char *)p + ve->delta, v);
        p++;
    } while (n >= 0);
    struct VEntry *e = o->vtbl + 4;
    e->fn((char *)o + e->delta, arg1);
}
