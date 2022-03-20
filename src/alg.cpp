int countPairs1(int* arr, int len, int value) {
int count = 0;
int halfValue = value / 2;
for (int i = 0; arr[i] <= halfValue; i++) {
int secondPart = value - arr[i];
for (int j = i + 1; arr[j] <= secondPart; j++) {
if (arr[i] + arr[j] == value) {
count++;
}
}
}
return count;
}

int countPairs2(int* arr, int len, int value) {
int count = 0;
int left = 0;
int right = len;
int maxPart{};
while (left < right) {
maxPart = (left + right) / 2;
if (arr[maxPart] > value) {
right = maxPart;
} else {
left = maxPart + 1;
}
}
int halfValue = value / 2;
int i = 0;
for (i; arr[i] < halfValue; i++) {
int secondPart = value - arr[i];
for (int j = maxPart; arr[j] >= secondPart; j--) {
if (arr[i] + arr[j] == value) {
count++;
}
}
}
for (int j = 1; arr[i + 1] == halfValue; i++, j++) {
count += j;
}
return count;
}

int countPairs3(int* arr, int len, int value) {
int count = 0;
int i = 0;
int tempValue = value / 2;
int left = 0;
int right = len;
int mid{};
while (left < right) {
mid = (left + right) / 2;
if (arr[mid] > value) {
right = mid;
} else {
left = mid + 1;
}
}
for (i; arr[i] <= tempValue; i++) {
int left = i + 1;
int tempValue2 = value - arr[i];
while (left < right) {
int mid = (left + right) / 2;
if (arr[mid] < tempValue2) {
left = mid + 1;
} else {
right = mid;
}
}
while (arr[left] == tempValue2) {
count++;
left++;
}
}
return count;
}
