typedef int s32;
struct VEntry { short delta; short index; s32 (*fn)(void *); };
struct Obj { char pad[0x64]; VEntry *vtbl; };
extern "C" void func_00116268(void *a, Obj *o);
extern "C" void func_00116440(void *a, Obj *o);
extern "C" void func_001165B8(void *a, Obj *o);
extern "C" void func_001161A0(void *a, Obj *o)
{
    VEntry *e = o->vtbl + 0x5F;
    s32 r = e->fn((char *)o + e->delta);
    switch (r) {
    case 16:
        func_00116268(a, o);
        break;
    case 17:
        func_00116440(a, o);
        break;
    case 18:
        func_001165B8(a, o);
        break;
    }
}
