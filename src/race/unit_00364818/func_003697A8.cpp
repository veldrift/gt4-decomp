/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Info {unsigned char tag, count;};
struct Dst {float x, y, z; char pad[0x34-12];};
struct Obj {char pad0[0x10]; void *o10; char pad1[0x7B8-0x14]; Dst dst[1];};
extern "C" Info *func_00359510(void *);
extern "C" float func_003696C8(Obj *, int) throw();
extern "C" float func_00369760(Obj *, int, int, float) throw();
extern "C" void func_003697A8(Obj *self){
    float v[3];
    int i = 0;
    Info *info = func_00359510(self->o10);
    if (__builtin_expect(info->count, 0) == 0) return;
    Dst *d = self->dst;
    do {
        float t = func_003696C8(self, i);
        for (int j = 0; j < 3; j++)
            v[j] = func_00369760(self, i, j, t);
        i++;
        d->x = v[0];
        d->y = v[2];
        d->z = -v[1];
        d++;
    } while (i < info->count);
}
