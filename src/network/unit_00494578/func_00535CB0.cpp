extern "C" char *func_005316F8(unsigned) throw();
struct Obj { char *entries[64]; };
extern "C" int func_00535CB0(Obj *obj, unsigned i, char **out) {
    if (!out) return 23;
    *out = 0;
    if (i >= 64) return 23;
    if (!obj) return 10;
    if (!obj->entries[i]) {
        obj->entries[i] = func_005316F8(44);
        if (!obj->entries[i]) return 22;
    }
    *out = obj->entries[i];
    return 0;
}
