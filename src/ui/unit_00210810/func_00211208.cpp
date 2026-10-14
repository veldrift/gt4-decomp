/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Vec4 { f32 x, y, z, w; };

struct Elem {
    s32 flag;
    f32 f[4];
    Vec4 v[4];
};

struct Obj {
    s32 m0;
    Vec4 v;
    Elem e[4];
};

extern "C" Vec4 *func_002030E8(Vec4 *, Vec4 *);

extern "C" Obj *func_00211208(Obj *self, Obj *src) {
    s32 i;
    func_002030E8(&self->v, &src->v);
    for (i = 0; i < 4; i++) {
        s32 j;
        for (j = 0; j < 4; j++) {
            self->e[i].f[j] = src->e[i].f[j];
        }
        func_002030E8(&self->e[i].v[0], &src->e[i].v[0]);
        func_002030E8(&self->e[i].v[1], &src->e[i].v[1]);
        func_002030E8(&self->e[i].v[2], &src->e[i].v[2]);
        func_002030E8(&self->e[i].v[3], &src->e[i].v[3]);
    }
    return self;
}
