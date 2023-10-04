# sort


## vector sort(오름차순)
```
#inlclude <algorithm>
#inlclude <vector>

vector<xy> V;

sort(V.begin(), V.end());
```

## struct vector sort(오름차순)
```
#inlclude <algorithm>
#inlclude <vector>

typedef strcut {
    int x;
    int y;
}xy;

vector<xy> V;

void SortByXy(xy a, xy b) {
    if(a.x == b.x){
        return a.y < b.y
    }else{
        return a.x < b.x
    }
}

sort(V.begin(), V.end(), SortByXy);
```

## priority queue sort(오름차순)
```
#include <queue>
#inlclude <vector>
#include <fuctional>

priority_queue<xy, vector<xy>, greater<int>> Q;
```
```
#inlclude <vector>
#inlcude <queue>

struct compare {
    bool operator () (const int& a, const int& b) const {
         return a > b;
    }
}

priority_queue<xy, vector<xy>, compare> Q;
```
```
#inlclude <vector>
#inlcude <queue>

typedef strcut {
    int x;
    int y;
}xy;

struct compare {
    bool operator () (const xy& a, const xy& b) const {
        if(a.x == b.x){
            return a.y > b.y;
        }else{
            return a.x > b.x;
        }
    }
}

priority_queue<xy, vector<xy>, compare> Q;
```
