--
-- @lc app=leetcode id=181 lang=mysql
--
-- [181] Employees Earning More Than Their Managers
--

-- @lc code=start
# Write your MySQL query statement below
SELECT E1.Name 
AS Employee
FROM Employee E1,
     Employee E2
WHERE E1.ManagerID = E2.Id
      AND E1.salary > E2.salary

-- @lc code=end

