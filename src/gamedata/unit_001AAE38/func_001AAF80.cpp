extern "C" int func_001C6BE8(void *, int);
extern "C" void func_001C6D58(void *);
extern "C" void func_001C7298(void *);
extern "C" void func_001AAF80(void *arg0) {
    char *q = (char *)arg0 + 0xBC;
    char *last = (char*)arg0+0x1E9C;
    func_001C6BE8(q, *(int *)((char *)arg0 + 0x1F50));
    func_001C6D58(q);
    func_001C7298(last);
}
