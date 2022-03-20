// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int res = 0;
  for (int i = 0; i < (len - 1); i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        res++;
      }
    }
  }
  return res;
  return 0;
}
int countPairs2(int *arr, int len, int value) {
  int res = 0;
  int to_left = len-1;
  int to_right = 0;
  while (arr[to_left] > value) {
    to_left--;
  }
  for (to_right; to_right < to_left; to_right++) {
    for (int i = to_right + 1; to_left+1 > i; i++) {
      if (arr[to_right] + arr[i] == value) {
        res++;
      }
    }
  }
  return res;
  return 0;
}
int countPairs3(int *arr, int len, int value) {
  int res = 0, left = 0, right = len - 1;
  int mid = 0;
  int count = 0;
  while (left < right - 1) {
    mid = (left + right) / 2;
    if (arr[mid] < value) {
      right = mid;
    } else {
      left = mid;
    }
  }
  len = right - 1;
  for (int i = 0; i < len; i++) {
    left = i + 1, right = len - 1;
    count = 0;
    while (left < right) {
      mid = (left + right) / 2;
      if (arr[mid] < (value - arr[i])) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    while (arr[left] == (value - arr[i])) {
      count++;
      left++;
    }
    res += count;
  }
  return res;
  return 0;
}
