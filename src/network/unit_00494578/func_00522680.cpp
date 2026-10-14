extern "C" int func_0056FA90(void *);
extern "C" int func_0056FB50(void *, int *);
extern "C" long func_00571790(void *, int *);
extern char D_00863EC0[];
extern int D_00863F00;
extern int D_0064B450;
extern int D_0064B444;
extern "C" void func_00522680() {
    func_00571790(D_00863EC0, &D_00863F00);
    if (func_0056FB50(D_00863EC0, &D_00863F00) >= 0) {
        func_0056FA90(D_00863EC0);
        D_0064B450 = -1;
        D_0064B444 = 0;
    }
}
