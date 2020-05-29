=begin

Course Schedule or (this is the topological order problem)

There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
 

Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5

=end


# @param {Integer} num_courses
# @param {Integer[][]} prerequisites
# @return {Boolean}
def get_indegree vertex, two_d, nc
    cnt = 0
    nc.times { |i| cnt += 1 if two_d[i][vertex] == 1 }
    cnt
end

def can_finish(num_courses, prerequisites)
    # this is the topological order problem
    # to store indegree (no of incoming edges to the vertex) of all vertex
    indegree = []
    # to storing vertext for topological order
    queue = Queue.new
    # 2D array create adjacency list for graph & initialize all cells to zero
    two_d = Array.new(num_courses, 0) { Array.new(num_courses, 0) }
    # creating edges b/w vertex based on prerequisites
    prerequisites.each { |pre| two_d[pre[1]][pre[0]] = 1 }
    
    # calculating indegree for all the vertex if indegree is zero pushing it to queue
    (num_courses).times do |i|
        indegree[i] = get_indegree(i, two_d, num_courses)
        queue.push(i) if indegree[i] == 0
    end

    count = 0
    while(!queue.empty? && count < num_courses)
        # deleting vertex from graph (queue) and also removing all the edges from it & updating  
        # indegree again
        front = queue.pop
        # if u want topological order also then push that pop vertex to array etc
        count = count + 1
        (num_courses).times do |i|
            if two_d[front][i] == 1
                two_d[front][i] == 0
                indegree[i] = indegree[i] - 1
                # if anytime again indegree zero then pushing it to queue
                queue.push(i) if indegree[i] == 0
            end      
        end
    end
    
    return true if count == num_courses
    false
end

