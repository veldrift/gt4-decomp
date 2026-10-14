struct S { char pad[0xC]; int h; int x; };
extern "C" int func_005ADCA0(void *);
extern "C" int func_00539A78(S *s) {
    int sp[8];
    if (s == 0) return 2;
    s->x = 0;
    sp[1] = 1;
    sp[2] = 1;
    int h = func_005ADCA0(sp);
    if (h == -1) return 0x384;
    s->h = h;
    return 0;
}
