/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned int u32;
extern "C" int func_001C1DF8(u8 *base,u32 size,u32 unused,u32 off,u32 start,u32 n1,u32 n2,u32 *outA,u32 *outB) {
    size += 15;
    u32 stride=size&~15u;
    u32 end=start+n2-1;
    u32 prod=end*stride;
    u32 col=off+n1-1;
    *outA=col;
    *outB=end;
    base+=prod+col;
    u8 *cand=base;
    u32 count;
    u32 i;
    for(i=end;i>=start;i--,base-=stride) {
        count=n1;
        u8 *q=base;
        while(count) {
            if(*q-- !=0) {
                *outB=i;
                goto found;
            }
            count--;
        }
    }
    return 0;
found:
    base=cand;
    count=col;
    while(count>=off) {
        i=n2;
        u8 *q=base;
        while(i) {
            u8 v=*q;
            q-=stride;
            if(v) goto done;
            i--;
        }
        base--;
        count--;
    }
    return 0;
done:
    *outA=count;
    return 1;
}
