# Write your MySQL query statement below
SELECT e.name 
FROM Employee e
JOIN 
Employee emp
on e.id = emp.managerId
GROUP BY e.id , e.name
Having COUNT(emp.id) >= 5;