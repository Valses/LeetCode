//Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.


//并没有通过测试，33 / 34 test cases passed.
//失败案例：[[0,0],[94911151,94911150],[94911152,94911151]]
//似乎是精读问题

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.size() < 3)
            return points.size();
        int maxp = 0;
        
        for(int i = 0; i < points.size(); i++){
            map<double, int> slops;
            double slop;
            int dup = 0;
            int temp = 0;
            for(int j = i + 1; j < points.size(); j++){
                if(points[i].x == points[j].x){
                    if(points[i].y == points[j].y)//重叠点
                        dup++;
                    else{//斜率正无穷的点
                        slop = INT_MAX;
                        slops[slop]++;
                        temp = slops[slop] > temp ? slops[slop] : temp;
                    }
                }
                else{//计算斜率
                    slop = (double)(points[i].y - points[j].y) / (points[i].x - points[j].x);
                    slops[slop]++;
                    temp = slops[slop] > temp ? slops[slop] : temp;
                }
            }
            maxp = maxp > (temp + dup) ? maxp : (temp + dup);//更替当前点为基点的同一直线最大点数（比最大点数少1）
        }
        return maxp + 1;//最终结果要加上基准点
    }
    
};
