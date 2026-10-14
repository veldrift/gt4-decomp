/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rec { int f[11]; };
extern "C" Rec D_00622E90, D_00622EC0, D_00622EF0, D_00622F20;
extern "C" void func_00439108(Rec *out, int a, int b) {
    int sel = 0;
    if (a) sel += 1;
    if (b) sel += 2;
    Rec *src = &D_00622E90;
    switch (sel) {
    case 0: break;
    case 1: src = &D_00622EC0; break;
    case 2: src = &D_00622EF0; break;
    case 3: src = &D_00622F20; break;
    }
    *out = *src;
}
