/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct G {
    char pad[0x50];
    float f50, f54, f58, f5C, f60;
};
extern G D_00843630;
extern "C" float func_00350DA0(void *);
extern "C" int func_00355D48(void *);
extern "C" float func_00356D88(void *, float *);
extern "C" int Automobile__getDrawMode(void *);
extern "C" int func_00368398(void *);
extern "C" float func_00369510(void *, float *);

struct Sub { char pad[0x40]; float f40[1]; char pad2[0x44 - 0x44]; };
struct Z { char pad[0x10D1]; u8 b10D1; };
struct S104 {
    char pad[0x51C - 0x104 + 0x104 - 0x104 + 0x104 - 0x104];
};

extern "C" float func_0034FED0(char *self, float *out) {
    char *s1 = self + 0x104;
    G *g = &D_00843630;
    float var_f0;
    float val;
    if (Automobile__getDrawMode(self) != 3) return 0.0f;
    {
        if (func_00355D48(self) != 0) {
            return func_00356D88(self, out);
        }
        if (func_00368398(*(char **)(self + 0x10) + 0x234) != 0) {
            return func_00369510(self, out);
        }
        char *v = *(char **)(self + 0x10);
        if (*(u8 *)(v + 0x10D1) == 0 || *(u8 *)(s1 + 0x522) == 0) {
            *out = 1.0f;
            return 0.0f;
        } else {
            float a = *(float *)(s1 + 0x51C);
            float temp_f0 = g->f58;
            if (a < 0.0f) a = -a;
            if (temp_f0 < a) a = temp_f0;
            char *w = v + 0x234;
            a = (a * *(float *)(w + *(u8 *)(s1 + 0x520) * 4 + 0x40)) / (temp_f0 * *(float *)(w + 0x44));
            if (a < 0.0f) a = -a;
            float temp_f1 = g->f50;
            a = temp_f1 + ((g->f54 - temp_f1) * a);
            float var_f3 = func_00350DA0(self);
            if (var_f3 < 0.0f) var_f3 = -var_f3;
            *out = g->f60 + (var_f3 * g->f5C);
            return a;
        }
    }
}
