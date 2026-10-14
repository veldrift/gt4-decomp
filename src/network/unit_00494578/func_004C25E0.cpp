/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rec { char pad0[4]; unsigned char b4, b5; };
struct Out { int f0; Rec *f4; short f8; unsigned char fa; unsigned char fb; int pad; };
struct Hdr { char f0; char pad1[3]; Out *f4; short f8; short pad2; Hdr *fC; };
extern "C" void *func_004C8C20(int, int);
extern "C" void func_004C8C38(int, void *);
extern "C" int func_004C9580(int, int);
extern "C" short func_004C3680(int, unsigned char, int);

extern "C" int func_004C25E0(int arg0, Hdr **arg1, int arg2, int arg3, Rec *s1, Rec *s5,
                             Rec *base, int ctx, unsigned char s9, int s10) {
    int cnt = 0;
    Out *o = (Out *)func_004C8C20(arg0, arg2 * 0x10);
    if (o == 0) return 0x80000320;
    Hdr *h = (Hdr *)func_004C8C20(arg0, 0x10);
    if (h == 0) {
        func_004C8C38(arg0, o);
        return 0x80000320;
    }
    h->f0 = arg3;
    h->f8 = arg2;
    h->f4 = o;
    h->fC = *arg1;
    *arg1 = h;
    if (s5 >= s1) {
        do {
            if (func_004C9580(ctx, ((s1->b4 & 0x3F) << 3) | (s1->b5 >> 5)) == 1) {
                int v = s10 + (unsigned int)((char *)s1 - (char *)base) / 6;
                o->f4 = s1;
                cnt++;
                o->f0 = v;
                short r = func_004C3680(arg0, s9, v);
                o->fa = s9;
                o->f8 = r;
                o->fb = 0;
                o++;
            }
            s1++;
        } while (s5 >= s1);
    }
    return cnt;
}
