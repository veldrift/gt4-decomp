/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct Data { unsigned w[10]; };
struct Item { u8 id; char pad[3]; Data data; };
struct Node { u8 id; char pad[3]; Item *item; unsigned short count; char padA[2]; Node *next; };
struct Info { char pad[12]; Data *data; void *table; };
struct Base { char pad[0x2c]; Info info; };
struct Obj { char pad[0x24]; Base *base; };
extern "C" int func_004C33A0(Info *,const unsigned short *,u8 **,u8 **);
extern "C" int func_004C9580(unsigned *,int);
extern "C" void func_004C3190(void *,u8 *,unsigned short *);
extern "C" int func_004C8DB8(const unsigned short *,const unsigned short *,int);
extern "C" void *func_004C8C20(Obj *,int);
extern "C" void func_004C8C38(Obj *,void *);
extern "C" void *func_004C4070(void *,const void *,unsigned);
extern "C" void func_004C94A0(unsigned *,const unsigned *,const unsigned *);
extern "C" int func_004C2F48(Obj *obj,const unsigned short *code,unsigned *bits,int add,Node **head) {
 unsigned short buf[16];
 u8 *cur,*end;
 int count=0;
 Info *info=&obj->base->info;
 if(func_004C33A0(info,code,&cur,&end)!=0) return 0;
 while(cur<end) {
  if(func_004C9580(bits,(cur[4]<<8)|cur[5])==1) {
   int len=cur[3];
   func_004C3190(info->table,cur,buf);
   if(func_004C8DB8(buf,code,len)==0) {
    Node *n=*head;
    Item *item=0;
    while(n) {
     if(n->id==len+add) { item=n->item; break; }
     n=n->next;
    }
    if(item==0) {
     item=(Item *)func_004C8C20(obj,0x2c);
     if(item==0) return 0x80000324;
     len+=add;
     func_004C4070(&item->data,&info->data[cur[6]],0x28);
     item->id=len;
     Node *node=(Node *)func_004C8C20(obj,0x10);
     if(node==0) { func_004C8C38(obj,item); return 0x80000324; }
     node->item=item;
     node->id=len;
     node->count=1;
     node->next=*head;
     *head=node;
     count++;
    } else {
     func_004C94A0(item->data.w,item->data.w,info->data[cur[6]].w);
    }
   }
  }
  cur+=7;
 }
 return count;
}
