struct S { char p0[8]; int type; char p1[0x60]; int c; float a; float b; };
extern "C" void func_003FBDA0(char *);
extern "C" void func_003FBE70(S *);
extern "C" void func_003FC320(S *);
extern "C" void func_003FBC58(S *s)
{
    float f = s->a;
    if (f > 0.0f) {
        float g = f - s->b;
        s->a = g;
        if (g < 0.0f) s->a = 0.0f;
    }
    switch (s->type) {
    case 0: func_003FBDA0((char *)s); break;
    case 1: func_003FBE70(s); break;
    }
    func_003FC320(s);
    int v = s->c;
    if (v < 0) {
        s->c = 0;
        v = 0;
    }
    int n = v + 1;
    s->c = n;
    if (n >= 3) s->c = 2;
}
