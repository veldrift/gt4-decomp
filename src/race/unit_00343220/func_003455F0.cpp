/* compiler: ee-gcc2.96-no-strict-aliasing */
struct State { char pad[0x440]; unsigned char index; char gap[0x568-0x441]; float x; int a; float y; char gap2[0x5fc-0x574]; int z1,z2; };
struct Entry { float f[12]; };
struct Data { char pad[0xcab8]; Entry entries[1]; };
struct Obj { int a; Data *data; };
extern "C" void func_003455F0(Obj *self) {
    State *s = (State *)((char *)self + 0x104);
    Data *data = self->data;
    int index = s->index;
    float y = s->y;
    s->z1 = 0;
    s->z2 = 0;
    Entry *e = data->entries + index;
    e->f[0] = y;
    e->f[2] = 0;
    e->f[1] = 0;
    e->f[3] = s->x;
    e->f[4] = 0;
    e->f[5] = 0;
    e->f[6] = 0;
    e->f[7] = 0;
    e->f[8] = 0;
    e->f[9] = 0;
    e->f[10] = 0;
    e->f[11] = 0;
}
