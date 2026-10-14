/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x98]; int flags[1]; };
extern "C" int func_00251860(void *, int) throw();
extern "C" bool func_002518B8(Obj *self, int index, int mask) {
    int inverse = ~mask;
    int flags = self->flags[index];
    int other = flags & inverse;
    flags &= mask;
    bool result = false;
    if (flags) {
        if (!other) {
            result = func_00251860(self, index) == 0;
        }
    }
    return result;
}
