/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Header { int frames; unsigned size; };
struct Obj { char pad[0x48]; Header *h; };
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" void *func_00346528(Obj *o, Header *src) {
    Header *h = o->h;
    if (h) {
        func_005A4724(h, src, src->size);
        return (char *)src + ((src->size + 3) & ~3u);
    }
    return src;
}
