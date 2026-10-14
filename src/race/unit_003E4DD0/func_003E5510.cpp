/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj {
    char *items;
    int count;
};
extern "C" void func_0045B620(void *, void *);
extern "C" void GT4Model__BinStreamReader__read8u(void *);
extern "C" int func_0045B140(void *);
extern "C" int func_0045B1E0(void *);
extern "C" void func_0045B740(void *, void *);
extern "C" void func_003E4F60(Obj *, void *) throw();
extern "C" void func_003E4FC0(void *, void *) throw();
extern "C" void func_003E56E8(void *, void *);

extern "C" void func_003E5510(Obj *self, void *stream) {
    int buf[4];
    int i = 0;
    func_0045B620(buf, stream);
    GT4Model__BinStreamReader__read8u(stream);
    func_0045B140(stream);
    if (self->count > 0) {
        int off = 0;
        do {
            char *it = self->items + off;
            off += 0x60;
            func_003E4F60(self, it);
            if (func_0045B1E0(stream)) {
                if (func_0045B1E0(stream)) func_003E56E8(it, stream);
            } else {
                func_003E4FC0(self, it);
            }
            i++;
        } while (i < self->count);
    }
    func_0045B740(buf, stream);
}
