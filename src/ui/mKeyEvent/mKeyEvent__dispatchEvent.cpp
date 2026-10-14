/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct VObj;
struct VEntryN { s16 delta; s16 index; const char *(*fn)(void *); };
struct VEntryD { s16 delta; s16 index; s32 (*fn)(void *, s32, void *, s32); };
struct VObj { char pad0[4]; char *vtbl; char pad8[8]; s32 f10; s32 f14; };

extern "C" void func_00231940(s32, s32);
extern "C" s32 func_0027F2B8(void) ;
extern "C" s32 func_0028EA08(void *);
extern "C" VObj *func_0028EA18(void *);
extern "C" s32 func_002A95A8(void) throw();
extern "C" const char *hModule__getName(const char *);
extern "C" void func_005D4AD8(const char *, ...);

extern "C" s32 mKeyEvent__dispatchEvent(VObj *self) {
    s32 result = 1;
    func_005D4AD8("{\n");
    VEntryN *n = (VEntryN *)(self->vtbl + 0x50);
    func_005D4AD8("[%s {%d} %010d] ", hModule__getName(n->fn((char *)self + n->delta)), self->f14, self->f10);
    if (func_0028EA18(self) != 0) {
        VObj *o = func_0028EA18(self);
        VEntryD *e = (VEntryD *)(o->vtbl + 0x2A8);
        void *adj = (char *)o + e->delta;
        result = e->fn(adj, func_0028EA08(self), self, 0);
        if (result == 2) {
            s32 a = func_0028EA08(self);
            func_00231940(a, func_002A95A8());
            s32 b = func_0028EA08(self);
            func_00231940(b, func_0027F2B8());
        }
    }
    func_005D4AD8("}\n");
    return result;
}
