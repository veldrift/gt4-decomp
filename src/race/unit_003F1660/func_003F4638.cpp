/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Data { float front, rear, width; };
struct Car { char pad0[0x10]; Data *data; char pad14[0x65-0x14]; signed char next; char pad66[0x7e - 0x66]; unsigned char depth; char pad7f[0x6a0-0x7f]; float sum; };
struct Obj { char pad[0xf81a]; unsigned char mode; char pad2[0xf8a0-0xf81b]; int count; };
struct Result { float z1,x1,z2,x2,speed; char pad[12]; };
extern "C" Car *func_0034C190(Obj *, int);
extern "C" void func_003F4080(Obj *, int, int, int) throw();
extern "C" int func_003F40F8(Result *, Car *, Car *) throw();
extern "C" int func_003F42D0(Car *, Car *, float *, float *, float, float) throw();
extern "C" void func_003F4428(Obj *, int, int, float) throw();
extern "C" float func_003F4450(Obj *, int, int) throw();
extern "C" float func_003F44A0(Car *, Car *, float, float) throw();
extern "C" int func_003F4520(float,float,float,float,float,float) throw() __attribute__((const));
extern "C" void func_004694A0(void *);
extern "C" void func_004694F8(void *,float,float,float,float,float,float);
extern "C" void func_00469868(Car *,Car *);
extern "C" void func_00469918(Car *,Car *,float,float,float,float);
extern "C" void func_003F4638(Obj *o) {
    int i;
    for (i=0; i<o->count; i++) func_0034C190(o,i)->depth=0;
    for (i=0; i<o->count; i++) func_004694A0((char *)func_0034C190(o,i)+0x14);
    for (i=0; i<o->count; i++) {
        for (int j=i+1; j<o->count; j++) {
            Car *a=func_0034C190(o,i);
            Car *b=func_0034C190(o,j);
            Result r;
            if (func_003F40F8(&r,a,b)==0) {
                func_003F4428(o,i,j,0.0f);
                func_003F4428(o,j,i,0.0f);
                func_003F4080(o,i,j,0);
                func_003F4080(o,j,i,0);
            } else {
                Data *db=b->data;
                Data *da=a->data;
                float front=da->front+db->rear;
                float rear=da->rear+db->front;
                float width=(da->width+db->width)*0.5f;
                func_004694F8((char *)a+0x14,r.speed,r.z1,r.x1,front,rear,width);
                func_004694F8((char *)b+0x14,r.speed,r.z2,r.x2,rear,front,width);
                func_003F4080(o,i,j,func_003F4520(r.speed,r.z1,r.x1,front,rear,width));
                func_003F4080(o,j,i,func_003F4520(r.speed,r.z2,r.x2,rear,front,width));
                float p,q;
                if(o->mode!=6) {
                    if(func_003F42D0(a,b,&p,&q,r.z1,r.x1)) func_00469918(a,b,r.z1,r.x1,p,q);
                    else func_00469868(a,b);
                    if(func_003F42D0(b,a,&p,&q,r.z2,r.x2)) func_00469918(b,a,r.z2,r.x2,p,q);
                    else func_00469868(b,a);
                } else {
                    func_00469868(a,b);
                    func_00469868(b,a);
                }
                func_003F4428(o,i,j,func_003F44A0(a,b,r.z2,r.x2));
                func_003F4428(o,j,i,func_003F44A0(b,a,r.z1,r.x1));
            }
        }
    }
    for (i=0; i<o->count; i++) {
        float sum=0.0f;
        for(int j=0;j<o->count;j++) sum+=func_003F4450(o,i,j);
        if(sum>1.0f) sum=1.0f;
        func_0034C190(o,i)->sum=sum;
    }
    for(i=0;i<o->count;i++) {
        int depth=0;
        int next=i;
        for(int j=0;j<o->count;j++) {
            next=func_0034C190(o,next)->next;
            if(next==-1) break;
            depth++;
        }
        func_0034C190(o,i)->depth=depth;
    }
}
