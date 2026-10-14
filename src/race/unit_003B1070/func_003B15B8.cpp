typedef int s32;

extern "C" void func_003B11A8(char *arg0);
extern "C" void ModelSet2__begin(void *arg0, void *arg1);
extern "C" void ModelSet2__end(void *arg0);
extern "C" void func_004567E0(int arg0);
extern char D_00845370[];

union Word3B15B8 {
    s32 i;
    char *p;
};

extern "C" void func_003B15B8(char *arg0) {
    char *g;
    s32 v;
    char **p;

    if (*(s32 *)(arg0 + 0x6BC) == 0) {
        return;
    }
    if (*(void **)arg0 == 0) {
        return;
    }
    v = *(s32 *)(arg0 + 0x6A0);
    if (v == 3) {
        return;
    }
    if (*(s32 *)(arg0 + 0x6B4) == 0) {
        return;
    }
    g = D_00845370;
    ((union Word3B15B8 *)(g + 4))->i = v;
    p = *(char ***)(arg0 + 0x6B0);
    if (p != 0) {
        *(char **)((char *)p + 0x14) = g;
    }
    func_004567E0(0);
    ModelSet2__begin(*(void **)arg0, 0);
    func_003B11A8(arg0);
    ModelSet2__end(*(void **)arg0);
    func_004567E0(1);
}
