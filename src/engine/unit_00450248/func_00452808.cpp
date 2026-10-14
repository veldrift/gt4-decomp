/* compiler: ee-gcc2.96-no-strict-aliasing */
struct G { float a, b, c, d; };
struct Mid { char pad[0x18]; void *f18; };
struct Self {
    Mid *mid;
    char pad[0x94 - 4];
};
struct Item {
    float v[14];
};
struct Obj2 { char pad[0x7C]; void *f7C; };
struct Arg1;

extern G D_008465B0;

extern "C" {
Arg1 *func_00450FE0(Self *) throw();
void func_00454110(float *, int);
void ModelSet2__begin(void *, void *);
void ModelSet2__end(void *);
void ModelSet2___render(void *, int, void *);
void func_004A29A8(int);
void func_004A53F8();
void func_004A5400();
void func_004A60E0(float, float, float, float);
void func_004A6100(float, float, float, float);
void func_004A7890(float, float, float);
void func_004AB040(int);
}

static inline void *getObj(Self *self) {
    Mid *m = self->mid;
    if (!m) return 0;
    return m->f18;
}

extern "C" void func_00452808(int arg0, Obj2 *other) {
    Self *self = (Self *)arg0;
    void *obj = getObj(self);
    void *a = func_00450FE0(self);
    if (obj != 0 && a != 0) {
        ModelSet2__begin(obj, a);
        func_004A6100(D_008465B0.a, D_008465B0.b, D_008465B0.c, 0.0f);
        func_004A60E0(1.0f, 1.0f, 1.0f, D_008465B0.d);
        ModelSet2___render(obj, 1, a);
        ModelSet2__end(obj);
        if (other != 0) {
            a = (char *)self + 0x94;
            void *o2 = other->f7C;
            int i = 0;
            ModelSet2__begin(other, o2);
            func_004A6100(D_008465B0.a, D_008465B0.b, D_008465B0.c, 0.0f);
            func_004A60E0(1.0f, 1.0f, 1.0f, D_008465B0.d);
            func_004A29A8(0);
            func_004AB040(5);
            for (; i < 4; i++) {
                int flip = i & 1;
                func_004A53F8();
                func_00454110(((Item *)a)->v, flip);
                float y = ((Item *)a)->v[8];
                float x = ((Item *)a)->v[6];
                a = (Item *)a + 1;
                if (flip != 0) {
                    x = -x;
                }
                func_004A7890(x, y, y);
                ModelSet2___render(other, 0, o2);
                func_004A5400();
            }
            ModelSet2__end(other);
        }
    }
}
