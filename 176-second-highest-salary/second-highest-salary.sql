# Write your MySQL query statement below

-- USING SIMPLE SELECT STATEMENT

SELECT MAX(salary) as SecondHighestSalary
FROM Employee where salary < (
    SELECT MAX(salary)
    FROM Employee
)