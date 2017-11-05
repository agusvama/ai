int distance(int x, int y){
  return matrix[x][y];
}

bool canTravel(int from, int to){
  return matrix[from][to] != 0;
}
