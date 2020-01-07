--
-- @lc app=leetcode id=175 lang=mysql
--
-- [175] Combine Two Tables
--

-- 官方解答
select FirstName, LastName, City, State
from Person left join Address
on Person.PersonId = Address.PersonId;

-- 我的解答，正在学习mysql;
# Write your MySQL query statement below
SELECT FirstName, 
       LastName,
       (SELECT City
        FROM Address
        WHERE Address.PersonId = Person.PersonId) AS City,
       (SELECT State
        FROM Address
        WHERE Address.PersonId = Person.PersonId) AS State
From Person