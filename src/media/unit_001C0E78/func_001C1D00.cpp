/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned int u32;
extern "C" int func_001C1D00(u8 *base,u32 size,u32 unused,u32 off,u32 start,u32 n1,u32 n2,u32 *outA,u32 *outB) {
    size=(size+15)&~15u;
    u32 i;
    u32 prod=start*size;
    u32 end=start+n2;
    u32 lim=off+n1;
    *outA=off;
    *outB=start;
    base+=prod+off;
    u8 *cand=base;
    for(i=start;i<end;i++,base+=size) {
        unused=n1;
        u8 *q=base;
        while(unused) {
            if(*q++ !=0) {
                *outB=i;
                goto found;
            }
            unused--;
        }
    }
    return 0;
found:
    base=cand;
    unused=off;
    while(unused<lim) {
        i=n2;
        u8 *q=base;
        while(i) {
            u8 v=*q;
            q+=size;
            if(v) goto done;
            i--;
        }
        base++;
        unused++;
    }
    return 0;
done:
    *outA=unused;
    return 1;
}
