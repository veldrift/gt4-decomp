extern "C" int func_004F1BA0(void *arg0, void *arg1);
extern "C" void func_00215298(int n);
extern "C" int func_001F1368(void *ctx);
extern char D_00645570[];

typedef struct {
    int pad[6];
    int timeout;
    int a;
    int b;
    int c;
    int d;
    int size;
} WaitParams;

extern "C" void func_001F2A28(void *arg0, int a1, int a2, int a3, int a4, int a5, int a6)
{
    WaitParams params;

    params.timeout = a1;
    params.a = a2;
    params.b = a3;
    params.c = a4;
    params.d = a5;
    params.size = a6;
    while (func_004F1BA0(D_00645570, &params) == 0) {
        func_00215298(1);
    }
    func_001F1368(arg0);
}
