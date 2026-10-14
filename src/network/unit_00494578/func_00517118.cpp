struct Context { char pad[0x104]; int id; };
struct Item { char pad[4]; unsigned char flag; char pad5[7]; int id; };
extern "C" Context *D_00854150;
extern "C" Item *func_00515EC8(unsigned int) throw();
extern "C" int func_00517118(unsigned int index) {
    if (index >= 0x200) return 0x17;
    Context *ctx = D_00854150;
    if (!ctx) return 9;
    Item *p = func_00515EC8(index);
    int r = 9;
    if (!p) return r;
    if (p->id != ctx->id) return r;
    r = 0;
    p->flag = 1;
    return r;
}
