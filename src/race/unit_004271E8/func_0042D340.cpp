typedef int s32;
typedef unsigned short u16;

extern "C" void func_0042D918(s32 v, s32 d, s32 *p);
extern "C" void func_0042D898(char **s, s32 n);

struct S42D340 {
    char pad0[0x10];
    s32 a;
    u16 n1;
    u16 n2;
    s32 b;
    char *c;
};

extern "C" void func_0042D340(struct S42D340 *self, s32 d) {
    s32 i = 0;
    s32 a = self->a;
    s32 b = self->b;
    self->a = (a == 0) ? 0 : a + d;
    self->b = (b == 0) ? 0 : b + d;
    if (self->n1 != 0) {
        do {
            s32 off = i << 2;
            s32 *e;
            s32 v;
            i++;
            e = (s32 *)(off + self->b);
            v = *e;
            *e = (v == 0) ? 0 : v + d;
            func_0042D918(*(s32 *)(off + self->b), d, (s32 *)(off + self->b));
        } while (i < self->n1);
    }
    {
        char *c = self->c;
        i = 0;
        self->c = (c == 0) ? 0 : c + d;
        if (self->n2 != 0) {
            do {
                func_0042D898((char **)(self->c + (i << 4)), d);
                i++;
            } while (i < self->n2);
        }
    }
}
