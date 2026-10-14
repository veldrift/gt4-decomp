/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x60]; char *data; };
extern "C" char *func_00346528(void *, char *) throw();
extern "C" char *func_00346CA0(Obj *self, char *src) {
    __builtin_memcpy(self->data, src, 0x14F4);
    return func_00346528((char *)self + 8, src + 0x14F4);
}
