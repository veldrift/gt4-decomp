/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0xf4]; const signed char **names; };
extern "C" int func_004AE9E8(const signed char *, const signed char *);
extern "C" int func_004B0A38(Obj *);
extern "C" int func_004ACBA0(Obj *self, const signed char *name) {
    if (self->names) {
        const signed char **p = self->names;
        while (*p) {
            if (func_004AE9E8(*p, name)) return 1;
            p++;
        }
        return 0;
    }
    return func_004B0A38(self);
}
