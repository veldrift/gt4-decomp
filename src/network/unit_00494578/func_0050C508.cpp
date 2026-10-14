extern int D_0064A308;
extern int D_0064A30C;
extern char D_008A0400[];
extern char D_008A01D8[];
extern "C" void func_0050AA88();
extern "C" void func_0050A9A0(void*) throw();
extern "C" void func_0050A9C0(int) throw();
extern "C" void func_0050AAE8(int,const void*) throw();
extern "C" int func_0050B460(int,int,int,void*) throw();
extern "C" int func_0052EFC0(void*);
extern "C" int func_0052F010(void*,void*);
struct Task { int id; void (*fn)(); char data[24]; };
extern "C" int func_0050C508(char *self,int arg1,int arg2) {
    Task task;
    int out[4];
    self[0x14]=0;
    self[0x25]=0;
    self[0x4f]=0;
    int r = -15;
    if(D_0064A308 != 1) return r;
    r = -16;
    if(D_0064A30C == 0) return r;
    int mode = *(int*)(self+0x50);
    *(int*)D_008A0400 = arg1;
    *(int*)D_008A01D8 = arg2;
    if(mode == 2) {
        if(func_0052EFC0(&task)) return -2;
        func_0050A9A0(task.data);
        task.fn = func_0050AA88;
        func_0050A9C0(3);
        func_0050AAE8(0x2c,self);
        r = func_0052F010(&task,out);
        if(r) {
            func_0050A9C0(0);
            return -2;
        }
        return r;
    }
    int c = func_0050B460(1,0xf3,0xc4,self);
    int x = -5;
    if(c==0) x=0;
    return x;
}
