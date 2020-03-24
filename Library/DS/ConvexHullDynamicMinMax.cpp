// NOTE : This problem requres implementation of Standard convex hull trick which I have copied from :
// http://codeforces.com/blog/entry/11339 

// SOURCE : http://codeforces.com/blog/entry/11339 

/*
 * Dynamic version of data structure
 * to be used in dynamic programming optimisation
 * called "Convex Hull trick"
 * 'Dynamic' means that there is no restriction on adding lines order
 */
class ConvexHullDynamic
{
    typedef long long coef_t;
    typedef long long coord_t;
    typedef long long val_t;
 
    /*
     * Line 'y=a*x+b' represented by 2 coefficients 'a' and 'b'
     * and 'xLeft' which is intersection with previous line in hull(first line has -INF)
     */
private:
    struct Line
    {
        coef_t a, b;
        double xLeft;
 
        enum Type {line, maxQuery, minQuery} type;
        coord_t val;
 
        explicit Line(coef_t aa=0, coef_t bb=0) : a(aa), b(bb), xLeft(-INFINITY), type(Type::line), val(0) {}
        val_t valueAt(coord_t x) const { return a*x+b; }
        friend bool areParallel(const Line& l1, const Line& l2) { return l1.a==l2.a; }
        friend double intersectX(const Line& l1, const Line& l2) { return areParallel(l1,l2)?INFINITY:1.0*(l2.b-l1.b)/(l1.a-l2.a); }
        bool operator<(const Line& l2) const
        {
            if (l2.type == line)
                return this->a     < l2.a;
            if (l2.type == maxQuery)
                return this->xLeft < l2.val;
            if (l2.type == minQuery)
                return this->xLeft > l2.val;
        }
    };
 
private:
    bool            isMax; //whether or not saved envelope is top(search of max value)
    std::set<Line>  hull;  //envelope itself
 
private:
    /*
     * INFO:        Check position in hull by iterator
     * COMPLEXITY:  O(1)
     */
    bool hasPrev(std::set<Line>::iterator it) { return it!=hull.begin(); }
    bool hasNext(std::set<Line>::iterator it) { return it!=hull.end() && std::next(it)!=hull.end(); }
 
    /*
     * INFO:        Check whether line l2 is irrelevant
     * NOTE:        Following positioning in hull must be true
     *              l1 is next left to l2
     *              l2 is right between l1 and l3
     *              l3 is next right to l2
     * COMPLEXITY:  O(1)
     */
    bool irrelevant(const Line& l1, const Line& l2, const Line& l3) { return intersectX(l1,l3) <= intersectX(l1,l2); }
    bool irrelevant(std::set<Line>::iterator it)
    {
        return hasPrev(it) && hasNext(it)
               && (    isMax && irrelevant(*std::prev(it), *it, *std::next(it))
                       || !isMax && irrelevant(*std::next(it), *it, *std::prev(it)) );
    }
 
    /*
     * INFO:        Updates 'xValue' of line pointed by iterator 'it'
     * COMPLEXITY:  O(1)
     */
    std::set<Line>::iterator updateLeftBorder(std::set<Line>::iterator it)
    {
        if (isMax && !hasPrev(it) || !isMax && !hasNext(it))
            return it;
 
        double val = intersectX(*it, isMax?*std::prev(it):*std::next(it));
        Line buf(*it);
        it = hull.erase(it);
        buf.xLeft = val;
        it = hull.insert(it, buf);
        return it;
    }
 
public:
    explicit ConvexHullDynamic(bool isMax): isMax(isMax) {}
    
    /*
     * INFO:        Adding line to the envelope
     *              Line is of type 'y=a*x+b' represented by 2 coefficients 'a' and 'b'
     * COMPLEXITY:  Adding N lines(N calls of function) takes O(N*log N) time
     */
    void addLine(coef_t a, coef_t b)
    {
        //find the place where line will be inserted in set
        Line l3 = Line(a, b);
        auto it = hull.lower_bound(l3);
 
        //if parallel line is already in set, one of them becomes irrelevant
        if (it!=hull.end() && areParallel(*it, l3))
        {
            if (isMax && it->b < b || !isMax && it->b > b)
                it = hull.erase(it);
            else
                return;
        }
 
        //try to insert
        it = hull.insert(it, l3);
        if (irrelevant(it)) { hull.erase(it); return; }
 
        //remove lines which became irrelevant after inserting line
        while (hasPrev(it) && irrelevant(std::prev(it))) hull.erase(std::prev(it));
        while (hasNext(it) && irrelevant(std::next(it))) hull.erase(std::next(it));
 
        //refresh 'xLine'
        it = updateLeftBorder(it);
        if (hasPrev(it))
            updateLeftBorder(std::prev(it));
        if (hasNext(it))
            updateLeftBorder(std::next(it));
    }
    /*
     * INFO:        Query, which returns max/min(depends on hull type - see more info above) value in point with abscissa 'x'
     * COMPLEXITY:  O(log N), N-amount of lines in hull
     */
    val_t getBest(coord_t x) const
    {
        Line q;
        q.val = x;
        q.type = isMax ? Line::Type::maxQuery : Line::Type::minQuery;
 
        auto bestLine = hull.lower_bound(q);
        if (isMax) --bestLine;
        return bestLine->valueAt(x);
    }
};
