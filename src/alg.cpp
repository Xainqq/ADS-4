// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
int count = 0;

for (int i = 0; i < len-1; i++) {
for (int j = i + 1; j < len; j++) {
if (arr[i] + arr[j] == value) {
count++;
}
}
}
return count;
return 0;
}

int countPairs2(int* arr, int len, int value) {
int count = 0;

for (int i = 0; i < len-1; i++) {
if(arr[i] > value) { break; }
for (int j = len-1; j > i; j--) {
if (arr[j] > value) { continue; }
if (arr[i] + arr[j] == value) {
count++;
}
}
}
return count;
return 0;
}

int countPairs3(int* arr, int len, int value) {
int count = 0;
int right = len - 1;
int left = 0;
int index = 0;
int mid;

for (int i = 0; i < len - 1; i++) {
int prim = 0;
left = i + 1;
mid = (left + right) / 2;
while (left <= right) {
if (arr[mid] + arr[i] == value) {
count++;
prim = 1;
break;
}
if (arr[mid] + arr[i] > value) {
right = mid - 1;
} else { left = mid + 1; }
mid = (left + right) / 2;
}
if (prim) {
int middle = mid;
index = mid;
while (arr[index + 1] + arr[i] == value) {
count++;
index++;
}
while (arr[middle - 1] + arr[i] == value && middle - 1 != i) {
count++;
middle--;
}
}
}
return count;
}
