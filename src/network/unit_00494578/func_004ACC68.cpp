/* compiler: ee-gcc2.96-no-strict-aliasing */
struct NodeA { NodeA *next; void *item; };
struct NodeB { void *item; int pad; NodeB *next; };
extern volatile int D_00631878;
extern NodeA *D_006318BC;
extern NodeB *D_006318B0;
extern "C" void func_004ACD88(void *);
extern "C" void func_004AD750(void *);
extern "C" void func_004B0708();
extern "C" void func_00577F80();
extern "C" void func_004ACC68() {
    if (D_00631878 != 0) {
        return func_00577F80();
    }
    func_004B0708();
    NodeA *a = D_006318BC;
    while (a != 0) {
        func_004ACD88(a->item);
        a = a->next;
    }
    NodeB *b = D_006318B0;
    while (b != 0) {
        func_004AD750(b->item);
        b = b->next;
    }
    D_00631878 = 1;
}
