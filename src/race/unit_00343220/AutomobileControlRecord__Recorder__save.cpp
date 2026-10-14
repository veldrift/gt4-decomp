/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Header { int frames; unsigned size; };
struct Obj { char pad[0x48]; Header *h; };
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" void AutomobileControlRecord__Recorder__save(Obj *o, int *out) {
    if (o) {
        Header *h = o->h;
        if (h) {
            func_005A4724((char *)out + *out, h, h->size);
            unsigned size = h->size;
            *out = *out + ((size + 3) & ~3u);
        }
    }
}
