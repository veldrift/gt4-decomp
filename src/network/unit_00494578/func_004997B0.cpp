/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_0049B220(unsigned,int,int,int*);
extern "C" int func_004AA788(void*);
extern "C" int func_004AA650(int,void*);
extern "C" void func_004A4F48(int,int,int,int,int,int,int,void*);
extern "C" void func_004A2038(int);
extern "C" void func_004A4910(void);
extern "C" void func_004A4100(int,int,int,int);
extern "C" void func_004A4418(int,int);
extern "C" int func_004997B0(int psm,int w,int h,void *p) {
    int out;
    int size=func_0049B220(psm,w,h,&out);
    int result=-1;
    if(size) {
        int n=func_004AA788(p);
        if(n>=0) goto setup;
        {
            n=func_004AA650(size,p);
            if(n<0) goto done;
            {
                func_004A4F48(n,psm,out,0,0,w,h,p);
                func_004A2038(1);
                func_004A4910();
            }
        }
        if((n & 0x80000000)==0) {
setup:
            func_004A4100(0,n,psm,out);
            func_004A4418(w,h);
        }
done:
        result=n;
    }
    return result;
}
