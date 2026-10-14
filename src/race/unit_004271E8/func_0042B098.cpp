struct E32 { char pad[32]; };
struct Tbl {
    unsigned short n0;
    unsigned short n1;
    E32 *a;
    E32 *b;
    E32 *c;
};
extern "C" void func_0042A328(void *, int);
extern "C" void func_0042D340(void *, int);
extern "C" void func_0042B098(Tbl *t, int d) {
    int i = 0;
    E32 *a = t->a;
    E32 *b = t->b;
    E32 *c = t->c;
    t->a = a ? (E32 *)((char *)a + d) : 0;
    t->b = b ? (E32 *)((char *)b + d) : 0;
    t->c = c ? (E32 *)((char *)c + d) : 0;
    if (t->n0) {
        do {
            func_0042D340(&t->a[i++], d);
        } while (i < t->n0);
    }
    i = 0;
    if (t->n1) {
        do {
            func_0042A328(&t->b[i++], d);
        } while (i < t->n1);
    }
}
