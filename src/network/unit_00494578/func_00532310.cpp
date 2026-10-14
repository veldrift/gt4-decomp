struct Obj { char pad[0x158]; int state; };
struct Header { unsigned char type,subtype; unsigned short length,count,index; unsigned char sequence; char pad[3]; int total,offset; } __attribute__((aligned(8)));
struct Packet { char data[512]; } __attribute__((aligned(8)));
extern "C" void *memcpy(void *,const void *,unsigned int);
extern "C" int func_00532080(int,Obj *,int,unsigned int,unsigned int,int,const void *) throw();
extern "C" int func_00532230(int,Obj *,int,unsigned int,unsigned int,int,const void *) throw();
extern "C" unsigned int func_00539528();
extern "C" void *func_005A4724(void *,const void *,unsigned int);
extern "C" int func_00532310(signed char a,Obj *p,int id,unsigned int type,unsigned int subtype,int size,const char *src) {
    Header h __attribute__((aligned(8)));
    Packet packet __attribute__((aligned(8)));
    int offset=0;
    int sendSize=0;
    signed char flags;
    unsigned int sendType,sendSubtype;
    unsigned int count;
    if(type>=6) return 23;
    if(subtype>=256) return 23;
    if(size<=0) return 23;
    if(!src) return 23;
    if(!p) return 23;
    if(p->state==4) return 15;
    if(size>=511) {
        if(id==65535) return 31;
        count=(unsigned int)(size+489)/490;
        flags=a|0x50;
        sendType=0;
        sendSubtype=2;
        h.sequence=func_00539528();
    } else {
        sendSize=size;
        flags=a;
        sendType=type;
        sendSubtype=subtype;
        offset=sendSize;
        count=1;
        func_005A4724(&packet,src,sendSize);
    }
    for(int i=0;i<(int)count;i++) {
        if(sendSize!=size) {
            int n=size-offset;
            h.index=i;
            h.type=type;
            if(n>490) n=490;
            h.total=size;
            h.subtype=subtype;
            h.count=count;
            h.length=n;
            sendSize=n+20;
            h.offset=offset;
            memcpy(&packet,&h,20);
            const char *chunk=src+offset;
            func_005A4724(packet.data+20,chunk,n);
            offset+=n;
        }
        if(!p || p->state==2) {
            int r=func_00532080(flags,p,id,sendType,sendSubtype,sendSize,&packet);
            if(r) return r;
        } else {
            int r=func_00532230(flags,p,id,sendType,sendSubtype,sendSize,&packet);
            if(r) return r;
        }
    }
    return 0;
}
