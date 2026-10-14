struct H2 { char b[2]; };
struct W4 { char b[4]; };
struct B100 { char b[100]; };
struct B20 { char b[20]; };
struct Packet { H2 h0; W4 w2; char pad6[2]; W4 w8; H2 hc; H2 he; W4 w10; W4 flags; B100 data; H2 labelLen; char label[102]; W4 we4; B20 b20; H2 tailLen; char tail[102]; W4 w164; };
extern "C" void *func_005A48D8(void *,int,unsigned);
extern "C" void *func_005A4724(void *,const void *,unsigned);
extern "C" void func_0057D9C0(const char *,...);
extern int (*D_0064A2FC)(int,int,int,void *);
extern char D_006C2458[],D_006C2470[];
extern "C" int func_00514AA8(int a0,int a1,int a2,char *p) {
 Packet q;
 func_005A48D8(&q,0,0x168);
 q.h0=*(H2 *)p; p+=2;
 int result=*(short *)&q.h0;
 q.w2=*(W4 *)p; p+=4;
 q.w8=*(W4 *)p; p+=4;
 q.hc=*(H2 *)p; p+=2;
 q.he=*(H2 *)p; p+=2;
 q.w10=*(W4 *)p; p+=4;
 q.flags=*(W4 *)p; p+=4;
 func_0057D9C0(D_006C2458,*(int *)&q.flags);
 q.data=*(B100 *)p; p+=100;
 if (*(int *)&q.flags & 2) {
 q.labelLen=*(H2 *)p; p+=2;
 char *label=q.label;
 func_005A4724(label,p,*(short *)&q.labelLen);
 int len=*(short *)&q.labelLen;
 p+=len;
 func_0057D9C0(D_006C2470,len,label);
 }
 if (*(int *)&q.flags & 4) { q.w164=*(W4 *)p; p+=4; }
 if (*(int *)&q.flags & 8) { q.we4=*(W4 *)p; p+=4; q.b20=*(B20 *)p; p+=20; }
 if (*(int *)&q.flags & 16) {
 q.tailLen=*(H2 *)p; p+=2;
 func_005A4724(q.tail,p,*(short *)&q.tailLen);
 }
 if (D_0064A2FC) D_0064A2FC(a0,a1,a2,&q);
 return result;
}
