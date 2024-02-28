void wavePrint(vector<vector<int> >v){
  int row=v.size();
  int col=v[0].size();
  for(int startcol=0;startcol<col;startcol++){
    // print top to bottom
    if(startcol & 1 ==0){//even no of column so even number have 0 in the end 0&1==0
      for(int i=0;i<row;i++){
        cout<<v[i][startcol];
      }
    }
    else{
      for(int i=row-1;i>0;i--){
        cout<<v[i][startcol];
      }
    }
  }
}
    
