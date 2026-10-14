/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Table { int count; signed char *len; unsigned short *code; int eob; int zrl; };
struct Data { char pad[0x730]; int coef[64]; int prev[4]; };
struct Obj { int err, detail; char pad[8]; Data d; };
extern Table *D_006240B8[];
extern Table *D_006240C8[];
extern int D_006240D8[];
extern int D_006ABCB8[];
extern "C" void func_0046F260(void *, int, u32) throw();
static inline int *next(int *p) { return p + 1; }
extern "C" int func_00471738(Obj *o, void *out, int comp) {
    Data *d = &o->d;
    Table *tab = D_006240B8[comp];
    int value = o->d.coef[0] - d->prev[comp];
    int mag = value;
    if (value < 0) { mag = -value; value--; }
    int bits;
    if (mag < 256) bits = D_006240D8[mag];
    else if (!(mag > 65535)) {
        bits = D_006240D8[mag >> 8] + 8;
    } else {
        bits = 12;
    }
    if (bits < tab->count) {
        int run = 0;
        int i = 1;
        func_0046F260(out, tab->len[bits], tab->code[bits]);
        func_0046F260(out, bits, value);
        tab = D_006240C8[comp];
        int *scan = next(D_006ABCB8);
        do {
            value = d->coef[*scan];
            int shortRun = run < 16;
            if (value == 0) {
                run++;
                if (i == 63) {
                    int idx = tab->eob;
                    func_0046F260(out, tab->len[idx], tab->code[idx]);
                }
            } else {
                goto check_run;
                do {
                    {
                    int idx = tab->zrl;
                    run -= 16;
                    func_0046F260(out, tab->len[idx], tab->code[idx]);
                    shortRun = run < 16;
                    }
check_run:
                    ;
                } while (!shortRun);
                int bits;
                mag = value;
                if (value < 0) { mag = -value; value--; }
                if (mag < 256) bits = D_006240D8[mag];
                else if (!(mag > 65535)) {
                    bits = D_006240D8[mag >> 8] + 8;
                } else {
                    bits = 11;
                }
                if (shortRun && bits < 11) {
                    int off = run * 11;
                    run = 0;
                    func_0046F260(out, *(signed char *)(off + (int)tab->len + bits), tab->code[off + bits]);
                    func_0046F260(out, bits, value);
                } else {
                    goto fail;
                }
            }
            i++;
            scan++;
        } while (i < 64);
        return 1;
    }
fail:
    o->err = 3; o->detail = 1; return 0;
}
