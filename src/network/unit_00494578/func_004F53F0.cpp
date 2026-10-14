/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Record { char p0[0x18]; int mode; char p1c[0x50]; signed char flag; char tail[3]; };
struct Data { char pad[0x1d8]; Record records[16]; char tail[0x5258]; int count; };
struct Obj { char pad[0x5a8]; Data *data; };
extern Obj D_00645570;
extern char D_006C0650[];
extern "C" int func_004F0C38(Obj *,const char *) throw();
extern "C" int func_004F0B08(Obj *,Record *) throw();
extern "C" void func_004F87E8(Obj *,int);
extern "C" int func_004F53F0(Record *rec,Obj *o) {
 if (o==0) o=&D_00645570;
 if (func_004F0C38(o,D_006C0650)) return func_004F0B08(o,rec);
 int mode=rec->mode;
 int handled=0;
 if (mode<0 || mode==1) {
  func_004F87E8(o,mode);
  handled=1;
 }
 if (handled) return func_004F0B08(o,rec);
 int *n=&o->data->count;
 int idx=(*n)++;
 if (idx<16) o->data->records[idx]=*rec;
 if (rec->flag) {
  func_004F87E8(o,rec->mode);
  if (rec->flag) {
   func_004F87E8(o,rec->mode);
   func_004F0B08(o,rec);
  }
 }
}
