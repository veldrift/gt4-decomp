typedef int s32;
typedef unsigned char u8;

extern char D_00697BC0[];
extern char D_00697BD8[];
extern char D_00697BE0[];
extern char D_00697BF8[];
extern char D_00697C10[];
extern char D_00697C28[];
extern char D_0082B570[];
extern char D_0082BBB8[];
extern char D_0082C200[];
extern char D_0082C848[];

extern "C" void func_0030C378(void *arg0, const char *fmt, ...);
extern "C" void *func_00326578(void);
extern "C" void func_00326728(s32 arg0, s32 arg1);

extern "C" void func_00219460(s32 arg0) {
    func_0030C378((void *)arg0, D_00697BC0);
    char *close = D_00697BD8;
    func_00326728(arg0, (s32)&D_0082B570);
    func_0030C378((void *)arg0, close);
    func_0030C378((void *)arg0, D_00697BE0);
    func_00326728(arg0, (s32)&D_0082BBB8);
    func_0030C378((void *)arg0, close);
    func_0030C378((void *)arg0, D_00697BF8);
    func_00326728(arg0, (s32)&D_0082C200);
    func_0030C378((void *)arg0, close);
    func_0030C378((void *)arg0, D_00697C10);
    func_00326728(arg0, (s32)&D_0082C848);
    func_0030C378((void *)arg0, close);
    func_0030C378((void *)arg0, D_00697C28);
    func_00326728(arg0, (s32)func_00326578());
    func_0030C378((void *)arg0, close);
}
