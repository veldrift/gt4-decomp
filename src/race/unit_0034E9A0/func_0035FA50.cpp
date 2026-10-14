/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta,index; int (*fn)(void *); };
struct Owner { char pad[0x10140]; VEntry *vtbl; };
struct Obj { int word; Owner *owner; char pad[0x56a-8]; signed char busy; };
extern "C" int func_0035FA50(Obj *self) {
    if (self->busy != 0) return 0;
    Owner *o = self->owner;
    VEntry *e = o->vtbl + 44;
    return e->fn((char *)o + e->delta);
}
