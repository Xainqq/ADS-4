int countPairs1(int* arr, int len, int value) {
    int count = 0;
    int tmp = 0;
    for (int i = 0; i < len; i++) {
        for (int j = (len - 1); j >= (i + 1); j--) {
            if (arr[j] < arr[j - 1]) {
                tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
    }
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(int* arr, int len, int value) {
    int count = 0, r;
    int tmp = 0;
    for (int i = 0; i < len; i++) {
        for (int j = (len - 1); j >= (i + 1); j--) {
            if (arr[j] < arr[j - 1]) {
                tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
    }
    for (int i = len - 1; i >= 0; i--) {
        if (arr[i] > value) {
            continue;
        } else {
            r = i;
            break;
        }
    }
    for (int i = 0; i < r - 1; i++) {
        for (int j = r; j >= i + 1; j--) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs3(int* arr, int len, int value) {
    int count = 0, l, r, mid, sec, right;
    bool flag = 0;
    int tmp = 0;
    for (int i = 0; i < len; i++) {
        for (int j = (len - 1); j >= (i + 1); j--) {
            if (arr[j] < arr[j - 1]) {
                tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
    }
    for (int i = len - 1; i >= 0; i--) {
        if (arr[i] > value) {
            continue;
        } else {
            right = i;
            break;
        }
    }
    for (int i = 0; i < right; i++) {
        l = i + 1;
        r = right;
        sec = value - arr[i];
        flag = 0;
        while ((l <= r) && (flag != true)) {
            mid = (l + r) / 2;
            if (r-l+1 == 3) {
                if (arr[mid + 1] == sec) {
                    count++;
                    flag = true;
                }
                if (arr[mid - 1] == sec) {
                    count++;
                    flag = true;
                }
            }
            if (arr[mid] < sec) {
                l = mid + 1;
            }
            if (arr[mid] > sec) {
                r = mid - 1;
            }
            if (arr[mid] == sec) {
                if (arr[mid + 1] == arr[mid]) {
                    for (int j = mid + 1; j <= r; j++) {
                        if (arr[j] == sec) {
                            count++;
                        } else {
                            break;
                        }
                    }
                }
                if (arr[mid - 1] == arr[mid]) {
                    for (int j = mid - 1; j >= l; j--) {
                        if (arr[j] == sec) {
                            count++;
                        } else {
                            break;
                        }
                    }
                }
                count++;
                flag = true;
            }
        }
    }
    return count;
}
