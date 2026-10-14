extern "C" int mListBox__getTotalItemCount(char *) throw();
extern "C" void mListBox__setFocusIndex(char *,int) throw();
extern "C" int func_002B5580(char *,int);
extern "C" int func_002B3C88(char *self,int count) {
 int index=*(int *)(self+0x124);
 if (index>=0) {
 if(count>0) {
 do {
 --index;
 if (index<0) {
 if (*(int *)(self+0x10c)!=0) index=mListBox__getTotalItemCount(self)-1;
 else index=-1;
 if (index<0) return 0;
 }
 if (func_002B5580(self,index)==0) {
 --count;
 if (index==*(int *)(self+0x124)) index=-1;
 }
 if (index<0) return 0;
 } while(count>0);
 }
 if (index>=0) {mListBox__setFocusIndex(self,index);return 1;}
 }
 return 0;
}
