extern "C" {
void func_0022AD20(void *) throw();
void func_0022ACC8(void *, int) throw();
void func_002F9B90(void *, void *);
void func_002F9B20(void *, void *);
void func_002F9B38(void *, int);
void func_00231980(void *, void *);
}
extern char IfScriptEvent__vtable[];
extern char MEventFilter__vtable[];
struct Filter { char *vtable; int member[3]; };
extern "C" void MRenderContext__flushEvent(void *arg0, void *arg1, int arg2, void *arg3) {
    void *buf0[4];
    struct Filter buf1;
    int buf2[4];
    if (arg2 == 1) {
        func_0022AD20(buf0);
        int *p2 = buf2;
        struct Filter *p1 = &buf1;
        func_002F9B90(p2, arg3);
        p1->vtable = MEventFilter__vtable;
        p1->vtable = IfScriptEvent__vtable;
        func_002F9B20(p1->member, p2);
        func_002F9B38(p2, 2);
        func_00231980(buf0[0], p1);
        p1->vtable = IfScriptEvent__vtable;
        func_002F9B38(p1->member, 2);
        p1->vtable = MEventFilter__vtable;
        func_0022ACC8(buf0, 2);
    }
}
