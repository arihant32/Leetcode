=begin

Course Schedule II

There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .
Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.

=end


# @param {Integer} num_courses
# @param {Integer[][]} prerequisites
# @return {Integer[]}

def get_indegree(nc, v, adj_list) 
    cnt = 0;
    nc.times { |i| cnt += 1 if adj_list[i][v].eql?(1) }
    cnt
end

def find_order(num_courses, prerequisites)
    result = []
    nc = num_courses
    adj_list = Array.new(nc) {Array.new(nc,0)}
    prerequisites.each { |p| adj_list[p[1]][p[0]] = 1 }
    q = Queue.new
    indegree_arr = []
    nc.times do |v|
        indegree = get_indegree(nc, v, adj_list)
        indegree_arr[v] = indegree
        q.push(v) if indegree.eql?(0)
    end
    while !q.empty?
        v = q.pop
        result.push(v)
        nc.times do |i|
            if adj_list[v][i].eql?(1)
                adj_list[v][i] = 0
                indegree_arr[i] -= 1
                q.push(i) if indegree_arr[i].eql?(0)
            end
        end
    end
    return result.size.eql?(nc) ? result : []
end
