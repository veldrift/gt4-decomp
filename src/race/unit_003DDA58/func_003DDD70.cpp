typedef unsigned int u32;
extern "C" void func_003DDC70(char *,int) throw();
extern "C" void func_003DDD70(char *self) {
    if(*(int *)self==0x34504552) {
        int old=*(int *)(self+4);
        *(int *)(self+4)=(int)self;
        int delta=(int)self-old;
        int *p24=(int *)(self+0x24);
        *p24+=delta;
        u32 i;
        for(i=0;i<*(u32 *)(self+0x20);i++) {
            func_003DDC70(*(char **)(self+0x24)+i*0x7c,delta);
        }
        int *p30=(int *)(self+0x30);
        int *p38=(int *)(self+0x38);
        *p30+=delta;
        *p38+=delta;
        *(int *)(self+0x18)=0;
        i=0;
        if(*(u32 *)(self+0x20)) {
        float *p=(float *)(*(char **)(self+0x24)+8);
        do {
            if(*(float *)(self+0x18)<*p) *(float *)(self+0x18)=*p;
            p=(float *)((char *)p+0x7c);
            ++i;
        } while(i<*(u32 *)(self+0x20));
        }
    }
}
