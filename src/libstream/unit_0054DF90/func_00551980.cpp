/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" {
void func_00577F80();
void func_00578908(int);
int func_0058ED40();
int func_0058EEB0(int);
}
struct Flag { int v; };
extern volatile Flag D_0064C710, D_0064C714;
extern int D_0086FD58;
extern char D_0086FC80[];
extern "C" void func_00551980() {
    if (D_0064C710.v) {
        D_0064C710.v = 0;
        D_0064C714.v = 0;
        func_00578908(D_0086FD58);
        int i = 0;
        int ready = 1;
        int off = 0;
        do {
            int *p = (int *)(D_0086FC80 + off);
            while (func_0058EEB0(*p) != ready) func_00577F80();
            i++;
            off += 0x6C;
        } while (i < 2);
        while (func_0058ED40() != 1) func_00577F80();
    }
}
