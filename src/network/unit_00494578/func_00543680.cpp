struct Node { char pad[8]; int key; int *fC; void *f10; void *f14; void *f18; };
extern "C" void *func_00538988(int) throw();
extern "C" Node *func_00542A28(void *, unsigned) throw();
extern "C" Node *func_00542928(void) throw();
extern "C" void func_005429F0(void *, Node *) throw();
extern "C" int func_00538830(int *) throw();
extern "C" int func_00543008(int, int, int *) throw();
extern "C" int func_005428E8(void *) throw();
extern "C" int func_005433B0(int, int, void *) throw();
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" int func_00543680(int a, int b, int c, int d) {
    void *head = func_00538988(a);
    if (!head) return -1;
    Node *src = func_00542A28(head, b);
    if (!src) return -1;
    head = func_00538988(c);
    if (!head) return -1;
    Node *dst = func_00542A28(head, d);
    if (!dst) {
        dst = func_00542928();
        dst->key = d;
        func_005429F0(head, dst);
    }
    if (func_00538830(src->fC) == 0)
        func_00543008(c, d, src->fC);
    if (func_005428E8(src->f18) == 0) {
        func_005433B0(c, d, src->f18);
        func_005A4724(dst->f10, src->f10, 0x10C);
        func_005A4724(dst->f14, src->f14, 0x10C);
    }
    return 0;
}
