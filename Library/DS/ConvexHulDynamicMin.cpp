struct cht{
    struct Line{
        int a;
        long long b;
        long long val;
        double xLeft;
        bool type;
        Line(long long _a = 0 , long long _b = 0){
            a = _a;
            b = _b;
            xLeft = -1e16;
            type = 0;
            val = 0;
        }
        long long valueAt(int x) const{
            return 1LL * a * x + b;
        }
        friend bool areParallel(const Line &l1, const Line &l2){
            return l1.a == l2.a;
        }
        friend double intersectX(const Line &l1 , const Line &l2){
            return areParallel(l1 , l2) ? 1e16 : 1.0 * (l2.b - l1.b) / (l1.a - l2.a);
        }
        bool operator < (const Line &l2) const{
            if(!l2.type)
                return a < l2.a;
            return xLeft > l2.val;
        }
    };
    set < Line >  hull;
    bool hasPrev(set < Line > :: iterator it){
        return it != hull.begin();
    }
    bool hasNext(set < Line > :: iterator it){
        return it != hull.end() && next(it) != hull.end();
    }
    bool irrelevant(const Line &l1 , const Line &l2 , const Line &l3){
        return intersectX(l1,l3) <= intersectX(l1,l2);
    }
    bool irrelevant(set < Line > :: iterator it){
        return hasPrev(it) && hasNext(it) && (irrelevant(*next(it) , *it , *prev(it)));
    }
    set < Line > :: iterator updateLeftBorder(set < Line > :: iterator it){
        if(!hasNext(it)){
            return it;
        }
        double val = intersectX(*it , *next(it));
        Line buf(*it);
        it = hull.erase(it);
        buf.xLeft = val;
        it = hull.insert(it, buf);
        return it;
    }
    void addLine(int a , long long b){
        Line l3 = Line(a, b);
        auto it = hull.lower_bound(l3);
        if(it != hull.end() && areParallel(*it , l3)){
            if(it -> b > b){
                it = hull.erase(it);
            }
            else{
                return;
            }
        }
        it = hull.insert(it, l3);
        if(irrelevant(it)){
            hull.erase(it);
            return;
        }
        while(hasPrev(it) && irrelevant(prev(it))){
            hull.erase(prev(it));
        }
        while(hasNext(it) && irrelevant(next(it))){
            hull.erase(next(it));
        }
        it = updateLeftBorder(it);
        if(hasPrev(it)){
            updateLeftBorder(prev(it));
        }
        if(hasNext(it)){
            updateLeftBorder(next(it));
        }
    }
    long long getBest(int x){
        Line q;
        q.val = x;
        q.type = 1;
        auto bestLine = hull.lower_bound(q);
        if(bestLine == hull.end()){
            return 1e16;
        }
        return bestLine -> valueAt(x);
    }
};
