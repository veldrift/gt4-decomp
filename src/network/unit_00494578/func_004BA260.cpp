/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned short u16;
struct Sub { u8 x,len; char p[10]; };
struct Rec { char p[16]; Sub sub; };
struct Work { Rec entries[42]; u8 count,len; };
struct Ctx { char p[0x28]; u16 *text; int *state; Work *work; };
extern Ctx *D_006452D4;
extern "C" {
void func_004BBCB8();
int func_004BBF58(Ctx*);
void func_004BC6E8(Ctx*);
void func_004BC728(void*,void*);
void func_004C3F90(void*,unsigned);
int func_004C6778(Ctx*,void*,int,Work*);
int func_004C8718(Ctx*,void*,int,void*,Rec*);
void *func_004C8C20(Ctx*,int);
void func_004C8C38(Ctx*,void*);
void func_004C8F08(void*,void*);
void func_004C8FD8(void*,void*);
void func_004C9138(void*,void*,int);
char *func_004C9198(char*,char*);
int func_004C9330(char*);
int func_004C93F8(void*);
int func_004C9410(void*);
}
static inline Ctx **context() {return &D_006452D4;}
extern "C" int func_004BA260(void *input,char *out,unsigned capacity,u8 separator) {
 struct Buffers {char joined[128]; char wide[96]; char text[96]; u16 *getWide() {return (u16*)wide;} } b;
 if(*(*context())->state==0x65) return 0x80000243;
 if(capacity-1>=0x7fffU) return 0x80001543;
 if(!out) return 0x80001643;
 if(!input) return 0x80001743;
 int check=func_004C93F8(input);
 if(check>=43 || check==0) return 0x80001143;
 func_004BC6E8(*context());
 func_004BC728(b.text,input);
 if(!separator) return 0x80001243;
 func_004C8FD8(b.getWide(),b.text);
 int error=func_004BBF58(*context());
 if(error<0) return error;
 func_004C8F08((*context())->text,b.getWide());
 *(*context())->state=0x65;
 int status=func_004C6778(*context(),(*context())->text,0,(*context())->work);
 if(status<0) {func_004BBCB8();return status;}
 status=(*context())->work->len;
 func_004C3F90(b.joined,127);
 int wideused;
 int size=(capacity>>1)*2+2;
 void *buf=func_004C8C20(*context(),size);
 if(!buf) {func_004BBCB8();return 0x80000343;}
 char *converted=(char*)func_004C8C20(*context(),size);
 if(!converted) {func_004C8C38(*context(),buf);func_004BBCB8();return 0x80000343;}
 int used=0;wideused=0;
 int i=(*context())->work->count-1;
 int joinedused=0;
 if(i>=0) {
 int offset=i*28;
 do {
  int suboff=offset+16;
  Ctx *ctx=*context();
  status-=((Sub*)((char*)ctx->work+suboff))->len;
  Rec *rec=(Rec*)((char*)ctx->work+offset);
  offset-=28;
  int n=func_004C8718(ctx,buf,size,ctx->text+status,rec);
  if(n<0) {func_004C8C38(*context(),buf);func_004C8C38(*context(),converted);func_004BBCB8();return n;}
  func_004C9138(converted,buf,n);
  int length=func_004C9330(converted);
  int prefix=used+func_004C9330(b.text);
  int need=(*context())->work->count+1;
  need+=prefix;
  need+=length;
  if(capacity<(unsigned)need) {
   func_004C8C38(*context(),buf);func_004C8C38(*context(),converted);func_004BBCB8();out[0]=0;return 0x80001043;
  }
  char *output=out+used;
  used+=length;
  i--;
  func_004C9198(output,converted);
  out[used++]=separator;
  char *dest=b.joined+joinedused;
  u16 *src=b.getWide()+wideused;
  int len=((Sub*)((char*)(*context())->work+suboff))->len;
  wideused+=len;
  func_004C9138(dest,src,len);
  joinedused+=func_004C9330(dest);
  b.joined[joinedused++]=separator;
 } while(i>=0);
 }
 func_004C8C38(*context(),buf);
 func_004C8C38(*context(),converted);
 if(used>0) {used--;out[used]=0;} else {used=0;out[0]=0;}
 if(joinedused>0) b.joined[joinedused-1]=0; else b.joined[0]=0;
 int total=func_004C9410(out);
 total+=func_004C9410(b.joined);
 total+=2;
 total=capacity<(unsigned)total;
 if(total) {func_004BBCB8();out[0]=0;return 0x80001043;}
 func_004C9198(out+used+1,b.joined);
 return D_006452D4->work->count;
}
