struct Res { char pad[0x40C]; int cnt; char pad2[0x10]; };
struct Rec { int p0; char *p4; char *p8; int pc; };
struct Tbl { int p0; int p4; int p8; int pc; Rec *recs; };
struct Obj { int p0; Tbl *t; };
extern "C" {
float func_0042A4A8(void *, float);
float func_0042D430(void *, float);
int func_0042AA00(Res *, int, int);
void func_0042AA58(Res *, int);
void func_0042C300(Rec *, int, Res *, float);
void func_0042C348(Rec *, int, Res *, float, float);
int func_00429060(Obj *o, int ri, int a, int b, float f0, float f1, int c0, int c1, float *tp) {
    Res r;
    int idx;
    int res = 0;
    int first;
    float t;
    Rec *rec;
    if (o->t == 0) return res;
    if (a >= 0) {
        idx = a;
        first = 1;
    } else if (b >= 0) {
        idx = b;
        first = 0;
    } else {
        return 0;
    }
    func_0042AA00(&r, c0, c1);
    char *tt = (char *)o->t;
    rec = (Rec *)(*(char **)(tt + 0x10) + ri * 16);
    if (first)
        t = func_0042D430(rec->p4 + idx * 32, f0);
    else
        t = func_0042A4A8(rec->p8 + idx * 32, f0);
    if (tp) *tp = t;
    if (first)
        func_0042C300(rec, idx, &r, t);
    else
        func_0042C348(rec, idx, &r, t, f1);
    res = r.cnt;
    func_0042AA58(&r, 2);
    return res;
}
}
