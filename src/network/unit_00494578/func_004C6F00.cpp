/* compiler: ee-gcc2.96-nogcse */
struct Data {int word; int a[1];};
struct Node {unsigned char index; char pad1[3]; Data *data; int pad8; Node *next; short pad10,score; int pad14; Node *object; Node *link;};
extern "C" {
int func_004C7B38(int,unsigned short *,int *,Data *,Node **,int);
int func_004C0D00(int,unsigned short *,int *,Node **) throw();
void func_004C8B50(int,Node *);
void func_004C8BB0(int,Node *);
void func_004C8C38(int,void *);
int func_004C8ED0(unsigned short *);
void func_004C9428(int *,int *,int *);
}
extern "C" int func_004C6F00(int ctx,unsigned short *text,int *values,int *initial,Node **out,int flags) {
 struct Frame { int tmp[12]; Node *head; Node *list; } f;
 f.head=0;
 int err=func_004C7B38(ctx,text,initial,0,&f.head,flags);
 if(err<0) {func_004C8B50(ctx,f.head);return err;}
 err=func_004C0D00(ctx,text,initial,&f.list);
 if(err<0) {func_004C8BB0(ctx,f.list);func_004C8B50(ctx,f.head);return err;}
 func_004C8ED0(text);
 Node *node=f.list;
 while(node) {
 Data *data=node->data;
 func_004C9428(f.tmp,values,data->a);
 err=func_004C7B38(ctx,text+node->index,f.tmp,data,&f.head,flags);
 if(err<0) {func_004C8B50(ctx,f.head);func_004C8BB0(ctx,f.list);return err;}
 f.list=node->next;
 func_004C8C38(ctx,data);
 func_004C8C38(ctx,node);
 node=f.list;
 }
 Node *first=f.head;
 Node *saved=first;
 Node *cur=first->link;
 int score=first->score;
 if(cur) {
 do {
 int v=cur->score;
 cur=cur->link;
 score=score<v?v:score;
 } while(cur);
 }
 if(score<0) score=(short)(score*2); else score=(short)(score/2);
 Node *prev=0;
 cur=saved;
 if(cur) {
 do {
 Node *next=cur->link;
 if(cur->score<score) {
 if(!prev) f.head=next; else prev->link=next;
 if(cur->object)func_004C8C38(ctx,cur->object);
 func_004C8C38(ctx,cur);
 }else prev=cur;
 cur=next;
 } while(cur);
 first=f.head;
 }
 *out=first;
 return 0;
}
