typedef int s32;
struct Obj { char pad[0x10]; char *p10; };
extern "C" void func_0015F3E0(void *, void *);
extern "C" void func_0015F388(void *, int);
extern "C" void func_0042FC50(char *, char *);
extern "C" char *func_005A6AB0(char *, const char *, s32);
extern "C" void MGame__setReturnToLastMenuProject(void *, void *arg1) {
    Obj *tmp[4];
    char project[0x40];
    char *base;
    char *src;
    char *dst;
    func_0015F3E0(tmp,arg1);
    base=tmp[0]->p10;
    func_0015F388(tmp,2);
    src=base+0x3A39C;
    dst=base+0x3A368;
    func_005A6AB0(project,src,0x40);
    func_0042FC50(dst,project);
}
