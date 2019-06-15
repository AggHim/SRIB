#include <iostream>
using namespace std;

int Balloon(int a[], int elements, int k)
{
    if (elements == 0)
        return 0;
    if (elements < 3)
        return elements;
    int temp = -1;
    int t;
    for (int i = 0; i < elements - 2; i++) {
        if (a[i + 1] - a[i] == a[i + 2] - a[i + 1]) {
            if (a[i + 1] - a[i] == k) {
                int arr[elements - 3];
                int h = 0;
                for (int j = 0; j < elements; j++) {
                    if (!(j == i || j == i + 1 || j == i + 2)) {
                        arr[h] = a[j];
                        h++;
                    }
                }
                t = temp;
                temp = Balloon(arr, elements - 3, k);
            }
            if (temp != -1 && t != -1) {
                if (temp > t)
                    temp = t;
            }
        }
    }
    if (temp == -1) {
        return elements;
    }
    return temp;
}

int main()
{
    int t;
    cin >> t;
    for (int z = 0; z < t; z++) {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int ans = Balloon(a, n, k);
        cout << "#" << z + 1 << " " << ans << "\n";
    }
    return 0;
}
