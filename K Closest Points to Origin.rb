=begin

K Closest Points to Origin

We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

 

Example 1:

Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation: 
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], K = 2
Output: [[3,3],[-2,4]]
(The answer [[-2,4],[3,3]] would also be accepted.)
 

Note:

1 <= K <= points.length <= 10000
-10000 < points[i][0] < 10000
-10000 < points[i][1] < 10000

=end

# @param {Integer[][]} points
# @param {Integer} k
# @return {Integer[][]}

def k_closest(points, k)
    # Distance b/w two points P(x1,y1) and Q(x2,y2) is given by: d(P, Q) = √ (x2 − x1)2 + (y2 − y1)2       
    # Distance of a point P(x, y) from the origin (0, 0) is given by d(0,P) = √ x2 + y2
    res = Array.new
    hh = Hash.new
    i = 0
    points.each do |p|
        # calculating distance of each given point and storing in hash with key it's index and value is distance
        hh[i] =  p[0]*p[0] + p[1]*p[1]
        i += 1
    end
    # sorting hash by distance
    sorted = hh.sort_by { |k, v| v }
    #taking first k pairs
    sorted.each do |s|
        if k > 0
            index = s[0]
            res.push points[index]
        end
        k -= 1
    end
    res
end
