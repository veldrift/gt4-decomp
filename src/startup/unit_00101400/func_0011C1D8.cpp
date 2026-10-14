struct N{char pad[0x10];N*next;int flag;char*data;char pad1c[4];char object[1];};
struct L{int count;char pad[0x10];N*head;};
struct O{char pad[0x60];L*list;};
extern "C" void RaceEntryBase__sortByRank(L*);
extern "C" char *func_00445450(char*);
extern "C" void func_005A609C(char*,char*);
extern "C" void func_00445AE8(char*,char*);
extern "C" void func_0011C1D8(char*s,char*a){
 O*o=*(O**)(a+0x6c);
 RaceEntryBase__sortByRank(o->list);
 N*n=o->list->head;
 int i=0;
 if(o->list->count>0){
 int sentinel=0x157529ff;int*p=(int*)(s+0x454);char*aux=s+0x304;char*dst=s+4;
 do{
  char*ob=(char*)n+0x20;
  func_005A609C(dst,func_00445450(ob));
  func_00445AE8(ob,aux);aux+=0x10;
  char*d=n->data;
  if(*(unsigned char*)(d+0x5b6))*p=*(int*)(d+0x718);else *p=sentinel;
  if(!n->flag)*(int*)(s+0x4a0)=i;
  ++i;n=n->next;++p;dst+=0x80;
 }while(i<o->list->count);
 }
}
