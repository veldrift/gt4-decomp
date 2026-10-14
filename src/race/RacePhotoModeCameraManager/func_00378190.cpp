/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef short s16;
extern "C" void func_004A7454(void);
extern "C" void func_004A7698(void *);
static inline void *get(void *o) {
    char *e = *(char **)o + 0x1F0;
    void *fn = *(void **)(e + 4);
    return ((void *(*)(void *))fn)((char *)o + *(s16 *)e);
}
static inline void call(void *o) {
    char *e = *(char **)o + 0x70;
    void *fn = *(void **)(e + 4);
    ((void (*)(void *))fn)((char *)o + *(s16 *)e);
}
extern "C" void func_00378190(void *self) {
    void *obj = get(self);
    void *dst = (char *)self + 0xA40;
    if (obj == 0) return func_004A7454();
    func_004A7698(dst);
    call(obj);
    func_004A7698((char *)self + 0xA80);
}
