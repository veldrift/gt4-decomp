struct Node { int a; int len; int pad8; };
struct Args { int a0; int a4; Node *n8; Node *nC; Node *n10; };
struct Str9 { char c[9]; };
extern char D_0064C3E4_dummy;
extern char *D_0064C3E4;
extern char D_006C8480[];
extern char D_006C8478[];
extern "C" int func_0054AA70(int, char *);
extern "C" int func_0054AB88(int, char *);
extern "C" int func_0054AC90(int, char *, int, int, int);
extern "C" void func_00576788(char *);
extern "C" void func_005767C0(char *);
extern "C" int func_0057F260(char *);
extern "C" void func_005A5DC8(char *, char *);
extern "C" char *func_005A609C(char *, const char *);

extern "C" int func_0054BCE8(int arg0, Args *arg1) {
    struct { int r; char pad[12]; char path[64]; } L;
    func_00576788(D_0064C3E4 + 0x34);
    char *p = L.path;
    L.path[0] = 0x2F;
    func_005A609C(p + 1, *(char **)arg1);
    L.r = func_0054AA70(arg0, p);
    if (L.r == 0 || (L.r == 2 && (L.r = func_0054AB88(arg0, p)) == 0)) {
        func_005A5DC8(p, D_006C8478);
        char *s2 = p + func_0057F260(p);
        func_005A609C(s2, *(char **)arg1->n8);
        L.r = func_0054AC90(arg0, p, arg1->n8->len, 0, arg1->n8->pad8);
        if (L.r == 0) {
            if (arg1->nC != 0) {
                func_005A609C(s2, *(char **)arg1->nC);
                L.r = func_0054AC90(arg0, p, arg1->nC->len, 0, arg1->nC->pad8);
                if (L.r != 0) goto done;
            }
            if (arg1->n10 != 0) {
                func_005A609C(s2, *(char **)arg1->n10);
                L.r = func_0054AC90(arg0, p, arg1->n10->len, 0, arg1->n10->pad8);
                if (L.r != 0) goto done;
            }
            *(Str9 *)s2 = *(Str9 *)D_006C8480;
            L.r = func_0054AC90(arg0, p, arg1->a4, 0, 0x3C4);
        }
    }
done:
    func_005767C0(D_0064C3E4 + 0x34);
    return L.r;
}
