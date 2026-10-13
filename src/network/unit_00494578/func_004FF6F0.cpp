extern char D_00645570[];
int func_0052F6F0(void *, int);

struct func_004FF6F0_arg0 {
    int unk0;
    int unk4;
};

struct func_004FF6F0_glob {
    char pad0[0x3F3C];
    int unk3F3C;
    int unk3F40;
};

void func_004FF6F0(void *arg0) {
    struct func_004FF6F0_arg0 *a = (struct func_004FF6F0_arg0 *)arg0;
    struct func_004FF6F0_glob *g;
    int buf[4];
    int r;

    r = func_0052F6F0(buf, a->unk0);
    g = (struct func_004FF6F0_glob *)D_00645570;
    if (r == 0) {
        if (a->unk0 == g->unk3F3C) {
            if (a->unk4 == buf[0]) {
                g->unk3F40 = 1;
                return;
            }
        }
        ((struct func_004FF6F0_glob *)D_00645570)->unk3F40 = 0;
    }
}
