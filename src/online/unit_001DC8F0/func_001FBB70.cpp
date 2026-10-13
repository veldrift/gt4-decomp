extern "C" char D_00645570[];
extern "C" int func_004FA008(char *lock);
extern "C" void func_004FA048(char *lock, char *p);

extern "C" void func_001FBB70(int arg0, int arg1)
{
    char *p = (char *)func_004FA008(D_00645570);
    if (p != 0) {
        *(int *)(p + arg1) = arg0;
    }
    func_004FA048(D_00645570, p);
}
