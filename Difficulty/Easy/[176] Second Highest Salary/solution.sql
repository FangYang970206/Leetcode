--
-- @lc app=leetcode id=176 lang=mysql
--
-- [176] Second Highest Salary
--

-- @lc code=start
# Write your MySQL query statement below

-- 没有第二高工资则会判错
select salary as SecondHighestSalary
FROM Employee
where Employee.salary != (select salary
						  FROM Employee
                          order by salary
                          LIMIT 1)
order by salary
LIMIT 1;

-- 同样，没有第二高工资则会判错
SELECT DISTINCT
    Salary AS SecondHighestSalary
FROM
    Employee
ORDER BY Salary DESC
LIMIT 1 OFFSET 1

-- 构建临时表来解决空值问题
SELECT
    (SELECT DISTINCT
            Salary
        FROM
            Employee
        ORDER BY Salary DESC
        LIMIT 1 OFFSET 1) AS SecondHighestSalary

-- 使用IFNULL来判断空值
SELECT
    IFNULL(
      (SELECT DISTINCT Salary
       FROM Employee
       ORDER BY Salary DESC
        LIMIT 1 OFFSET 1),
    NULL) AS SecondHighestSalary

-- @lc code=end