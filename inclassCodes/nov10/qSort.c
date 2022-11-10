
void qSort(void *base, size_t n, size_t size, int (*compare)(const void *a, const void *b)){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - 1; j++){
            if (compare(base + j*size, base + (j+1)*size) > 0){
                swap(base + j*size, base + (j+1)*size, size);
            }
        }
    }
}

int compare(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int main(){
    int n = 10;
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    qSort(a, 10, sizeof(int), compare);
    for (int i = 0; i < 10; i++){
        printf("%d ", a[i]);
    }
    return 0;

}