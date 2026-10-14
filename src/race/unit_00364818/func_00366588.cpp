/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Inf {char pad[0xC4]; int c4; float c8;};
struct Sub {char pad0[0x466]; signed char s466; unsigned char u467; char pad1[0x4B2-0x468]; unsigned char u4B2; char pad2[0x632-0x4B3]; signed char s632;};
struct Car {char pad0[0x14]; int w14; char pad1[0x104-0x18]; Sub sub;};
struct Main {Inf *inf; char pad[0xF8A0-4]; int count;};
extern "C" Car *func_0034C190(Main *, int);
extern "C" void func_00463C28(void *, int, int);
extern "C" void func_00366588(Main *self){
    Inf *inf = self->inf;
    if (inf->c4 != 0 && (int)inf->c8 == 0xB3) {
        int i = 0;
        if (self->count > 0) {
            do {
                Car *c = func_0034C190(self, i++);
                Sub *s = &c->sub;
                if (s->u4B2 == 0) {
                    s->s632 = 1;
                    if (s->s466 == 0) {
                        s->s466 = 2;
                        if ((unsigned char)(s->u467 + 0xFE) >= 3)
                            func_00463C28((char *)c + 0x14, 6, 1);
                    }
                }
            } while (i < self->count);
        }
    }
}
