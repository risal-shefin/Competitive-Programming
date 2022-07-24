// rotate p by theta degrees CCW w.r.t point c
point rotate(point p, point c, double theta) {
    double rad = DEG_to_RAD(theta); // multiply theta with PI / 180.0
    p.x -= c.x, p.y -= c.y;
    return point(p.x*cos(rad) - p.y*sin(rad) + c.x,
                 p.x*sin(rad) + p.y*cos(rad) + c.y);
}
// in 3D, to rotate a vector v by θ angle around a unit vector k describing the axis/line,
// v_rot=vcosθ+(k×v)sinθ+k(k.v)(1-cosθ) 

/* Line Template Starts */
struct line { double a, b, c; }; // ax + by + c = 0
// the answer is stored in the third parameter (pass by reference)
void pointsToLine(point p1, point p2, line &l) {
    if (fabs(p1.x - p2.x) < EPS) {   // vertical line is fine
        l.a = 1.0, l.b = 0.0, l.c = -p1.x; // default values
    }
    else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0; // IMPORTANT: we fix the value of b to 1.0
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
}
bool areParallel(line l1, line l2) { // check coefficients a & b
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}
bool areSame(line l1, line l2) { // also check coefficient c
    return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS);
}
// returns true (+ intersection point) if two lines are intersect
bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2))
        return false; // no intersection
    // solve system of 2 linear algebraic equations with 2 unknowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    // special case: test for vertical line to avoid division by zero
    if (fabs(l1.b) > EPS)
        p.y = -(l1.a * p.x + l1.c);
    else
        p.y = -(l2.a * p.x + l2.c);
    return true;
}
/* Line Template Ends */

/* Line Segment (Vector) Starts */
struct vec {
    double x, y; // name: ‘vec’ is different from STL vector
    vec(double _x, double _y) : x(_x), y(_y) {}
};
vec toVec(point a, point b) {  // convert 2 points to vector a->b
    return vec(b.x - a.x, b.y - a.y);
}
vec scale(vec v, double s) {  // nonnegative s = [<1 .. 1 .. >1]
    return vec(v.x * s, v.y * s);   // shorter.same.longer
}
point translate(point p, vec v) {  // translate p according to v
    return point(p.x + v.x, p.y + v.y);
}
double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }
double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

// returns the distance from p to the line defined by
// two points a and b (a and b must be different)
// the closest point is stored in the 4th parameter (byref)
double distToLine(point p, point a, point b, point &c) {
    // formula: c = a + u * ab
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u)); // translate a to c
    return dist(p, c);  // Euclidean distance between p and c
}

// returns the distance from p to the line segment ab defined by
// two points a and b (still OK if a == b)
// the closest point is stored in the 4th parameter (byref)
double distToLineSegment(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0) {
        c = point(a.x, a.y); // closer to a
        return dist(p, a); // Euclidean distance between p and a
    }
    if (u > 1.0) {
        c = point(b.x, b.y); // closer to b
        return dist(p, b);  // Euclidean distance between p and a
    }
    return distToLine(p, a, b, c);
}
double angle(point a, point o, point b) {  // returns angle aob in rad
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}
/* Line Segment (Vector) Ends */

/* Circle Template Starts */
int insideCircle(point p, point c, int r) {  // all integer version
    int dx = p.x - c.x, dy = p.y - c.y;
    int Euc = dx * dx + dy * dy, rSq = r * r; // all integer
    return Euc < rSq ? 0 : Euc == rSq ? 1 : 2; //inside/border/outside
}

// Two circles intersecting in two points p1 and p2
bool circle2PtsRad(point p1, point p2, double r, point &c) {
    double d2 = (p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y);
    double det = r * r / d2 - 0.25;
    if (det < 0.0)
        return false;
    double h = sqrt(det);
    c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true;
} // to get the other center, reverse p1 and p2

// Line-Circle Intersection
int getLineCircleIntersection (Point p, Point q, Circle O, double& t1, double& t2, vector<Point>& sol) {
    vec v = q - p;
    //sol.clear();
    double a = v.x, b = p.x - O.o.x, c = v.y, d = p.y - O.o.y;
    double e = a*a+c*c, f = 2*(a*b+c*d), g = b*b+d*d-O.r*O.r;
    double delta = f*f - 4*e*g;
    if (delta < -EPS) return 0;
    if (abs(delta)<=EPS) {
        t1 = t2 = -f / (2 * e);
        sol.push_back(p + v * t1);
        return 1;
    }

    t1 = (-f - sqrt(delta)) / (2 * e); sol.push_back(p + v * t1);
    t2 = (-f + sqrt(delta)) / (2 * e); sol.push_back(p + v * t2);
    return 2;
}

// Circle-Circle Intersection
double getLength (vec a) { return sqrt(dot(a, a)); }
vec ccw(vec a, double co, double si) {return vec(a.x*co-a.y*si, a.y*co+a.x*si);}
vec cw (vec a, double co, double si) {return vec(a.x*co+a.y*si, a.y*co-a.x*si);}
int getCircleCircleIntersection (Circle o1, Circle o2, vector<Point>& sol) {
    double d = getLength(o1.o - o2.o);
    if (abs(d)<=EPS) {
        if (abs(o1.r - o2.r)<=EPS) return -1;
        return 0;
    }
    if ((o1.r + o2.r - d) < -EPS) return 0;
    if ((fabs(o1.r-o2.r) - d) > EPS) return 0;

    vec v = o2.o - o1.o; // obj.o is the center point
    double co = (o1.r*o1.r + getPLength(v) - o2.r*o2.r) / (2 * o1.r * getLength(v));
    double si = sqrt(fabs(1.0 - co*co));
    Point p1 = scale(cw(v,co, si), o1.r) + o1.o;
    Point p2 = scale(ccw(v,co, si), o1.r) + o1.o;

    sol.push_back(p1);
    if (p1 == p2) return 1;
    sol.push_back(p2);
    return 2;
}
/* Circle Template Ends */

/* Triangle Template Starts */
// Radius of Inscribed Circle (incircle) & Circumcircle
double rInCircle(double ab, double bc, double ca) {
    return area(ab, bc, ca) / (0.5 * perimeter(ab, bc, ca));
}
double rCircumCircle(double ab, double bc, double ca) {
    return ab * bc * ca / (4.0 * area(ab, bc, ca));
}

// if this function returns 1, ctr will be the inCircle center
// and r is the same as rInCircle. returns 0 for no incircle.
int inCircle(point p1, point p2, point p3, point &ctr, double &r)
{
    r = rInCircle(dist(p1,p2), dist(p2,p3), dist(p3,p1));
    if (fabs(r) < EPS)
        return 0; // no inCircle center
    line l1, l2; // compute these two angle bisectors
    double ratio = dist(p1, p2) / dist(p1, p3);
    point p = translate(p2, scale(toVec(p2, p3), ratio / (1 + ratio)));
    pointsToLine(p1, p, l1);
    ratio = dist(p2, p1) / dist(p2, p3);
    p = translate(p1, scale(toVec(p1, p3), ratio / (1 + ratio)));
    pointsToLine(p2, p, l2);
    areIntersect(l1, l2, ctr); // get their intersection point
    return 1;
}
bool pointInTriangle(Point a, Point b, Point c, Point p){
     double s1 = getArea(a,b,c);
     double s2 = getArea(p,b,c) + getArea(p,a,b) + getArea(p,c,a);
     return abs(s1-s2)<EPS;
}
/* Triangle Template Ends */
