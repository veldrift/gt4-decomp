typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct Owner;
struct Vt {
    char pad[0x48];
    int (*f48)(u32, int, void *, void *, void *);
};
struct Vt78 {
    char pad[0x78];
    void (*f78)(void *, void *);
};
struct Arg {
    u32 id;
    int kind;
    char pad8[0x14];
    u16 h1C;
    char pad1E[0x38 - 0x1E];
    void *data;
    int len;
    char pad40[0x80 - 0x40];
    struct Owner *owner;
};
extern struct Vt *D_0064B710;
int func_0051E018(int);
int func_0051E158(struct Owner *, unsigned, int, const void *, unsigned, int);
int func_00520230(int);
void func_00520280(u8 *, u8 *, u8 *);
int func_00530F88(void);
int func_00538BF8(void **, unsigned long long);
int func_00538C68(void **);
int func_00538F70(void *, unsigned);
int func_00539068(void *, unsigned);
void *func_005A4724(void *, const void *, unsigned);
void *func_005A48D8(void *, int, unsigned);

int func_0051DE30(struct Arg *arg0) {
    char sp0[0x40];
    char sp40[0x40];
    u8 tri[3];
    char sp90[0x40];
    void *spD0;
    int s5;
    int s0 = 0;
    void *data = arg0->data;
    int len = arg0->len;
    spD0 = 0;
    if ((u32)arg0->kind >= 2) return 2;
    {
        int ret;
        s5 = func_0051E018(len);
        ret = func_00538BF8(&spD0, (u32)s5);
        if (ret != 0) return ret;
        {
            char *p = (char *)spD0;
            func_00520280(&tri[0], &tri[1], &tri[2]);
            p[0] = tri[0];
            p[1] = tri[1];
            p[2] = tri[2];
            p += 3;
            func_00538F70(p, arg0->h1C);
            p += 2;
            func_00539068(p, func_00530F88());
            p += 4;
            if (func_00520230(arg0->id) != 0) {
                if (D_0064B710 != 0) ((struct Vt78 *)D_0064B710)->f78(sp0, sp40);
                s0 = D_0064B710->f48(arg0->id & 0x7FFFFFFF, 0xFFFF, sp0, sp40, sp90) != 0 ? 0xCB30 : 0;
                func_005A4724(p, sp90, 0x40);
            } else {
                func_005A48D8(p, 0, 0x40);
            }
            p += 0x40;
            if (data != 0 && len != 0) {
                func_005A4724(p, data, len);
                p += len;
            }
            if (s0 == 0) {
                s0 = func_0051E158(arg0->owner, arg0->kind == 0 ? 0 : 0x15, 0xFFFF, spD0, s5, 1);
            }
            if (spD0 != 0) func_00538C68(&spD0);
            return s0;
        }
    }
}
