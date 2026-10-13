typedef int s32;

struct hObject;

struct MMCFile {
    s32 w0;
    s32 vtbl;
    s32 w8;
    s32 w0c;
    s32 owner;
    s32 flag;
};

extern char D_00690F00[];
extern char mMemoryCardFile__vtable[];
extern "C" void *func_00326750(unsigned int size, int align, const char *name);
extern "C" void *hObject__structor_0(struct hObject *arg0);
extern "C" void func_00309348(void *, void *);

extern "C" void mMemoryCardFile__structor_0(s32 arg0, s32 arg1) {
    s32 sp[4];
    MMCFile *temp_v0;
    s32 vt;
    temp_v0 = (MMCFile *)func_00326750(0x18, 4, D_00690F00);
    hObject__structor_0((struct hObject *)temp_v0);
    vt = (s32)mMemoryCardFile__vtable;
    temp_v0->owner = arg1;
    temp_v0->vtbl = vt;
    temp_v0->flag = 0;
    sp[0] = (s32)temp_v0;
    func_00309348((void *)arg0, sp);
}
