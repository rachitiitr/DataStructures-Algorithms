const ll INF = 1LL<<61;
bool cmpA;
struct Line {
   ll a, b;
   mutable long double xl;
   bool operator < (const Line &l) const { if (cmpA) return a < l.a; else return xl < l.xl; }
};
struct DynamicHull : multiset<Line> {
   bool bad (iterator y) {
      iterator z = next(y), x;
      if (y == begin()) {
         if (z == end()) return 0;
         return y->a == z->a && y->b <= z->b;
      }
      x = prev(y);
      if (z == end()) {
         return y->a == x->a && y->b <= x->b;
      }
      return 1.0L * (x->b - y->b) * (z->a - y->a) >= 1.0L * (y->b - z->b) * (y->a - x->a);
   }
 
   void add (ll a, ll b) {
        a*=-1;
        b*=-1;
      cmpA = 1;
      iterator y = insert((Line){a,b,-INF});
      if (bad(y)) { erase(y); return; }
      while (next(y) != end() && bad(next(y))) erase(next(y));
      while (y != begin() && bad(prev(y))) erase(prev(y));
      if (next(y) != end()) next(y)->xl = 1.0L * (y->b - next(y)->b) / (next(y)->a - y->a);
      if (y != begin()) y->xl = 1.0L * (y->b - prev(y)->b) / (prev(y)->a - y->a);
   }
 
   ll eval (ll x) {
      if (empty()) return -(-INF);
      cmpA = 0;
      iterator it = prev(lower_bound((Line){0,0,1.0L*x}));
      return -(it->a * x + it->b);
   }
};
