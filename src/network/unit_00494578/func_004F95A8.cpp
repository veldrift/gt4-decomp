/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Row { int a,b,c,d; };
struct Desc { int a,b; Row *rows; int count; };
struct Options { int type, mode, zero; unsigned char flag; char pad[3]; };
extern "C" void func_004F8820(void *, int) throw();
extern "C" int func_00515638();
extern "C" int func_005156B0(int *,int,int,int,int,Options *);
extern "C" int func_00515BE8(int *,int,int);
extern "C" int func_00515C68(int,void (*)(),void (*)(),void (*)());
extern "C" int func_004F95A8(void *self, Desc *desc, int flag, void (*cb1)(), void (*cb2)(), void (*cb3)()) {
    Options options;
    int handle;
    int r;
    int i=0;
    options.type=45;
    options.mode=1;
    options.zero=0;
    options.flag=flag;
    func_00515638();
    for (;i<desc->count;i++) {
        Row *row=(Row *)(i*16+(int)desc->rows);
        r=func_005156B0(&handle,row->a,row->b,row->c,row->d,&options);
        if(r) { func_004F8820(self,r); return -1; }
    }
    r=func_00515BE8(&handle,desc->a,desc->b);
    if(r) { func_004F8820(self,r); return -1; }
    r=func_00515C68(handle,cb1,cb2,cb3);
    if(r) { func_004F8820(self,r); return -1; }
    return handle;
}
