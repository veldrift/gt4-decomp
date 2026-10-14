/* compiler: ee-gcc2.96-no-strict-aliasing */
struct St {
    char p0[0x4F0];
    float f4F0;
    short s4F4;
    short s4F6;
    short s4F8;
    short s4FA;
    char p1[2];
    float f500, f504, f508;
    char p2[0x5F8 - 0x50C];
    short tab[2];
    char p3[0x606 - 0x5FC];
    unsigned char b606, b607;
};
struct Self {
    char p0[0x10];
    char *eng;
    char p1[0x104 - 0x14];
    St st;
};
struct Self2 { char p0[0x54C]; float f54C; };
extern "C" float func_0034ECF0(char *, short, short, float *);
extern "C" void func_00354B78(Self *, float) throw();
extern "C" float func_00355410(Self *, float) throw();

extern "C" float func_003554A0(Self *self, float x) {
    float tmp[4];
    St *st = &self->st;
    char *eng = self->eng;
    char *s3 = eng + 0x134;
    float k = ((Self2 *)self)->f54C;
    float r = x;
    float zero = 0.0f;
    float f21;
    float f4;
    float f2;
    if (*(float *)(s3 + 0xFC) == zero) {
        st->f4F0 = x;
        st->b606 = 0;
        st->f500 = x;
    } else {
        f21 = func_0034ECF0(s3, st->s4FA, st->s4FA, tmp);
        float f0 = st->f4F0;
        float loopzero = 0.0f;
        st->f500 = f0;
        float *tabA = (float *)(eng + 0x138);
        float *tabB = (float *)(eng + 0x140);
        float ratio = (f0 * (float)st->s4FA) / f21;
        short *p = &st->s4F4;
        int offset = 0xe0;
        int count = 1;
        do {
            if (*(float *)((char *)tabA + offset) != loopzero) {
                int v = (unsigned short)*p + (int)(((ratio - (float)*p) * *(float *)((char *)tabB + offset)) * k);
                *p = v;
                if ((short)v < 0) *p = 0;
            }
            count--;
            p++;
            offset += 4;
        } while (count >= 0);
        int one = 1;
        f4 = x * func_0034ECF0(s3, st->s4F4, st->s4F6, tmp);
        f2 = 0.5f - ((float)st->s4FA * 0x1p-12f * 0.25f);
        if (f2 < 0.0625f) f2 = 0.0625f;
        unsigned char m = st->b607;
        st->f504 = 0.0f;
        st->f508 = (st->f508 + (f4 + ((1.0f - x) * f2))) * 0.5f;
        switch (m) {
        case 0:
            if (x < 0.75f) {
                float f2b = st->f504;
                float f1 = st->f4F0 - 0x1.999998p-1f;
                if (f1 < f2b) f1 = f2b;
                st->b607 = one;
                st->f504 = f1 * 0.00390625f;
            }
            break;
        case 1:
            if (x > 0.9f) st->b607 = 0;
            break;
        }
        r = 1.0f;
        st->f4F0 = f4;
        if (!(f21 <= f4)) r = f4 / f21;
        st->s4F8 = st->s4F4;
        if ((unsigned short)st->s4F8 < st->s4F6) st->s4F8 = st->s4F6;
    }
    float f20 = func_00355410(self, r);
    float f1 = 0.0f;
    if (*(float *)(s3 + 0xFC) > f1) {
        f2 = st->f500;
        f2 -= 0.75f;
        if (f2 <= f1 || f20 <= f1) st->b606 = 1;
        else {
            if (f20 >= 587.99994f) f1 = f2;
            else f1 = f2 * f20 * 0.0017006804f;
            int n = (int)(f1 * f1 * 128.0f);
            if (n > 127) n = 127;
            if (n < 1) n = 1;
            st->b606 = n;
        }
    }
    func_00354B78(self, f20);
    return f20;
}
