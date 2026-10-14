struct Ent { int f0; int f4; int f8; int fC; };
struct S { char p[0x10]; int f10; char q[8]; Ent e[18]; char r[0x27C - 0x1C - 0x120]; int idx; };
extern "C" int func_0058C840(int, int, int, int);
extern "C" int func_001C5250(S *s) {
    int ret = 0;
    while (s->idx < 18) {
        int i = s->idx;
        Ent *e = &s->e[i];
        if (e->f0 != 0) {
            if (func_0058C840(s->f10, e->f4, e->f8, e->fC) == 0) {
                e->f0 = 0;
                ret = 1;
                s->idx++;
            }
            break;
        }
        s->idx = i + 1;
    }
    return ret;
}
