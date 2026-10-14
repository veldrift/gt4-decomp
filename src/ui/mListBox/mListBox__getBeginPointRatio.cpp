extern "C" float mListBox__get_width(char *) throw();
extern "C" float mListBox__getTotal(char *) throw();
extern "C" float mListBox__getBeginPointRatio(char *self) {
 float width=mListBox__get_width(self);
 float total=mListBox__getTotal(self);
 float pos=-*(float *)(self+0x120);
 if (pos < 0.0f) return 0.0f;
 float max=1.0f-width/total;
 float ratio=pos/total;
 if (max <= ratio) return max;
 return ratio;
}
