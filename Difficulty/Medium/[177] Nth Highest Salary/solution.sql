--
-- @lc app=leetcode id=177 lang=mysql
--
-- [177] Nth Highest Salary
--

-- @lc code=start
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE P1 INT;
  DECLARE P2 INT;
  
  IF (N < 0) 
    THEN SET P1 = 0, P2 = 0;
  ELSE SET P1 = N-1, P2 = 1;
  END IF;

  RETURN (
      # Write your MySQL query statement below.
      SELECT 
        IFNULL (
          (SELECT DISTINCT Salary
           FROM Employee
           ORDER BY Salary DESC
           LIMIT P2 OFFSET P1), NULL
        ) AS NthHighestSalary
  );
END
-- @lc code=end