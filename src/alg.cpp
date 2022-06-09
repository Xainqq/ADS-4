// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
  int count = 0;
  for (int v = 0; v < len - 1; v++) {
    for (int c = v + 1; c < len; c++) {
      if (arr[c] + arr[v] == value)
        count++;
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  for (int v = 0; v < len - 1; v++) {
    if (arr[v] <= value) {
      for (int c = len - 1; c > v; c--) {
        if (arr[v] + arr[c] == value)
          count++;
      }
    }
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int v = 0; v < len - 1; a++) {
    int left = v;
    int right = len;
    while (left < right - 1) {
      int m = (left + right) / 2;
      if (arr[v] + arr[m] == value) {
        count++;
        int c = m + 1;
        while (arr[v] + arr[c] == value && c < right) {
          count++;
          c++;
        }
        c = m - 1;
        while (arr[v] + arr[c] == value && c > left) {
          count++;
          c--;
        }
        break;
      }
      if (arr[v] + arr[m] > value)
        right = m;
      else
        left = m;
    }
  }
  return count;
}
