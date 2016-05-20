#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
#include <iomanip>
using namespace std;

class Line
{
    public:
        double c;
        double m;
        double y;
        double x;
        Line(double c, double m):c(c),m(m)
        {
            y = numeric_limits<double>::max();  
            x = numeric_limits<double>::max();
        }

};
double getSlope(pair<double, double> p1, pair<double, double>p2)
{
    double yDiff = p2.second - p1.second;
    double xDiff = p2.first - p1.first;
    if(xDiff == 0)
    {
        return numeric_limits<double>::max(); 
    }
    else
    {
        return (yDiff/xDiff);
    }
}
Line getLine(pair<double, double> p1, pair<double, double> p2)
{
    double c = 0;
    double m = getSlope(p1,p2);
    c = ((double)-1 * m * p1.first) + p1.second;
    Line res = Line(c,m);
    if(m == numeric_limits<double>::max())
    {
        res.x = p1.first;
    }
    if(m == 0)
    {
        res.y = p1.second;
    }
    return res;
}
pair<double, double> getMidPoint(pair<double, double> p1, pair<double, double> p2)
{
    pair<double, double> res;
    res.first = (p2.first + p1.first)/(double)2;
    res.second = (p2.second + p1.second)/(double)2;
    return res;
}
pair<double, double> getIntercept(Line p1, Line p2)
{
    double max = numeric_limits<double>::max();
    pair<double, double> res;
    res.first = (p2.c - p1.c)/(p1.m - p2.m);
    res.second = (p1.m * res.first) + p1.c;
    
    if(p1.x != max && p2.y != max)
    {
        res.first = p1.x;
        res.second = p2.y;
    }
    else if(p2.x != max && p1.y != max)
    {
        res.first = p2.x;
        res.second = p1.y;
    }
    else if(p1.x != numeric_limits<double>::max())
    {
        res.first = p1.x;
        res.second = (p2.m * p1.x) + p2.c;
    }
    else if(p2.x != numeric_limits<double>::max())
    {
        res.first = p2.x;
        res.second = (p1.m * p2.x) + p1.c;
    }
    else if(p1.y != numeric_limits<double>::max())
    {
        res.first = (p1.y - p2.c)/p2.m;
        res.second = p1.y;
    }
    else if(p2.y != numeric_limits<double>::max())
    {
        res.first = (p2.y - p1.c)/p1.m;
        res.second = p2.y;
    }
    return res;
}
Line perpBis(Line l1, pair<double,double> midPoint)
{
    double m = ((double)-1 * pow(l1.m, -1));
    double c = (midPoint.second - (m * midPoint.first));
    Line res =  Line(c,m);
    if(l1.m == numeric_limits<double>::max())
    {
        res.y = midPoint.second;
    }
    if(l1.m == 0)
    {
        res.x = midPoint.first;
    }
    return res;
}
double getDist(pair<double, double>p1, pair<double, double> p2)
{
    return sqrt(pow((p2.first - p1.first),2) + pow((p2.second -
    p1.second),2));
}
int main()
{
    pair<double,double> a, b, c;
    while(cin >> a.first >> a.second >> b.first >> b.second >> c.first >>
        c.second)
    {
        pair <double,double> midAB,midBC;
        Line ab = getLine(a,b);
        Line bc = getLine(b,c);

        midAB = getMidPoint(a,b);
        midBC  = getMidPoint(b,c);

        Line abBis = perpBis(ab, midAB);
        Line bcBis = perpBis(bc, midBC);
        
        pair<double, double> center = getIntercept(abBis, bcBis);
        double radius = getDist(a,center);
        double pi = 3.141592653589793;
        cout << setprecision(2) << fixed << ((double)2 * pi * radius) <<
        endl;

    }
    return 0;
}

