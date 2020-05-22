=begin
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

=end

# @param {String} s
# @return {String}
def frequency_sort(s)
    # s = "xzaaabbbcccde"
    hh = (0...(s.size)).each_with_object({}) { |i,h| h[s[i]] = (h[s[i]] || 0) + 1 }
    # hh = {"x"=>1, "z"=>1, "a"=>3, "b"=>3, "c"=>3, "d"=>1, "e"=>1} 
    hh_sorted = hh.sort_by { |k, v| v }.reverse
    # hh_sorted = [["c", 3], ["b", 3], ["a", 3], ["e", 1], ["d", 1], ["z", 1], ["x", 1]] 
    new_str = ""
    hh_sorted.each { |arr| new_str << (arr[0]*arr[1]) }
    # new_str = "cccbbbaaaedzx"
    new_str
end
