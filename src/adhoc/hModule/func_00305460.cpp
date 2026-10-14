/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_00328660(void *);
extern "C" void func_003286B8(void *);
extern "C" void func_005EECB8(void *, const void *);
struct Object { char pad[0x10]; int word; void *handle; char string[0x10]; int field28; };
static inline void assignWord(int *dst, const int *src) {
    if (dst != src) *dst = *src;
}
static inline void assignHandle(void **dst, void *const *src) {
    if (dst != src) {
        if (*src) func_00328660(*src);
        if (*dst) func_003286B8(*dst);
        *dst = *src;
    }
}
static inline void assignString(void *dst, const void *src) {
    if (dst != src) func_005EECB8(dst, src);
}
extern "C" Object *func_00305460(Object *dst, const Object *src) {
    if (dst != src) {
        assignWord(&dst->word, &src->word);
        assignHandle(&dst->handle, &src->handle);
        assignString(dst->string, src->string);
        dst->field28 = 0;
    }
    return dst;
}
