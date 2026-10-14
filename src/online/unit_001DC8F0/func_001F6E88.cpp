extern "C" void *func_004F9F70(void *lock);
extern "C" void func_004FA048(void *lock, void *obj);
extern "C" void func_005A609C(void *arg, char *name);
extern "C" char D_00645570[];

extern "C" void func_001F6E88(void *self, void *a0, void *obj) {
    void *lock = func_004F9F70(D_00645570);
    if (lock != 0) {
        func_005A609C(obj, (char *)lock + 0x7A);
    }
    func_004FA048(D_00645570, lock);
}
