int positive(int x){
  return x > 0; // 0 is false, 1 is true
}

int negative(int x){
  return x < 0;
}

int zero(int x){
  return x == 0;
}

int next(int x){
  return x + 1;
}

int previous(int x){
  return x - 1;
}

int max(int x, int y){
  if(x > y){
    return x;
  }else{
    return y;
  }
}

int min(int x, int y){
  if(x < y){
    return x;
  }else{
    return y;
  }
}
