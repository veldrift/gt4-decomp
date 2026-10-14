extern void *memcpy(void *, const void *, unsigned int);
extern char *strcpy(char *, const char *);
extern int func_0057F260(const char *);
typedef struct Output { char name[100]; char desc[100]; int active; char dates[4][16]; int value; char text[20]; char *extra; int extraLen; char *last; int lastLen; } Output;
typedef struct Input { short head; char id[4]; short pad; int status; int unk; int flags; char name[100]; char desc[100]; short extraLen; char extra[100]; short pad2; int active; int value; char text[20]; char gap[20]; char dates[4][16]; short lastLen; char last[100]; } Input;
extern Output *D_0064A21C;
extern void (*D_0064A2D0)(int, Output **, int);
extern int func_0050F5E8(void *, Output **);
extern int func_0050A440(Output **, int, int);
extern int func_0050F5A0(Output *);
extern int func_0050A4E8(Output **);
extern int func_00507AC8(Input *p) {
 struct { char name[100]; short len; } query;
 int id;
 Output *out=0;
 int status=p->status;
 Output *result;
 int flags;
 id=0;
 memcpy(&id,p->id,4);
 result=0;
 D_0064A21C=0;
 if(status==0) {
  memcpy(query.name,p->name,100);
  query.len=func_0057F260(p->name);
  if(func_0050F5E8(&query,&out)!=0) {
   out=0;
   if(func_0050A440(&out,100,100)==0) {
    memcpy(out->name,p->name,100);
    if(func_0050F5A0(out)!=0) func_0050A4E8(&out);
   }
  }
  if(out) {
   out->active=1;
   memcpy(out->name,p->name,100);
   if(p->flags&2) memcpy(out->desc,p->desc,100); else strcpy(out->desc,"<NULL>");
   if(p->flags&4) { out->extraLen=p->extraLen; memcpy(out->extra,p->extra,100); } else strcpy(out->extra,"<NULL>");
   flags=p->flags;
   if(flags&8) out->active=p->active; else out->active=0;
   if(flags&16) { out->value=p->value; memcpy(out->text,p->text,20); } else { out->value=0; strcpy(out->text,"<NULL>"); }
   if(p->flags&32) {
    memcpy(out->dates[0],p->dates[0],16); memcpy(out->dates[1],p->dates[1],16);
    memcpy(out->dates[2],p->dates[2],16); memcpy(out->dates[3],p->dates[3],16);
   } else {
    strcpy(out->dates[0],"00/00/00"); strcpy(out->dates[1],"00:00:00");
    strcpy(out->dates[2],"00/00/00"); strcpy(out->dates[3],"00:00:00");
   }
   if(p->flags&64) { if(out->last) { out->lastLen=p->lastLen; memcpy(out->last,p->last,100); } }
   else { out->lastLen=0; if(out->last) strcpy(out->last,"<NULL>"); }
   result=out;
   D_0064A21C=out;
  }
 }
 if(D_0064A2D0) D_0064A2D0(status,&result,id);
}
