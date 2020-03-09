--
-- @lc app=leetcode id=185 lang=mysql
--
-- [185] Department Top Three Salaries
--

-- @lc code=start
# Write your MySQL query statement below
# Write your MySQL query statement below
SELECT 
    d.Name AS Department, e1.Name AS Employee, e1.Salary AS Salary
FROM
    Employee e1
        JOIN
    Department d ON e1.DepartmentId = d.Id
WHERE
    3 > (SELECT
            COUNT(DISTINCT e2.Salary)
        FROM
            Employee e2
        WHERE e1.DepartmentId = e2.DepartmentId
            AND e2.Salary > e1.Salary)
-- @lc code=end

