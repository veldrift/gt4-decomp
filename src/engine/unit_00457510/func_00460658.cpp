extern int D_0084688C;
extern char D_006AB400[];
extern char D_006AB408[];
extern "C" void func_00460600(float value);
extern "C" int func_00462450(void);
extern "C" void func_005587C0(void *arg0);
extern "C" void func_00558830(void);
extern "C" void func_0057DA20(int arg0, int arg1, ...);

extern "C" void func_00460658(int arg0) {
    char path[0x70];
    if (D_0084688C != 0) {
        func_00460600(1.0f);
        func_0057DA20((int)path, (int)D_006AB400, (int)D_006AB408, func_00462450(), arg0);
        func_005587C0(path);
        func_00558830();
    }
}
