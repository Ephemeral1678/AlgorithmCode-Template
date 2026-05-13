#include<iostream>
#include<vector>
#include<string>
using namespace std;

int n;
vector<int> ret;

void print(vector<int> ret){
    for (int i = 0; i < n;++i){
        cout << ret[i];
        if (i < n - 1){
            cout << " ";
        }
    }
    cout << endl;
}

void InsertSort(vector<int> &ret){
    for (int i = 1; i < n;++i){
        int temp = ret[i];
        int j = i;
        while(j >= 0 && ret[j - 1] > temp){
            ret[j] = ret[j - 1];
            j--;
        }
        ret[j] = temp;
        print(ret);
    }
}

void ShellSort(vector<int> &ret){
    int n = ret.size();
    for (int gap = n / 2; gap > 0; gap /= 2){
        for (int i = gap; i < n; ++i){
            int temp = ret[i];
            int j = i;
            while(j >= gap && ret[j-gap] < temp){
                ret[j] = ret[j - gap];
                j -= gap;
            }
            ret[j] = temp;
        }
        print(ret);
    }
}

void bubbleSort(int &ans, vector<int> &ret){
    for (int i = 1; i < n; ++i){
        int flag = 0;
        for (int j = 0; j < n - i; ++j){
            if(ret[j] > ret[j + 1]){
                flag = 1;
                ans++;
                swap(ret[j], ret[j + 1]);
            }
        }
        if(flag == 0){
            return;
        }
    }
}


//快速排序
int partition(vector<int> &ret, int low, int high){
    int pivot = ret[low];
    int i = low;
    int j = high;
    while(i < j){
        while(i < j && ret[j] >= pivot){
            j--;
        }
        if(ret[j] < pivot){
            ret[i] = ret[j];
            i++;
        }
        while(i < j && ret[i] <= pivot){
            i++;
        }
        if(ret[i] > pivot){
            ret[j] = ret[i];
            j--;
        }
    }
    ret[i] = pivot;
    return i;
}

void QuickSort(vector<int> &ret, int low, int high){
    if(low >= high){
        return;
    }

    int pivotidx = partition(ret, low, high);
    print(ret);

    QuickSort(ret, low, pivotidx - 1);
    QuickSort(ret, pivotidx + 1, high);
}

//堆排序
void heapify(vector<int> &ret, int n, int i){
    int max_idx = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if(left < n && ret[left] > ret[max_idx]){
        max_idx = left;
    }
    if(right < n && ret[right] > ret[max_idx]){
        max_idx = right;
    }
    if(max_idx != i){
        swap(ret[i], ret[max_idx]);
        heapify(ret, n, max_idx);
    }
}

void HeapSort(vector<int> &ret){
    for (int i = n / 2 - 1/*第一个非叶子节点*/; i >= 0; --i){
        heapify(ret, n, i);
    }
    print(ret);
    for (int i = n - 1; i > 0; --i){
        swap(ret[0], ret[i]);
        heapify(ret, i, 0);
        print(ret);
    }
}

//选择排序
void ChoiceSort(vector<int> &ret){
    for (int i = 0; i < n - 1; ++i){
        int minidx = i;
        int minv = ret[i];
        for (int j = i; j < n; ++j){
            if(ret[j] < minv){
                minv = ret[j];
                minidx = j;
            }
        }
        swap(ret[i], ret[minidx]);
        print(ret);
    }
}

//归并排序
void merge(vector<int> &ret, int left, int mid, int right){
    vector<int> temp(n);
    int i = left;
    int j = mid + 1;
    int k = 0;
    while(i <= mid && j <= right){
        if(ret[i] >= ret[j]){
            temp[k++] = ret[i++];
        }
        else{
            temp[k++] = ret[j++];
        }
    }
    while(i <= mid){
        temp[k++] = ret[i++];
    }
    while(j <= right){
        temp[k++] = ret[j++];
    }
    for (int i = 0; i < n; ++i){
        ret[i] = temp[i];
    }
}

void MergeSort(vector<int> &ret){
    int step = 1;
    while(step < n){
        for (int i = 0; i < n; i += step * 2){
            int left = i;
            int mid = min(i + step - 1, n - 1);
            int right = min(i + 2 * step - 1, n - 1);
            merge(ret, left, mid, right);
        }
        print(ret);
        step *= 2;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        ret.resize(n);
        for (int i = 0; i < n; ++i){
            cin >> ret[i];
        }
        ChoiceSort(ret);
        cout << endl;
        ret.clear();
    }
    
    
    
    return 0;
}