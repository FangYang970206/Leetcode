--
-- @lc app=leetcode id=182 lang=mysql
--
-- [182] Duplicate Emails
--

-- @lc code=start
# Write your MySQL query statement below
SELECT DISTINCT p1.Email AS Email
FROM Person p1, Person p2
WHERE p1.Email = p2.Email
      AND p1.Id <> p2.Id

-- @lc code=end

