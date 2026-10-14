/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct VEntry { short delta; short index; s32 (*fn)(void *); };
struct B { void *p; };
struct A { char pad[0x7c]; B *b; };
struct Data { char pad[0x18]; A *a; s32 pad2; s32 x; s32 y; };
struct Obj { char pad[8]; VEntry *vtbl; char pad2[8]; Data *data; };
extern "C" s32 func_003EDAD8(void);
extern "C" Data *func_00575E60(s32, s32);
extern "C" void func_004AE268(void *, s32, Data *, s32, s32);
extern "C" void func_004583D0(void *);
extern "C" void func_00454698(void *, B *, s32, s32);
extern "C" void func_00458290(s32, s32, s32);
extern "C" void func_00453480(void *, s32);
extern "C" void RaceCarModel__virtual_14(Obj *o, s32 arg) {
    s32 buf[8];
    s32 flags = func_003EDAD8();
    Data *data = o->data;
    if (!data) {
        data = func_00575E60(0x40, 0xb4000);
        o->data = data;
        flags = 0xb4000;
    }
    func_004AE268(buf, arg, data, flags, 1);
    func_004583D0(o->data);
    B *b = o->data->a->b;
    func_00454698(b->p, b, 0, 0);
    Data *d = o->data;
    s32 y = d->y;
    s32 x = d->x;
    if (y && x) {
        VEntry *e = (VEntry *)((char *)o->vtbl + 0x38);
        func_00458290(y, x, e->fn((char *)o + e->delta));
    }
    func_00453480((char *)o + 0x18, x);
}
