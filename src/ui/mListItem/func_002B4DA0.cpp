struct Item { int count; void *vt; int object; };
extern "C" {
void func_002550B8(void *,int);
void func_00255110(void *,void *);
Item *func_002B49B8(void *,unsigned int) throw();
int mListBox__get_total_item_count(void *) throw();
void func_002B4FD8(void *,int,int,int);
int func_002B50F0(void *);
void func_00309378(void *,int);
void *func_0030BA08(void *,int);
}
extern "C" int func_002B4DA0(void *self,int index,int arg) {
 int sp[4]; int tmp[4];
 int result=0;
 if(index>=0 && index<mListBox__get_total_item_count(self)) {
  result=func_002B49B8(self,index)->object;
  if(result==0 && arg!=0) {
   int *hold=tmp;
   int object=func_002B50F0(self);
   func_0030BA08(hold,object);
   func_00255110(sp,hold);
   func_00309378(hold,2);
   result=sp[0];
   func_002B4FD8(self,index,arg,result);
   func_002550B8(sp,2);
  }
 }
 return result;
}
