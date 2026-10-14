/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { int off; char name[28]; };
struct Obj { char *base; int count; Entry *entries; };
extern "C" void func_00277130(void *, void *) throw();
extern "C" int func_0057F238(const char *, const char *) throw();
extern "C" int func_00277228(Obj *o, void *out, const char *name) {
    for (int i = 0; i < o->count; i++) {
        if (func_0057F238(o->entries[i].name, name) == 0) {
            func_00277130(out, o->base + o->entries[i].off);
            return 1;
        }
    }
    return 0;
}
