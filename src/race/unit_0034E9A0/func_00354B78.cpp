/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Data { char p[0x104C]; float m104C; char q[0x10D4 - 0x1050]; float m10D4; };
struct E {
    char p0[0x4BA]; unsigned short m4BA; char p1[0x4C0 - 0x4BC]; float m4C0;
    char p2[0x4CC - 0x4C4]; float m4CC; float m4D0; char p3[0x4DC - 0x4D4]; float m4DC; float m4E0;
    unsigned char m4E4; char p4[0x4FC - 0x4E5]; float m4FC;
};
struct Self { char p[0x10]; Data *m10; char q[0x104 - 0x14]; E e; };
extern "C" int func_003683A8(Self *);

extern "C" void func_00354B78(Self *self, float x) {
    if (func_003683A8(self) == 0) {
        E *e = &self->e;
        Data *d = self->m10;
        int on = 0;
        e->m4DC = 0.0f;
        if (e->m4E4 != 0) {
            on = 1;
            e->m4E4 = e->m4E4 - 1;
        }
        if (!(x <= 0.0f)) {
            float f = (x * ((e->m4FC * 60.0f) / 0x1.921fb4p+2f)) / 0x1.b6ac24p+12f;
            if (on != 0) {
                float k = d->m10D4;
                float dt = *(float *)((char *)self + 0x54C);
                float g = (f * k) / (k + 1.0f);
                e->m4DC = g;
                float h = e->m4E0 - (g * dt);
                e->m4E0 = h;
                if (h <= 0.0f) {
                    e->m4E0 = 0.0f;
                    e->m4E4 = 0;
                }
            }
            float s = (d->m104C / 0x1.4532p+21f) * f * *(float *)((char *)self + 0x54C);
            e->m4C0 = e->m4C0 + s;
            if (e->m4CC > 0.0f) {
                if (e->m4BA == 0) {
                    float *q = &e->m4D0;
                    float t = *q - s;
                    *q = t;
                    if (t < 0.0f) *q = 0.0f;
                }
            }
        }
    }
}
