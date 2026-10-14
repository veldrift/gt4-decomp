/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x9200]; int flags[16]; };
extern char D_006A3088[];
extern "C" int Pitmen__getMotion(Obj *) throw();
extern "C" int func_00429D20(int,int,const char *,float);
extern "C" void func_0035BEE0(void *,int);
extern "C" void func_003CF868(Obj *self,int state,int index,int team,float *time,int *motion,void *obj) {
    if (state < 0) {
        self->flags[team*4+index]=0;
        return;
    }
    unsigned int full=0x9200+(team*4+index)*4;
    int *flag=(int *)((unsigned int)self+full);
    if (*flag==0 && func_00429D20(Pitmen__getMotion(self),*motion,D_006A3088,*time)) {
        *flag=1;
        func_0035BEE0(obj,index);
    }
}
