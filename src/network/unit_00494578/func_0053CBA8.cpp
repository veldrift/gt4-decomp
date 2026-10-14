/* compiler: ee-gcc2.96-as2004 */
typedef unsigned long long Addr __attribute__((aligned(4)));
struct Self;
struct Conn { void *handle; int resource; int flags; char pC[0x1024-12]; int status; char p1028[0x1008]; int multi; char p2034[0x2c]; void (*cb)(Self *,int,int,Addr); };
struct Self { char p0[12]; Addr addr; char p14[0x28]; int state; int f40; Conn *conn; };
struct Table {char p0[0x18]; void (*close)(void *); char p1c[0x64]; int (*parse)(Addr *,void *); };
struct Data { char keys[12][256]; char values[12][256]; unsigned int count; };
extern Table *D_0064B4B0;
extern char D_006C40D8[],D_006C4188[],D_006C41A0[];
extern "C" int func_0053BD78(Self *,int *) throw();
extern "C" int func_0053C2F0(Self *,const char *,const char *) throw();
extern "C" void func_0053A878(void *) throw();
extern "C" void func_00540EB0(int);
extern "C" int func_00540F10(int,const char *,int,int);
extern "C" int func_00540F98(int,void *);
extern "C" int func_00594470(const char *,const char *,unsigned int);
extern "C" void *func_005A48D8(void *,int,unsigned int);
extern "C" int func_0053CBA8(Self *self) {
 int done=0;
 int result=func_0053BD78(self,&done);
 if(result || done) {
   if(self->conn->status==200 && done) {
     int err;
     if(!self->conn->multi) {
       void *text=0;
       err=func_00540F10(self->conn->resource,D_006C40D8,0,1);
       if(!err) {
         err=func_00540F98(self->conn->resource,&text);
         if(!err) D_0064B4B0->parse(&self->addr,text);
       }
     } else {
       Data *data=0;
       err=func_00540F10(self->conn->resource,D_006C40D8,0,1);
       if(!err) {
         err=func_00540F98(self->conn->resource,&data);
         if(!err) {
           unsigned int i;
           for(i=0;i<data->count;i++) {
             if(!func_00594470(D_006C4188,data->keys[i],256)) D_0064B4B0->parse(&self->addr,data->values[i]);
           }
         }
       }
     }
     if(err) result=err;
   }
   func_00540EB0(self->conn->resource);
   self->conn->resource=0;
   D_0064B4B0->close(self->conn->handle);
   self->conn->handle=0;
   func_005A48D8((char *)self->conn+0x1024,0,0x100c);
   if(!self->conn->multi) {
     if(result) {
       result=func_0053C2F0(self,D_006C41A0,D_006C40D8);
       if(!result) func_0053A878((char *)self->conn+16);
       else {
         self->conn->cb(self,result,self->conn->flags,self->addr);
         self->conn->cb=0;self->state=0;
       }
     } else {
       self->conn->cb(self,0,self->conn->flags,self->addr);
       self->conn->cb=0;self->state=0;
     }
   } else {
     self->conn->cb(self,result,self->conn->flags,self->addr);
     self->conn->cb=0;self->state=0;
   }
 }
 return result;
}
