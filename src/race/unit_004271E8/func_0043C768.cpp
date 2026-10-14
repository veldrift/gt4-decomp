struct T { signed char b[0x15]; };
struct Src { char pad[0x10]; T t; };
extern "C" void func_004389F8(void *, void *, const signed char *, const unsigned char *, int);
extern "C" void *func_0055F1F0(void *);
extern "C" void func_0043C260(int, void *, void *, signed char *);
extern char D_006A6590[];

extern "C" void func_0043C768(Src *s, void *a1, char *a2, int a3) {
    T t = s->t;
    if (a3 == 2) {
        t.b[4] = -1;
        t.b[5] = -1;
        t.b[6] = -1;
        t.b[7] = -1;
    }
    func_004389F8(a1, func_0055F1F0(a2), &t.b[4], (const unsigned char *)D_006A6590, 0x10);
    func_0043C260(4, a1, a2 + 4, &t.b[1]);
}
