extern "C" float mListBox__get_width(char *) throw();
extern "C" int mListBox__getTotalItemCount(char *) throw();
extern "C" float mListBox__getTotal(char *) throw();
extern "C" int mListBox__canIncrement(char *self) {
 int index=*(int *)(self+0x124);
 if (!(index+1 < mListBox__getTotalItemCount(self))) return 0;
 float width=mListBox__get_width(self);
 float total=mListBox__getTotal(self);
 return width < *(float *)(self+0x120)+total;
}
