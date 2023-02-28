#include <iostream>
#include <ctime>
#include <vector>

std::pair<int, int> Partition(std::vector<int> &A, int start, int end) {
  int temp = start + (rand() % static_cast<int>(end - start + 1));
    std::swap(A[start], A[temp]);
  int comparator = A[start];
  std::pair<int,int> ind = {start, start};
  for (int i = start+1; i <= end; ++i) {
    if (A[i] < comparator) {
      ind.first++;
      ind.second++;
      std::swap(A[ind.second], A[i]);
      std::swap(A[ind.second], A[ind.first]);
    }
    else if (A[i] == comparator) {
      ind.second++;
      std::swap(A[ind.second], A[i]);
    }
  }
    std::swap(A[start], A[ind.first]);
  return ind;
}

void QuickSort(std::vector<int> &A, int start, int end) {
  while (start < end) {
    auto ind = Partition(A, start, end);
      QuickSort(A, start, ind.first - 1);
    start = ind.second + 1;
  }
}


int main() {
    srand(time(0));
    int n,m;
    std::cin>>n>>m;
    
    std::vector<int> starts_of_lines(n);
    std::vector<int> ends_of_lines(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> starts_of_lines[i] >> ends_of_lines[i];
      }
        
    QuickSort(starts_of_lines,0,n-1);
    QuickSort(ends_of_lines,0,n-1);
    
    
    
//    for (int i = 1; i<n+1; ++i) std::cout<<starts_of_lines[i]<<" ";
//    std::cout<<std::endl;
//    for (int i = 1; i<n+1; ++i) std::cout<<ends_of_lines[i]<<" ";
//    std::cout<<std::endl;
    
    for (int i = 0; i<m; ++i) {
        int point;
        std::cin >> point;
        auto N = upper_bound(starts_of_lines.begin(), starts_of_lines.end(), point) - starts_of_lines.begin();
        auto M = lower_bound(ends_of_lines.begin(), ends_of_lines.end(), point) - ends_of_lines.begin();
        std::cout<<N - M<<" ";
    }
    return 0;
}
