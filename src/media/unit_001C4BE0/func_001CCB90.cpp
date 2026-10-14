/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta, index; void *fn; };
struct Obj { char pad[0x4C]; VEntry *vt; };
struct Target { VEntry *vt; };
struct Data { int words[5]; };
extern "C" void func_004AF6B8(Data *);
extern "C" int func_004AE230(Data *, int, int);
extern "C" void free(int) throw();
extern "C" int func_001CCB90(Obj *self, Target *dest, int key, int idx) {
    VEntry *e = self->vt + 17;
    int *base = ((int *(*)(void *))e->fn)((char *)self + e->delta);
    Data data;
    func_004AF6B8(&data);
    Data tmp;
    Data *p = &tmp;
    func_004AE230(p, base[idx], 1);
    data = *p;
    VEntry *f = dest->vt + 16;
    int ok = ((int (*)(void *, int, int, int))f->fn)((char *)dest + f->delta, key, data.words[4], data.words[2]) == 0;
    free(data.words[4]);
    return ok;
}
