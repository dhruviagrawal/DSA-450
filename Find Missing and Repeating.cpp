int *findTwoElement(int *arr, int n) {
        // code here
        int size = n;
        int *ptr;
        int res[2];
        int i;
        for (i = 0; i < size; i++) {
        if (arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        else
            res[0] = abs(arr[i]);
    }
 
    
    for (i = 0; i < size; i++) {
        if (arr[i] > 0)
            res[1] = i+1;
    }
    return ptr = res;
    }
