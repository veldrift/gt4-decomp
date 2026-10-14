extern unsigned int D_0064A254;
extern char **D_0064A24C;
extern void func_00509E18(void *,void *);
extern void func_00509F80(void *,void *);
static inline void a(char **slot) { char *p=*slot; func_00509E18(p+0xD4,p+0x160); }
static inline void b(char **slot) { char *p=*slot; func_00509F80(p+0x70,p+0x164); }
extern void func_00509D80() {
    unsigned int i; for (i=0;i<D_0064A254;i++) {
        a(&D_0064A24C[i]);
        b(&D_0064A24C[i]);
    }
}
