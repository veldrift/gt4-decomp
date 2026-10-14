struct S { int a; int b; };
extern "C" int func_0046D7A0(S *) throw();
extern "C" int func_0046DA78(S *) throw();
extern "C" int func_0046D960(S *p) {
    if (p->b != 0) return 0;
    if (func_0046DA78(p) == 1) {
        for (;;) {
            switch (func_0046DA78(p)) {
            case 0:
                continue;
            case 2:
                break;
            case 3:
                if (func_0046D7A0(p) != 0) return 1;
                break;
            default:
                return 0;
            }
            break;
        }
    }
    p->a = 1;
    p->b = 1;
    return 0;
}
