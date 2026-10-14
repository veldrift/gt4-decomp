/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x14]; int entries[0x13C]; int flag; };
struct Info { char pad[0x60]; int *count; };
extern char D_00645570[];
extern "C" int ResultArcade__goal(Obj *, Info *, int);
extern "C" int func_004FA0E0(char *, int);
extern "C" void ResultLinkBattle__virtual_05(Obj *self, Info *info, int arg2) {
    int n = *info->count;
    int total = 0;
    for (int i = 0; i < n; i++) {
        if (self->entries[i]) total++;
    }
    if (total >= n - 2) {
        if (!self->flag) func_004FA0E0(D_00645570, 5);
        self->flag = 1;
    }
    ResultArcade__goal(self, info, arg2);
}
