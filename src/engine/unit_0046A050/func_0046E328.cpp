/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Reader { char p0[0x10]; u32 f10; char p1[0xC]; int f20; };
struct Elem { char p[0x14]; char *p14; };
struct Obj { int f0, f4; char p0[0xA88 - 8]; Reader rd; char p1[0xDDC - 0xA88 - sizeof(Reader)]; u32 fDDC; };
extern "C" {
void func_0046D748(Obj *) throw();
int func_0046D770(Obj *) throw();
u32 func_0046E978(Reader *);
int func_0046EA08(Reader *);
int func_00472110(Elem *, int);
int func_004721E0(Elem *, u32 *);
void func_004722E0(Elem *);
}
static inline void error(Obj *self, const int &code) { self->f0=code; self->f4=1; }
extern "C" int func_0046E328(Obj *self) {
    Reader *rd = &self->rd;
    u32 limit = rd->f10 + (func_0046EA08(rd) - 2);
    u32 cur;
    do {
        u32 v = func_0046E978(rd);
        u32 a = v >> 4;
        u32 b = v & 0xF;
        u32 buf[16];
        int sum, n;
        int r;
        Elem *e;
        if (a >= 2) goto invalid;
        if (b >= 3) goto invalid;
        sum = 0;
        u32 *p = buf;
        n = 0xF;
        do {
            n--;
            u32 x = func_0046E978(rd);
            *p = x;
            p++;
            sum += x;
        } while (n >= 0);
        r = func_0046D770(self);
        if (r == 0) return r;
        if (sum == 0) goto invalid;
        char *row = (char *)self + a * 0x6C;
        e = (Elem *)(row + b * 0x24 + 0x10F8);
        r = func_00472110(e, sum);
        if (r == 0) { error(self,2); return r; }
        r = func_004721E0(e, buf);
        if (r == 0) { error(self,4); return r; }
        for (int j = 0; j < sum; j++) e->p14[j] = func_0046E978(rd);
        func_004722E0(e);
        r = func_0046D770(self);
        if (r == 0) return r;
        cur = rd->f10;
    } while (cur < limit);
    if (cur == limit && rd->f20 == 0) {
        self->fDDC |= 4;
        return 1;
    }
    func_0046D748(self);
    return 0;
invalid:
    self->f0=4;
    self->f4=1;
    return 0;
}
