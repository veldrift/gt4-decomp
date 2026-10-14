struct Conn {
 void *session; int handle; char p8[0x2028];
 int async,zero; char p2038[0xc]; int flag;
 char p2048[0x34]; char request[0x800]; char host[0x800];
};
struct Self { char p[0x3c]; int state; int pad40; Conn *conn; int arg; };
struct Address { unsigned long value; char pad[8]; };
struct Params { int zero,size,other; };
struct Iface {
 char p[0x14]; int (*open)(Conn *,unsigned long,int,Params *);
 void (*close)(void *);
 int (*write)(void *,char *,int,int *);
 char q[0x4c]; void (*init)(void *);
 char r[8]; void (*format)(char *,unsigned long);
};
extern Iface *D_0064B4B0;
extern char D_0086B540[];
extern char D_006C42F8[];
extern int D_0064C118;
extern "C" int func_0053BC28(char *,int,char *) throw();
extern "C" int func_0053B6E8(char *,char *,Address *,int *) throw();
extern "C" int func_00540BF8(int *,unsigned int,int);
extern "C" void func_00540EB0(int);
extern "C" int func_0057F260(const char *) throw();
extern "C" void *func_005A48D8(void *,int,unsigned int);
extern "C" void func_0057DA20(char *,const char *,...);
extern "C" int func_0053EF68(Self *);
extern "C" int func_0053A878(void *) throw();
extern "C" char *func_005A6AB0(char *,const char *,int) throw();
extern "C" int func_0053E380(Self *self,int arg) {
 Params params;
 Address address;
 char text[16];
 int length,written;
 if(!self) return 2;
 if(self->state) return 0xd6da;
 if(!arg) return 2;
 if(func_0053EF68(self)) return 100;
 if(D_0064C118) goto success;
 func_005A48D8(D_0086B540,0,0x1304);
 { Conn *c=self->conn;
 c->zero=0;
 c->flag=0;
 func_005A6AB0(c->request,(char *)c+0x624,0x200);
 }
 int r;
 r=func_0053B6E8(self->conn->request,self->conn->host,&address,&length);
 if(r) return r;
 r=func_00540BF8(&self->conn->handle,0,self->arg);
 if(r) return r;
 if(!self->conn->handle) return r;
 func_005A48D8(&params,0,12);
 params.size=0x800;
 params.zero=0;
 r=D_0064B4B0->open(self->conn,address.value,length,&params);
 if(r==0) {
  D_0064B4B0->format(text,address.value);
  func_0057DA20(self->conn->request,D_006C42F8,self->conn->host,text,length);
  int n=func_0057F260(self->conn->request);
  r=D_0064B4B0->write(self->conn->session,self->conn->request,n,&written);
  if(r==0) {
   if(func_0057F260(self->conn->request)==written) goto success;
  }
  D_0064B4B0->close(self->conn->session);
 }
 func_00540EB0(self->conn->handle);
 return r;
success:
 Conn *c=self->conn;
 self->state=2;
 func_0053A878((char *)c+0x10);
 *(int *)((char *)self->conn+0x2054)=arg;
 return 0;
}
